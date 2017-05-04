/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_hitbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:41:14 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/04 23:00:35 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_mob_htb(t_mob *mob)
{
	if (!(mob->htb.upleft = malloc(sizeof(t_vector))) ||
		!(mob->htb.upright = malloc(sizeof(t_vector))) ||
		!(mob->htb.downleft = malloc(sizeof(t_vector))) ||
		!(mob->htb.downright = malloc(sizeof(t_vector))))
		exit_error(NULL);
}
/*
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

void		set_htb_tiles(t_hitbox *htb, t_mob *mob)
{
	htb->xminymin->mob = mob;
	htb->xmaxymin->mob = mob;
	htb->xminymax->mob = mob;
	htb->xmaxymax->mob = mob;
}*/

void	refresh_mob_htb_tiles(t_mob *mob)
{
	if (mob->htb.ul_tile)
		mob->htb.ul_tile->mob = NULL;
	if (mob->htb.ur_tile)
		mob->htb.ur_tile->mob = NULL;
	if (mob->htb.dl_tile)
		mob->htb.dl_tile->mob = NULL;
	if (mob->htb.dr_tile)
		mob->htb.dr_tile->mob = NULL;
	mob->htb.ul_tile = goto_tile(mob->htb.upleft, );
	mob->htb.xminymax = tile;
	mob->htb.xmaxymin = tile;
	mob->htb.xmaxymax = tile;
}

void	set_mob_htb(t_mob *mob, double x, double y)
{
	set_vect_crd(&mob->htb.orig_ul, x, y);
	set_vect_crd(&mob->htb.orig_ur, x + mob->sprites.spt_left->m_width, y);
	set_vect_crd(&mob->htb.orig_dl, x, y + mob->sprites.spt_front->m_width);
	set_vect_crd(&mob->htb.orig_dr, x + mob->sprites.spt_left->m_width,
				y + mob->sprites.spt_front->m_width);
	set_vect_crd(&mob->htb.center, x + mob->sprites.spt_front->m_width / 2,
				y + mob->sprites.spt_left->m_width / 2);

	rotate_vector(mob->htb.upleft, &mob->htb.orig_ul, &mob->htb.center,
				mob->view);
	rotate_vector(mob->htb.upright, &mob->htb.orig_ur, &mob->htb.center,
				mob->view);
	rotate_vector(mob->htb.downleft, &mob->htb.orig_dl, &mob->htb.center,
				mob->view);
	rotate_vector(mob->htb.downright, &mob->htb.orig_dr, &mob->htb.center,
				mob->view);
}
