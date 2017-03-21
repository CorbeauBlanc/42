/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:52:35 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/17 17:39:14 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_ray	*set_wall(t_ray *ray, t_map *wall)
{
	ray->wall = wall;
	return (ray);
}

t_ray			*horiz_intersec(t_ray *ray, t_player *player)
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
		if (!(ray->wall = goto_tile(&ray->h_i, player->tile)))
			return (ray);
		if (is_north(ray->a) && !is_empty(ray->wall->up))
			return (set_wall(ray, ray->wall->up));
		else if (is_south(ray->a) && !is_empty(ray->wall->down))
			return (set_wall(ray, ray->wall->down));
		ray->h_i.x += is_east(ray->a) ? xi : -xi;
		ray->h_i.y += is_north(ray->a) ? -WALL_SIZE : WALL_SIZE;
	}
	return (set_wall(ray, NULL));
}

t_ray			*vert_intersec(t_ray *ray, t_player *player)
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
		if (!(ray->wall = goto_tile(&ray->v_i, player->tile)))
			return (ray);
		if (is_east(ray->a) && !is_empty(ray->wall->right))
			return (set_wall(ray, ray->wall->right));
		else if (is_west(ray->a) && !is_empty(ray->wall->left))
			return (set_wall(ray, ray->wall->left));
		ray->v_i.x += is_east(ray->a) ? WALL_SIZE : -WALL_SIZE;
		ray->v_i.y += is_north(ray->a) ? -yi : yi;
	}
	return (set_wall(ray, NULL));
}

void			draw_vert_line(t_screen *scr, int x, double h, Uint32 color)
{
	int	y;

	if (h > SDL_GetCore()->height)
		h = SDL_GetCore()->height;
	y = (SDL_GetCore()->height - h) / 2 - 1;
	h += y;
	while (++y < h)
		put_pxl_screen(scr, x, y, color);
}
