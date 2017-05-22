/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 22:37:59 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/22 19:10:23 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

int			mob_animation_thread(void *arg)
{
	t_mob			*mob;
	int				ms;
	t_thread_state	state;

	mob = (t_mob*)arg;
	SDL_LockMutex(mob->animation.mutex);
	ms = mob->spt_north->ms;
	state = mob->animation.state;
	SDL_UnlockMutex(mob->animation.mutex);
	while (state != STOP)
	{
		SDL_LockMutex(mob->animation.mutex);
		if (state == RUN)
			change_sprites(mob);
		mob->visible = 0;
		state = mob->animation.state;
		SDL_UnlockMutex(mob->animation.mutex);
		SDL_Delay(ms);
	}
	return (1);
}
