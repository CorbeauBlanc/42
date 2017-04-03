/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:02:58 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/03 18:52:18 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_h_mob(t_ray *ray)
{
	if (is_north(ray->a) && ray->h_wall->up->mob &&
		ray->h_i.x >= ray->h_wall->up->mob->x &&
		ray->h_i.x <= (ray->h_wall->up->mob->x + ray->h_wall->up->mob->width) &&
		!ray->h_mob)
	{
		ray->h_mob = ray->h_wall->up->mob;
		ray->h_mob->data.i = ray->h_i;
	}
	else if (is_south(ray->a) && ray->h_wall->down->mob &&
	ray->h_i.x >= ray->h_wall->down->mob->x &&
	ray->h_i.x <= (ray->h_wall->down->mob->x + ray->h_wall->down->mob->width) &&
	!ray->h_mob)
	{
		ray->h_mob = ray->h_wall->down->mob;
		ray->h_mob->data.i = ray->h_i;
	}
}

void	check_v_mob(t_ray *ray)
{
	if (is_east(ray->a) && ray->v_wall->right->mob &&
	ray->v_i.y >= ray->v_wall->right->mob->y &&
	ray->v_i.y <= (ray->v_wall->right->mob->y + ray->v_wall->right->mob->width)
	&& !ray->v_mob)
	{
		ray->v_mob = ray->v_wall->right->mob;
		ray->v_mob->data.i = ray->v_i;
	}
	else if (is_west(ray->a) && ray->v_wall->left->mob &&
	ray->v_i.y >= ray->v_wall->left->mob->y &&
	ray->v_i.y <= (ray->v_wall->left->mob->y + ray->v_wall->left->mob->width)
	&& !ray->v_mob)
	{
		ray->v_mob = ray->v_wall->left->mob;
		ray->v_mob->data.i = ray->v_i;
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
		xt = (int)(mob->data.i.x * mob->spt_front->mapping_fact) % mob->spt_front->w;
	else
		xt = (int)(mob->data.i.y * mob->spt_front->mapping_fact) % mob->spt_front->w;
	set_rect_crd(&srect, xt, 0);
	set_rect_dim(&srect, 1, mob->spt_front->h);
	SDL_SetTextureColorMod(mob->spt_front->text,
							ray->filter, ray->filter, ray->filter);
	SDL_RenderCopy(SDL_GetCore()->renderer, mob->spt_front->text, &srect, &drect);
}
