/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_movements2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:34:02 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/18 22:05:18 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void		set_htb_tiles(t_hitbox *htb, t_mob *mob)
{
	htb->xminymin->mob = mob;
	htb->xmaxymin->mob = mob;
	htb->xminymax->mob = mob;
	htb->xmaxymax->mob = mob;
}

static int	move_mob_to_player(double x, double y, t_mob *mob)
{
	t_map		*tmp1;
	t_map		*tmp2;
	t_map		*tmp3;
	t_map		*tmp4;

	tmp1 = goto_tile2(x, y, mob->htb.xminymin);
	tmp2 = goto_tile2(x + mob->spt_north->m_width, y, mob->htb.xmaxymin);
	tmp3 = goto_tile2(x, y + mob->spt_west->m_width, mob->htb.xminymax);
	tmp4 = goto_tile2(x + mob->spt_north->m_width, y + mob->spt_west->m_width,
					mob->htb.xmaxymax);
	if (is_empty(tmp1) && is_empty(tmp2) && is_empty(tmp3) && is_empty(tmp4) &&
		(!tmp1->mob || tmp1->mob == mob) && (!tmp2->mob || tmp2->mob == mob) &&
		(!tmp3->mob || tmp3->mob == mob) && (!tmp4->mob || tmp4->mob == mob))
	{
		set_htb_tiles(&mob->htb, NULL);
		mob->htb.xminymin = tmp1;
		mob->htb.xmaxymin = tmp2;
		mob->htb.xminymax = tmp3;
		mob->htb.xmaxymax = tmp4;
		set_htb_tiles(&mob->htb, mob);
		return (1);
	}
	return (0);
}

void		mob_fluid_move(t_mob *mob)
{
	double		angle;
	t_player	*plr;

	plr = get_player();
	if (plr->pos.x == mob->htb.x)
		angle = plr->pos.y > mob->htb.y ? -90 : 90;
	else
		angle = atan((mob->htb.y - plr->pos.y) / (plr->pos.x - mob->htb.x)) +
				(plr->pos.x > mob->htb.x ? 0 : M_PI);
	mob->view = ft_to_deg(angle);
	mob->watching = 1;
	set_mob_sprites(mob);
	if (move_mob_to_player(mob->htb.x + cos(angle) * MSPEED,
							mob->htb.y - sin(angle) * MSPEED, mob))
		set_mob_htb(mob, mob->htb.x + cos(angle) * MSPEED,
					mob->htb.y - sin(angle) * MSPEED);
	else if (move_mob_to_player(mob->htb.x + cos(angle) * MSPEED, mob->htb.y,
								mob))
		set_mob_htb(mob, mob->htb.x + cos(angle) * MSPEED, mob->htb.y);
	else if (move_mob_to_player(mob->htb.x, mob->htb.y - sin(angle) * MSPEED,
								mob))
		set_mob_htb(mob, mob->htb.x, mob->htb.y - sin(angle) * MSPEED);
}

void		mob_static_move(t_mob *mob)
{
	t_map			*next;

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