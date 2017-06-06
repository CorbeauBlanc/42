/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:52:35 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/23 21:58:07 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_ray	*horiz_intersec(t_ray *ray, t_player *player)
{
	double		xi;

	ray->h_i.y = is_north(ray->a) ? player->tile->min.y : player->tile->max.y;
	ray->h_i.x = player->pos.x;
	xi = 0;
	if (fabs(ray->a) != M_PI_2 && fabs(ray->a) != (M_PI + M_PI_2))
	{
		ray->h_i.x += (player->pos.y - ray->h_i.y) / tan(ray->a);
		xi = fabs(WALL_SIZE / tan(ray->a));
	}
	while ((ray->h_i.w = fabs((player->pos.y - ray->h_i.y) / sin(ray->a))) <
			player->cam->f)
	{
		if (!(ray->h_wall = goto_tile(&ray->h_i, player->tile)))
			return (ray);
		if (is_north(ray->a) && !is_empty(ray->h_wall = ray->h_wall->up))
			return (ray);
		else if (is_south(ray->a) && !is_empty(ray->h_wall = ray->h_wall->down))
			return (ray);
		ray->h_i.x += is_east(ray->a) ? xi : -xi;
		ray->h_i.y += is_north(ray->a) ? -WALL_SIZE : WALL_SIZE;
	}
	return (set_wall(ray, &ray->h_wall, NULL));
}

t_ray	*vert_intersec(t_ray *ray, t_player *player)
{
	double		yi;

	ray->v_i.x = is_east(ray->a) ? player->tile->max.x : player->tile->min.x;
	ray->v_i.y = player->pos.y;
	yi = 0;
	if (ray->a && fabs(ray->a) != M_PI)
	{
		ray->v_i.y += (player->pos.x - ray->v_i.x) * tan(ray->a);
		yi = fabs(WALL_SIZE * tan(ray->a));
	}
	while ((ray->v_i.w = fabs((ray->v_i.x - player->pos.x) / cos(ray->a))) <
			player->cam->f)
	{
		if (!(ray->v_wall = goto_tile(&ray->v_i, player->tile)))
			return (ray);
		if (is_east(ray->a) && !is_empty(ray->v_wall = ray->v_wall->right))
			return (ray);
		else if (is_west(ray->a) && !is_empty(ray->v_wall = ray->v_wall->left))
			return (ray);
		ray->v_i.x += is_east(ray->a) ? WALL_SIZE : -WALL_SIZE;
		ray->v_i.y += is_north(ray->a) ? -yi : yi;
	}
	return (set_wall(ray, &ray->v_wall, NULL));
}

int		draw_tile(t_player *plr, int i, t_ray *ray)
{
	int			xt;
	SDL_Rect	srect;
	SDL_Rect	drect;
	t_map		*wall;

	set_rect_crd(&drect, i, plr->cam->half_scr - ray->h / 2 - 1);
	set_rect_dim(&drect, 1, ray->h);
	if (ray->h_i.w < ray->v_i.w && (wall = ray->h_wall))
		xt = (int)(ray->h_i.x * wall->textures[ray->side]->mapping_fact) %
			wall->textures[ray->side]->w;
	else if ((wall = ray->v_wall))
		xt = (int)(ray->v_i.y * wall->textures[ray->side]->mapping_fact) %
			wall->textures[ray->side]->w;
	else
		return (1);
	set_rect_crd(&srect, xt, 0);
	set_rect_dim(&srect, 1, wall->textures[ray->side]->h);
	SDL_SetTextureColorMod(wall->textures[ray->side]->text,
							ray->filter, ray->filter, ray->filter);
	SDL_RenderCopy(get_sdl_core()->renderer, wall->textures[ray->side]->text,
					&srect, &drect);
	return (0);
}
