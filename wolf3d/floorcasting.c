/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:06:50 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/15 20:45:17 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cast_floor(t_ray *ray, t_player *player, int i)
{
	t_vector	p_int;
	t_vector	tmp;
	double		d_orig;
	double		d;
	double		bottom;
	Uint32		color;

	if (ray->h_i.w < ray->v_i.w)
		p_int = ray->h_i;
	else
		p_int = ray->v_i;
	/*p_int.x = (int)p_int.x % WALL_SIZE;
	p_int.y = (int)p_int.y % WALL_SIZE;*/

	bottom = ((SDL_GetCore()->height + ray->h) / 2) - 1;
	d_orig = (WALL_SIZE * player->cam->f) / bottom;
	d_orig = d_orig / cos(ray->a);

	ray->a += ft_to_rad(player->cam->angle);

	put_pxl_screen(player->cam->screen, i, bottom, get_color(255, 255, 255));
	double	weight;
	while (++bottom < player->cam->screen->height)
	{
		d = player->cam->screen->height / (2.0 * bottom - player->cam->screen->height);
		/*d = (WALL_SIZE * player->cam->f) / bottom;*/
		d = d / cos(ray->a - ft_to_rad(player->cam->angle));
		weight = d / d_orig;
		tmp.y = weight * p_int.y + (1.0 - weight) * player->pos.y;
		tmp.y = (int)(tmp.y * WALL_SIZE) % WALL_SIZE;
		if (tmp.y < 8)
			color = get_color(0, 0, 255);
		else
			color = get_color(255, 0, 255);
		put_pxl_screen(player->cam->screen, i, bottom, color);
	}
	(void)tmp;
}
