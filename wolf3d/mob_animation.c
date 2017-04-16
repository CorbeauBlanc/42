/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 22:37:59 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/16 17:07:06 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		mob_set_state(t_mob *mob, t_thread_state val)
{
	SDL_LockMutex(mob->spt_mutex);
	mob->state = val;
	SDL_UnlockMutex(mob->spt_mutex);
}

int			mob_get_state(t_mob *mob)
{
	t_thread_state state;

	SDL_LockMutex(mob->spt_mutex);
	state = mob->state;
	SDL_UnlockMutex(mob->spt_mutex);
	return (state);
}

static void	change_sprites(t_mob *mob)
{
	t_sprite	*spt;

	spt = mob->spt_north;
	spt->current.y = (spt->current.y + spt->current.h) % spt->pic->h;
	spt = mob->spt_south;
	spt->current.y = (spt->current.y + spt->current.h) % spt->pic->h;
	spt = mob->spt_east;
	spt->current.y = (spt->current.y + spt->current.h) % spt->pic->h;
	spt = mob->spt_west;
	spt->current.y = (spt->current.y + spt->current.h) % spt->pic->h;
}

int			mob_main_thread(void *arg)
{
	t_mob			*mob;
	int				ms;
	int				ms_acc;
	t_thread_state	state;

	mob = (t_mob*)arg;
	SDL_LockMutex(mob->spt_mutex);
	ms = mob->spt_north->ms;
	state = mob->state;
	SDL_UnlockMutex(mob->spt_mutex);
	ms_acc = 0;
	while (state != STOP)
	{
		SDL_LockMutex(mob->spt_mutex);
		if (state == RUN)
		{
			change_sprites(mob);
			state = mob->state;
		}
		move_mob(mob, &ms_acc, &state);
		mob->visible = 0;
		SDL_UnlockMutex(mob->spt_mutex);
		SDL_Delay(ms);
		ms_acc += ms;
	}
	return (1);
}
