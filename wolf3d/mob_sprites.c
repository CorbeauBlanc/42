/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:04:55 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/27 23:26:27 by edescoin         ###   ########.fr       */
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
	t_vector	*tmp;

	if (is_looking_left(mob->view))
		set_spt_left(mob);
	else if (is_looking_right(mob->view))
		set_spt_right(mob);
	else if (is_looking_up(mob->view))
		set_spt_up(mob);
	else if (is_looking_down(mob->view))
		set_spt_down(mob);
	set_vect_crd(&tmp, mob->htb.x, mob->htb.y);
	set_equation2(&mob->data.n_spt_equation, &tmp, mob->view);

}
