/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_scanning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:49:10 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/28 01:28:04 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "raycasting.h"
#include "floorcasting.h"

void	cast_ray(t_ray *ray, t_player *player, double correction, int i)
{
	if (ray->a && fabs(ray->a) != M_PI)
		horiz_intersec(ray, player);
	if (fabs(ray->a) != M_PI_2 && fabs(ray->a) != (M_PI + M_PI_2))
		vert_intersec(ray, player);
	if (ray->h_i.w < player->cam->f && ray->h_i.w < ray->v_i.w)
	{
		ray->h = (WALL_SIZE * player->cam->f) / (ray->h_i.w * cos(correction));
		//cast_floor(ray, player, i);
		//refresh_cam(player->cam);
		draw_vert_line(player->cam->screen, i, ray->h, ray);
	}
	else if (ray->v_i.w < player->cam->f)
	{
		ray->h = (WALL_SIZE * player->cam->f) / (ray->v_i.w * cos(correction));
		//cast_floor(ray, player, i);
		//refresh_cam(player->cam);
		draw_vert_line(player->cam->screen, i, ray->h, ray);
	}
}

void	scan_environment(t_player *player)
{
	int			i;
	double		angle;
	t_ray		ray_l;
	t_ray		ray_r;

	i = -1;
	ray_l.h_i.w = player->cam->f;
	ray_l.v_i.w = player->cam->f;
	ray_r.h_i.w = player->cam->f;
	ray_r.v_i.w = player->cam->f;
	clear_screen(player->cam->screen);
	while (++i <= player->cam->half_scr)
	{
		angle = atan((player->cam->half_scr - i) / player->cam->f);
		ray_l.a =  angle + ft_to_rad(player->cam->angle);
		ray_r.a = ft_to_rad(player->cam->angle) - angle;
		cast_ray(&ray_l, player, angle, i);
		cast_ray(&ray_r, player, angle, player->cam->screen->width - i);
	}
	refresh_win();
}
