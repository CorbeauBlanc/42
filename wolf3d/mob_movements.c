/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:06:31 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/16 19:51:42 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_map	*get_next_tile(t_mob *m)
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

static void	rotate_mob(t_mob *m)
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

void		set_all_mob_tiles(t_mob *mob, t_map *tile)
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

void		set_mob_htb(t_mob *mob, int x, int y)
{
	mob->htb.x = x;
	mob->htb.y = y;
	mob->htb.xmax = mob->htb.x + mob->spt_north->m_width;
	mob->htb.ymax = mob->htb.y + mob->spt_west->m_width;
}

void		move_mob(t_mob *mob, int *ms_acc, t_thread_state *state)
{
	t_map	*next;

	next = NULL;
	if (*state != STOP)
	{
		if (mob->visible && *ms_acc >= 1000)
		{
			*ms_acc = 0;
			if ((next = get_next_tile(mob)))
			{
				set_all_mob_tiles(mob, next);
				set_mob_htb(mob,
					next->min.x + (WALL_SIZE - mob->spt_west->m_width) / 2,
					next->min.y + (WALL_SIZE - mob->spt_north->m_width) / 2);
			}
			else
				rotate_mob(mob);
		}
		/*else if (mob->visible)
			mob_fluid_move(mob);*/
	}
}
