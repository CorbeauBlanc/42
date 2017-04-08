/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:02:58 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/08 15:06:22 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_h_mob(t_ray *ray, t_player *player)
{
	if (is_north(ray->a) && ray->h_wall->up && ray->h_wall->up->mob)
	{
		ray->h_wall->up->mob->data.i.y = ray->h_wall->up->mob->y + ray->h_wall->up->mob->spt_west->m_width;
		ray->h_wall->up->mob->data.i.x = ray->h_i.x;
		if (fabs(ray->a) != M_PI_2 && fabs(ray->a) != (M_PI + M_PI_2))
			ray->h_wall->up->mob->data.i.x += (ray->h_wall->up->max.y - ray->h_wall->up->mob->data.i.y) / tan(ray->a);
		if (ray->h_wall->up->mob->data.i.x >= ray->h_wall->up->mob->x &&
			ray->h_wall->up->mob->data.i.x <= (ray->h_wall->up->mob->x + ray->h_wall->up->mob->spt_south->m_width))
		{
			ray->h_wall->up->mob->data.next = ray->h_mob;
			ray->h_mob = ray->h_wall->up->mob;
			ray->h_mob->data.i.w = fabs((player->pos.y - ray->h_mob->data.i.y) / sin(ray->a));
		}
	}
	else if (ray->h_wall->down && is_south(ray->a) && ray->h_wall->down->mob)
	{
		ray->h_wall->down->mob->data.i.y = ray->h_wall->down->mob->y;
		ray->h_wall->down->mob->data.i.x = ray->h_i.x;
		if (fabs(ray->a) != M_PI_2 && fabs(ray->a) != (M_PI + M_PI_2))
			ray->h_wall->down->mob->data.i.x -= (ray->h_wall->down->mob->data.i.y - ray->h_wall->down->min.y) / tan(ray->a);
		if (ray->h_wall->down->mob->data.i.x >= ray->h_wall->down->mob->x &&
			ray->h_wall->down->mob->data.i.x <= (ray->h_wall->down->mob->x + ray->h_wall->down->mob->spt_north->m_width))
		{
			ray->h_wall->down->mob->data.next = ray->h_mob;
			ray->h_mob = ray->h_wall->down->mob;
			ray->h_mob->data.i.w = fabs((player->pos.y - ray->h_mob->data.i.y) / sin(ray->a));
		}
	}
}

void	check_v_mob(t_ray *ray, t_player *player)
{
	if (ray->v_wall->right && is_east(ray->a) && ray->v_wall->right->mob)
	{
		ray->v_wall->right->mob->data.i.x = ray->v_wall->right->mob->x;
		ray->v_wall->right->mob->data.i.y = ray->v_i.y;
		if (ray->a && fabs(ray->a) != M_PI)
			ray->v_wall->right->mob->data.i.y -= (ray->v_wall->right->mob->data.i.x - ray->v_wall->right->min.x) * tan(ray->a);
		if (ray->v_wall->right->mob->data.i.y >= ray->v_wall->right->mob->y &&
			ray->v_wall->right->mob->data.i.y <= (ray->v_wall->right->mob->y + ray->v_wall->right->mob->spt_west->m_width))
		{
			ray->v_wall->right->mob->data.next = ray->v_mob;
			ray->v_mob = ray->v_wall->right->mob;
			ray->v_mob->data.i.w = fabs((ray->v_mob->data.i.x - player->pos.x) / cos(ray->a));
		}
	}
	else if (ray->v_wall->left && is_west(ray->a) && ray->v_wall->left->mob)
	{
		ray->v_wall->left->mob->data.i.x = ray->v_wall->left->mob->x + ray->v_wall->left->mob->spt_south->m_width;
		ray->v_wall->left->mob->data.i.y = ray->v_i.y;
		if (ray->a && fabs(ray->a) != M_PI)
			ray->v_wall->left->mob->data.i.y += (ray->v_wall->left->max.x - ray->v_wall->left->mob->data.i.x) * tan(ray->a);
		if (ray->v_wall->left->mob->data.i.y >= ray->v_wall->left->mob->y &&
			ray->v_wall->left->mob->data.i.y <= (ray->v_wall->left->mob->y + ray->v_wall->left->mob->spt_east->m_width))
		{
			ray->v_wall->left->mob->data.next = ray->v_mob;
			ray->v_mob = ray->v_wall->left->mob;
			ray->v_mob->data.i.w = fabs((ray->v_mob->data.i.x - player->pos.x) / cos(ray->a));
		}
	}
}

void	draw_mob(SDL_Rect *scr, int i, t_ray *ray, t_mob *mob)
{
	int			xt;
	SDL_Rect	srect;
	SDL_Rect	drect;

	set_rect_crd(&drect, i, ((scr->h + ray->h) / 2) - mob->data.h);
	set_rect_dim(&drect, 1, mob->data.h);
	if (mob == ray->h_mob)
		xt = (int)((mob->data.i.x - mob->x) * mob->spt_north->mapping_fact) % mob->spt_north->current.w;
	else
		xt = (int)((mob->data.i.y - mob->y) * mob->spt_north->mapping_fact) % mob->spt_north->current.w;
	set_rect_crd(&srect, xt, mob->spt_north->current.y);
	set_rect_dim(&srect, 1, mob->spt_north->current.h);
	SDL_SetTextureColorMod(mob->spt_north->pic->text,
							ray->filter, ray->filter, ray->filter);
	SDL_RenderCopy(SDL_GetCore()->renderer, mob->spt_north->pic->text, &srect, &drect);
}
