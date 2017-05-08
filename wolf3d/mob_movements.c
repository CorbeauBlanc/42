/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:06:31 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/08 17:54:26 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map	*get_next_tile(t_mob *m)
{
	if (is_looking_left(m->view) &&
		is_empty(m->htb.ul_tile->left) && !m->htb.ul_tile->left->mob &&
		is_empty(m->htb.dl_tile->left) && !m->htb.dl_tile->left->mob)
		return (m->htb.ul_tile->left);
	else if (is_looking_right(m->view) &&
			is_empty(m->htb.ur_tile->right) && !m->htb.ur_tile->right->mob &&
			is_empty(m->htb.dr_tile->right) && !m->htb.dr_tile->right->mob)
		return (m->htb.ul_tile->right);
	else if (is_looking_up(m->view) &&
			is_empty(m->htb.ul_tile->up) && !m->htb.ul_tile->up->mob &&
			is_empty(m->htb.ur_tile->up) && !m->htb.ur_tile->up->mob)
		return (m->htb.ul_tile->up);
	else if (is_looking_down(m->view) &&
			is_empty(m->htb.dl_tile->down) && !m->htb.dl_tile->down->mob &&
			is_empty(m->htb.dr_tile->down) && !m->htb.dr_tile->down->mob)
		return (m->htb.ul_tile->down);
	else
		return (NULL);
}

void	rotate_mob(t_mob *m)
{
	if (is_empty(m->htb.ul_tile) && !m->htb.ul_tile->mob &&
		is_empty(m->htb.ur_tile) && !m->htb.ur_tile->mob)
		m->view = 90;
	else if (is_empty(m->htb.ur_tile->right) && !m->htb.ur_tile->right->mob &&
			is_empty(m->htb.dr_tile->right) && !m->htb.dr_tile->right->mob)
		m->view = 0;
	else if (is_empty(m->htb.dl_tile->down) && !m->htb.dl_tile->down->mob &&
			is_empty(m->htb.dr_tile->down) && !m->htb.dr_tile->down->mob)
		m->view = -90;
	else if (is_empty(m->htb.ul_tile->left) && !m->htb.ul_tile->left->mob &&
			is_empty(m->htb.dl_tile->left) && !m->htb.dl_tile->left->mob)
		m->view = 180;
	set_mob_sprites(m);
}

int		mob_movement_thread(void *arg)
{
	t_mob			*mob;
	t_thread_state	state;
	int				ms;

	mob = (t_mob*)arg;
	ms = 0;
	state = get_thread_state(&mob->movement);
	while (state != STOP)
	{
		SDL_LockMutex(get_mutexes()->mob_mvt);
		SDL_LockMutex(mob->movement.mutex);
		if (mob->visible && state == RUN)
			mob_fluid_move(mob);
		else if (state == RUN && (ms += EVT_DELAY) >= 1000)
		{
			ms = 0;
			mob_static_move(mob);
		}
		state = mob->movement.state;
		mob->data.h = -1;
		mob->data.y = -1;
		SDL_UnlockMutex(mob->movement.mutex);
		SDL_UnlockMutex(get_mutexes()->mob_mvt);
		SDL_Delay(EVT_DELAY);
	}
	return (1);
}
