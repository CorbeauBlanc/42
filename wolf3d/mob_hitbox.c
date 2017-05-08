/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_hitbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:41:14 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/08 18:20:27 by edescoin         ###   ########.fr       */
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

void		set_tiles_mob(t_mob *mob, t_mob *val)
{
	if (mob->htb.ul_tile)
		mob->htb.ul_tile->mob = val;
	if (mob->htb.ur_tile)
		mob->htb.ur_tile->mob = val;
	if (mob->htb.dl_tile)
		mob->htb.dl_tile->mob = val;
	if (mob->htb.dr_tile)
		mob->htb.dr_tile->mob = val;
}

int		refresh_mob_htb_tiles(t_mob *mob, t_simple_htb *htb)
{
	set_tiles_mob(mob, NULL);
	mob->htb.ul_tile = goto_tile(&htb->ul, mob->htb.ul_tile);
	mob->htb.ur_tile = goto_tile(&htb->ur, mob->htb.ur_tile);
	mob->htb.dl_tile = goto_tile(&htb->dl, mob->htb.dl_tile);
	mob->htb.dr_tile = goto_tile(&htb->dr, mob->htb.dr_tile);
	if (!is_empty(mob->htb.ul_tile) || !is_empty(mob->htb.ur_tile) ||
		!is_empty(mob->htb.dl_tile) || !is_empty(mob->htb.dr_tile))
		return (0);
	set_tiles_mob(mob, mob);
	return (1);
}

void	set_mob_htb(t_mob *mob, double x, double y)
{
	t_simple_htb	tmp;

	set_vect_crd(&mob->htb.orig.ul, x, y);
	set_vect_crd(&mob->htb.orig.ur, x + mob->sprites.spt_left->m_width, y);
	set_vect_crd(&mob->htb.orig.dl, x, y + mob->sprites.spt_front->m_width);
	set_vect_crd(&mob->htb.orig.dr, x + mob->sprites.spt_left->m_width,
				y + mob->sprites.spt_front->m_width);
	set_vect_crd(&mob->htb.center, x + mob->sprites.spt_front->m_width / 2,
				y + mob->sprites.spt_left->m_width / 2);

	rotate_vector(&tmp.ul, &mob->htb.orig.ul, &mob->htb.center, mob->view);
	rotate_vector(&tmp.ur, &mob->htb.orig.ur, &mob->htb.center, mob->view);
	rotate_vector(&tmp.dl, &mob->htb.orig.dl, &mob->htb.center, mob->view);
	rotate_vector(&tmp.dr, &mob->htb.orig.dr, &mob->htb.center, mob->view);
	if (refresh_mob_htb_tiles(mob, &tmp))
		mob->htb.rot = tmp;
	else
		refresh_mob_htb_tiles(mob, &mob->htb.rot);

	if (is_north(ft_to_rad(mob->view)))
		
}
