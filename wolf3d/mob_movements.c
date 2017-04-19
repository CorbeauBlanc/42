/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:06:31 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/18 22:16:18 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map	*get_next_tile(t_mob *m)
{
	if (is_looking_left(m->view) && is_empty(m->htb.xminymin->left) &&
		(!m->htb.xminymin->left->mob || m->htb.xminymin->left->mob == m))
		return (m->htb.xminymin->left);
	else if (is_looking_right(m->view) && is_empty(m->htb.xminymin->right) &&
			(!m->htb.xminymin->right->mob || m->htb.xminymin->right->mob == m))
		return (m->htb.xminymin->right);
	else if (is_looking_up(m->view) && is_empty(m->htb.xminymin->up) &&
			(!m->htb.xminymin->up->mob || m->htb.xminymin->up->mob == m))
		return (m->htb.xminymin->up);
	else if (is_looking_down(m->view) && is_empty(m->htb.xminymin->down) &&
			(!m->htb.xminymin->down->mob || m->htb.xminymin->down->mob == m))
		return (m->htb.xminymin->down);
	else
		return (NULL);
}

void	rotate_mob(t_mob *m)
{
	if (is_empty(m->htb.xminymin->up) && !m->htb.xminymin->up->mob)
		m->view = 90;
	else if (is_empty(m->htb.xminymin->right) && !m->htb.xminymin->right->mob)
		m->view = 0;
	else if (is_empty(m->htb.xminymin->down) && !m->htb.xminymin->down->mob)
		m->view = -90;
	else if (is_empty(m->htb.xminymin->left) && !m->htb.xminymin->left->mob)
		m->view = 180;
	set_mob_sprites(m);
}

void	set_all_mob_tiles(t_mob *mob, t_map *tile)
{
	if (tile)
	{
		if (mob->htb.xminymin)
			mob->htb.xminymin->mob = NULL;
		if (mob->htb.xminymax)
			mob->htb.xminymax->mob = NULL;
		if (mob->htb.xmaxymin)
			mob->htb.xmaxymin->mob = NULL;
		if (mob->htb.xmaxymax)
			mob->htb.xmaxymax->mob = NULL;
		mob->htb.xminymin = tile;
		mob->htb.xminymax = tile;
		mob->htb.xmaxymin = tile;
		mob->htb.xmaxymax = tile;
		mob->htb.xminymin->mob = mob;
	}
}

void	set_mob_htb(t_mob *mob, double x, double y)
{
	mob->htb.x = x;
	mob->htb.y = y;
	mob->htb.xmax = mob->htb.x + mob->spt_north->m_width;
	mob->htb.ymax = mob->htb.y + mob->spt_west->m_width;
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
