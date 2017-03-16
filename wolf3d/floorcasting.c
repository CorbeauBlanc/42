/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:06:50 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/16 19:48:05 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cast_floor(t_ray *ray, t_player *player, int i)
{
	t_vector	p_wall;
	t_vector	tmp;
	double		d_orig;
	double		d;
	double		bottom;
	Uint32		color;

	if (ray->h_i.w < ray->v_i.w)
		p_wall = ray->h_i;
	else
		p_wall = ray->v_i;
	p_wall = (t_vector)p_wall;

	bottom = ((SDL_GetCore()->height + ray->h) / 2) - 1;
	d_orig = (WALL_SIZE * player->cam->f) / bottom;
	d_orig = d_orig / cos(ray->a);

	double	weight;
	printf("%.2f\n", ray->v_i.y);
	put_pxl_screen(player->cam->screen, i, bottom, get_color(255, 255, 255));
	while (++bottom < player->cam->screen->height)
	{
		/*d = (WALL_SIZE * player->cam->f) / bottom;
		d = d / cos(ray->a - ft_to_rad(player->cam->angle));*/
		d = player->cam->screen->height / (2 * bottom - player->cam->screen->height);
		d = d / cos(ray->a);
		weight = d / p_wall.w;
		tmp.y = weight * p_wall.y + (1.0 - weight) * player->pos.y;
		tmp.y = (int)(tmp.y * WALL_SIZE) % WALL_SIZE;
		/*tmp.x = weight * p_wall.x + (1.0 - weight) * player->pos.x;
		tmp.x = (int)(tmp.x * WALL_SIZE) % WALL_SIZE;*/
		if (tmp.y < 8)
			color = get_color(0, 0, 255);
		else
			color = get_color(255, 0, 255);
		put_pxl_screen(player->cam->screen, i, bottom, color);
	}
	(void)tmp;
}
