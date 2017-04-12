/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:02:58 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/12 22:45:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_h_mob(t_ray *ray, t_map *wall, t_vector *its, t_player *player)
{
	if (wall && wall->mob && is_north(ray->a) && its->y >= (wall->mob->y + wall->mob->spt_west->m_width))
	{
		wall->mob->data.i.y = wall->mob->y + wall->mob->spt_west->m_width;
		wall->mob->data.i.x = its->x;
		if (fabs(ray->a) != M_PI_2 && fabs(ray->a) != (M_PI + M_PI_2))
			wall->mob->data.i.x += (its->y - wall->mob->data.i.y) / tan(ray->a);
		if (wall->mob->data.i.x >= wall->mob->x &&
			wall->mob->data.i.x <= (wall->mob->x + wall->mob->spt_south->m_width))
		{
			wall->mob->data.next = ray->h_mob;
			ray->h_mob = wall->mob;
			ray->h_mob->data.i.w = fabs((player->pos.y - ray->h_mob->data.i.y) / sin(ray->a));
		}
	}
	else if (wall && wall->mob && is_south(ray->a) && its->y <= wall->mob->y)
	{
		wall->mob->data.i.y = wall->mob->y;
		wall->mob->data.i.x = its->x;
		if (fabs(ray->a) != M_PI_2 && fabs(ray->a) != (M_PI + M_PI_2))
			wall->mob->data.i.x -= (wall->mob->data.i.y - its->y) / tan(ray->a);
		if (wall->mob->data.i.x >= wall->mob->x &&
			wall->mob->data.i.x <= (wall->mob->x + wall->mob->spt_north->m_width))
		{
			wall->mob->data.next = ray->h_mob;
			ray->h_mob = wall->mob;
			ray->h_mob->data.i.w = fabs((player->pos.y - ray->h_mob->data.i.y) / sin(ray->a));
		}
	}
}

void	check_v_mob(t_ray *ray, t_map *wall, t_vector *its, t_player *player)
{
	if (wall && wall->mob && is_east(ray->a) && its->x <= wall->mob->x)
	{
		wall->mob->data.i.x = wall->mob->x;
		wall->mob->data.i.y = its->y;
		if (ray->a && fabs(ray->a) != M_PI)
			wall->mob->data.i.y -= (wall->mob->data.i.x - its->x) * tan(ray->a);
		if (wall->mob->data.i.y >= wall->mob->y &&
			wall->mob->data.i.y <= (wall->mob->y + wall->mob->spt_west->m_width))
		{
			wall->mob->data.next = ray->v_mob;
			ray->v_mob = wall->mob;
			ray->v_mob->data.i.w = fabs((ray->v_mob->data.i.x - player->pos.x) / cos(ray->a));
		}
	}
	else if (wall && wall->mob && is_west(ray->a) && its->x >= (wall->mob->x + wall->mob->spt_south->m_width))
	{
		wall->mob->data.i.x = wall->mob->x + wall->mob->spt_south->m_width;
		wall->mob->data.i.y = its->y;
		if (ray->a && fabs(ray->a) != M_PI)
			wall->mob->data.i.y += (its->x - wall->mob->data.i.x) * tan(ray->a);
		if (wall->mob->data.i.y >= wall->mob->y &&
			wall->mob->data.i.y <= (wall->mob->y + wall->mob->spt_east->m_width))
		{
			wall->mob->data.next = ray->v_mob;
			ray->v_mob = wall->mob;
			ray->v_mob->data.i.w = fabs((ray->v_mob->data.i.x - player->pos.x) / cos(ray->a));
		}
	}
}

void	draw_mob(SDL_Rect *scr, int i, t_ray *ray, t_mob *mob)
{
	int			xt;
	SDL_Rect	srect;
	SDL_Rect	drect;
	t_sprite	*spt;

	set_rect_crd(&drect, i, ((scr->h + ray->h) / 2) - mob->data.h);
	set_rect_dim(&drect, 1, mob->data.h);
	if (mob == ray->h_mob)
	{
		xt = (int)((mob->data.i.x - mob->x) * mob->spt_north->mapping_fact) % mob->spt_north->current.w;
		if (is_south(ray->a))
			spt = mob->spt_north;
		else
			spt = mob->spt_south;
	}
	else
	{
		xt = (int)((mob->data.i.y - mob->y) * mob->spt_north->mapping_fact) % mob->spt_north->current.w;
		if (is_east(ray->a))
			spt = mob->spt_west;
		else
			spt = mob->spt_east;
	}
	set_rect_crd(&srect, xt, spt->current.y);
	set_rect_dim(&srect, 1, spt->current.h);
	SDL_SetTextureColorMod(spt->pic->text, ray->filter, ray->filter, ray->filter);
	SDL_RenderCopy(SDL_GetCore()->renderer, spt->pic->text, &srect, &drect);
}
