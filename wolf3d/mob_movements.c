/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 20:06:31 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/13 22:33:33 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_map	*get_next_tile(t_mob *mob)
{
	if (is_looking_left(mob->view) && is_empty(mob->tile->left) &&
		!mob->tile->left->mob)
		return (mob->tile->left);
	else if (is_looking_right(mob->view) && is_empty(mob->tile->right) &&
			!mob->tile->right->mob)
		return (mob->tile->right);
	else if (is_looking_up(mob->view) && is_empty(mob->tile->up) &&
			!mob->tile->up->mob)
		return (mob->tile->up);
	else if (is_looking_down(mob->view) && is_empty(mob->tile->down) &&
			!mob->tile->down->mob)
		return (mob->tile->down);
	else
		return (NULL);
}

/*
**      Note à soi-même :
** CORRIGER CETTE ABOMINATION !!! (p*** de norme)
**            |
**            V
*/
static void	set_mob_sprites(t_mob *m)
{
	if (is_looking_left(m->view) && (m->spt_north = m->sprites.spt_right))
	{
		m->spt_south = m->sprites.spt_left;
		m->spt_east = m->sprites.spt_front;
		m->spt_west = m->sprites.spt_back;
	}
	else if (is_looking_right(m->view) && (m->spt_north = m->sprites.spt_left))
	{
		m->spt_south = m->sprites.spt_right;
		m->spt_east = m->sprites.spt_back;
		m->spt_west = m->sprites.spt_front;
	}
	else if (is_looking_up(m->view) && (m->spt_north = m->sprites.spt_front))
	{
		m->spt_south = m->sprites.spt_back;
		m->spt_east = m->sprites.spt_left;
		m->spt_west = m->sprites.spt_right;
	}
	else if (is_looking_down(m->view) && (m->spt_north = m->sprites.spt_back))
	{
		m->spt_south = m->sprites.spt_front;
		m->spt_east = m->sprites.spt_right;
		m->spt_west = m->sprites.spt_left;
	}
}

static void	rotate_mob(t_mob *mob)
{
	if (is_empty(mob->tile->up) && !mob->tile->up->mob)
		mob->view = 90;
	else if (is_empty(mob->tile->right) && !mob->tile->right->mob)
		mob->view = 0;
	else if (is_empty(mob->tile->down) && !mob->tile->down->mob)
		mob->view = -90;
	else if (is_empty(mob->tile->left) && !mob->tile->left->mob)
		mob->view = 180;
	set_mob_sprites(mob);
}

void		move_mob(t_mob *mob, int *ms_acc, t_thread_state *state)
{
	t_map	*next;

	next = NULL;
	if (*state != STOP)
	{
		if (!mob->visible && *ms_acc >= 1000)
		{
			*ms_acc = 0;
			if ((next = get_next_tile(mob)))
			{
				mob->tile->mob = NULL;
				next->mob = mob;
				mob->tile = next;
				mob->x = next->min.x + (WALL_SIZE - next->mob->spt_west->m_width) / 2;
				mob->y = next->min.y + (WALL_SIZE - next->mob->spt_north->m_width) / 2;
			}
			else
				rotate_mob(mob);
		}
		//else if (mob->visible)
	}
}
