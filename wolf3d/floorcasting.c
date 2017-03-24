/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:06:50 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/24 16:14:02 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cast_floor(t_ray *ray, t_player *player, int i)
{
	t_vector	p_wall;
	t_vector	tmp;
	double		d;
	double		bottom;
	double		cos_a;
	double		weight;
	Uint32		color = 0;

	if (ray->h_i.w < ray->v_i.w)
		p_wall = ray->h_i;
	else
		p_wall = ray->v_i;

	bottom = ((SDL_GetCore()->height + ray->h) / 2);
	ray->a -= ft_to_rad(player->cam->angle);

	cos_a = cos(ray->a);

	while (++bottom < player->cam->screen->height)
	{
		d = (WALL_SIZE * player->cam->f) / (bottom - player->cam->half_scr);
		d = d / cos_a;
		weight = d / p_wall.w;
		tmp.y = weight * p_wall.y + (2.0 - weight) * player->pos.y;
		tmp.y = (int)((tmp.y) / 2) % WALL_SIZE;
		tmp.x = weight * p_wall.x + (2.0 - weight) * player->pos.x;
		tmp.x = (int)((tmp.x - WALL_SIZE) / 2) % WALL_SIZE;
		if (tmp.x < 8 && tmp.y < 8)
			color = get_color(90, 90, 255);
		else if (tmp.x >= 8 && tmp.y >= 8)
			color = get_color(255, 90, 255);
		else if (tmp.x >= 8 && tmp.y < 8)
			color = get_color(255, 255, 90);
		else if (tmp.x < 8 && tmp.y >= 8)
			color = get_color(90, 255, 255);
		put_pxl_screen(player->cam->screen, i, bottom - 2, color);
		put_pxl_screen(player->cam->screen, i, player->cam->screen->height - bottom, color);
	}
	(void)tmp;
}
