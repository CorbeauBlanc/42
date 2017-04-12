/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 22:37:59 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/12 17:22:29 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		mob_set_visible(t_mob *mob, int val)
{
	SDL_LockMutex(mob->spt_mutex);
	mob->visible = val;
	SDL_UnlockMutex(mob->spt_mutex);
}

int			mob_is_visible(t_mob *mob)
{
	int	v;

	SDL_LockMutex(mob->spt_mutex);
	v = mob->visible;
	SDL_UnlockMutex(mob->spt_mutex);
	return (v);
}

static void	change_sprites(t_mob *mob)
{
	t_sprite	*spt;

	SDL_LockMutex(get_mutexes()->sprites);
	SDL_LockMutex(mob->spt_mutex);
	spt = mob->spt_north;
	spt->current.y = (spt->current.y + spt->current.h) % spt->pic->h;
	spt = mob->spt_south;
	spt->current.y = (spt->current.y + spt->current.h) % spt->pic->h;
	spt = mob->spt_east;
	spt->current.y = (spt->current.y + spt->current.h) % spt->pic->h;
	spt = mob->spt_west;
	spt->current.y = (spt->current.y + spt->current.h) % spt->pic->h;
	SDL_UnlockMutex(mob->spt_mutex);
	scan_environment(get_player());
	SDL_UnlockMutex(get_mutexes()->sprites);
}

int			mob_anim_thread(void *arg)
{
	t_mob		*mob;
	int			visible;
	int			ms;

	mob = (t_mob*)arg;
	SDL_LockMutex(mob->spt_mutex);
	ms = mob->spt_north->ms;
	SDL_UnlockMutex(mob->spt_mutex);
	while ((visible = mob_is_visible(mob)) >= 0)
	{
		if (visible)
			change_sprites(mob);
		SDL_Delay(ms);
	}
	return (1);
}
