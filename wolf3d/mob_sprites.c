/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:04:55 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/07 19:28:51 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	set_spt_left(t_mob *mob)
{
	mob->spt_north = mob->sprites.spt_right;
	mob->spt_south = mob->sprites.spt_left;
	mob->spt_east = mob->sprites.spt_front;
	mob->spt_west = mob->sprites.spt_back;
}

static void	set_spt_right(t_mob *mob)
{
	mob->spt_north = mob->sprites.spt_left;
	mob->spt_south = mob->sprites.spt_right;
	mob->spt_east = mob->sprites.spt_back;
	mob->spt_west = mob->sprites.spt_front;
}

static void	set_spt_up(t_mob *mob)
{
	mob->spt_north = mob->sprites.spt_front;
	mob->spt_south = mob->sprites.spt_back;
	mob->spt_east = mob->sprites.spt_left;
	mob->spt_west = mob->sprites.spt_right;
}

static void	set_spt_down(t_mob *mob)
{
	mob->spt_north = mob->sprites.spt_back;
	mob->spt_south = mob->sprites.spt_front;
	mob->spt_east = mob->sprites.spt_right;
	mob->spt_west = mob->sprites.spt_left;
}

void		set_mob_sprites(t_mob *mob)
{
	if (is_looking_left(mob->view))
		set_spt_left(mob);
	else if (is_looking_right(mob->view))
		set_spt_right(mob);
	else if (is_looking_up(mob->view))
		set_spt_up(mob);
	else if (is_looking_down(mob->view))
		set_spt_down(mob);
	set_equation(&mob->data.n_spt_equation, mob->htb.upleft,
											mob->htb.upright);
	set_equation(&mob->data.s_spt_equation, mob->htb.downleft,
											mob->htb.downright);
	set_equation(&mob->data.w_spt_equation, mob->htb.upleft,
											mob->htb.downleft);
	set_equation(&mob->data.e_spt_equation, mob->htb.upright,
											mob->htb.downright);
}
