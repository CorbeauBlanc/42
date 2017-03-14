/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:06:50 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/14 19:38:55 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cast_floor(t_ray *ray, t_player *player)
{
	t_vector	p_int;
	t_vector	tmp;
	double		d_orig;
	double		d;
	double		bottom;

	if (ray->h_i.w < ray->v_i.w)
		p_int = ray->h_i;
	else
	p_int = ray->v_i;
	p_int.x = (int)p_int.x % WALL_SIZE;
	p_int.y = (int)p_int.y % WALL_SIZE;

	bottom = ((SDL_GetCore()->height + ray->h) / 2);
	d_orig = (WALL_SIZE * player->cam->f) / bottom;
	d_orig = d_orig / cos(ray->a);

	while (++bottom < player->cam->screen->height)
	{
		d = d_orig - (WALL_SIZE * player->cam->f) / bottom;
		tmp.x = (int)(p_int.x + sin(ray->a) * d) % WALL_SIZE;
		tmp.y = (int)(p_int.y + cos(ray->a) * d) % WALL_SIZE;
	}


}
