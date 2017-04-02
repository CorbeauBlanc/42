/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:02:58 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/31 19:35:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_h_mob(t_ray *ray)
{
	if (is_north(ray->a) && ray->h_wall->up->mob && !ray->h_mob)
	{
		ray->h_mob = ray->h_wall->up->mob;
		ray->h_mob->data.i = ray->h_i;
	}
	else if (is_south(ray->a) && ray->h_wall->down->mob && !ray->h_mob)
	{
		ray->h_mob = ray->h_wall->down->mob;
		ray->h_mob->data.i = ray->h_i;
	}
}

void	check_v_mob(t_ray *ray)
{
	if (is_east(ray->a) && ray->v_wall->right->mob && !ray->v_mob)
	{
		ray->v_mob = ray->v_wall->right->mob;
		ray->v_mob->data.i = ray->v_i;
	}
	else if (is_west(ray->a) && ray->v_wall->left->mob && !ray->v_mob)
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

	set_rect_crd(&drect, i, (scr->h - ray->h) / 2 - 1);
	set_rect_dim(&drect, 1, ray->h);
	if (mob == ray->h_mob)
		xt = (int)(mob->data.i.x) % mob->width;
	else
		xt = (int)(mob->data.i.y) % mob->width;
	set_rect_crd(&srect, xt, 0);
	set_rect_dim(&srect, 1, mob->height);
	SDL_SetTextureColorMod(mob->spt_front,
							ray->filter, ray->filter, ray->filter);
	SDL_RenderCopy(SDL_GetCore()->renderer, mob->spt_front, &srect, &drect);
}
