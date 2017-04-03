/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_scanning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:49:10 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/03 16:20:53 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "raycasting.h"
#include "bg_casting.h"
#include "mob_casting.h"

void	cast_mobs(t_ray *ray, t_player *player, double correction, int i)
{
	(void)correction;
	if (ray->v_mob && ray->v_mob->data.i.w < ray->d)
	{
		ray->h = (WALL_SIZE * player->cam->f) / (ray->v_mob->data.i.w * cos(correction));
		ray->v_mob->data.h = (ray->v_mob->height * player->cam->f) / (ray->v_mob->data.i.w * cos(correction));
		ray->filter = get_filter_value(player->tile->data, ray->v_mob->data.i.w);
		draw_mob(&player->cam->screen, i, ray, ray->v_mob);
		ray->v_mob = NULL;
	}
	if (ray->h_mob && ray->h_mob->data.i.w < ray->d)
	{
		ray->h = (WALL_SIZE * player->cam->f) / (ray->h_mob->data.i.w * cos(correction));
		ray->h_mob->data.h = (ray->h_mob->height * player->cam->f) / (ray->h_mob->data.i.w * cos(correction));
		ray->filter = get_filter_value(player->tile->data, ray->h_mob->data.i.w);
		draw_mob(&player->cam->screen, i, ray, ray->h_mob);
		ray->h_mob = NULL;
	}
}

void	cast_ray(t_ray *ray, t_player *player, double correction, int i)
{
	if (ray->a && fabs(ray->a) != M_PI)
		horiz_intersec(ray, player);
	if (fabs(ray->a) != M_PI_2 && fabs(ray->a) != (M_PI + M_PI_2))
		vert_intersec(ray, player);
	if (ray->h_i.w < player->cam->f && ray->h_i.w < ray->v_i.w)
	{
		ray->d = ray->h_i.w;
		ray->h = (WALL_SIZE * player->cam->f) / (ray->h_i.w * cos(correction));
		ray->filter = get_filter_value(player->tile->data, ray->h_i.w);
		cast_background(ray, i, player);
		draw_tile(&player->cam->screen, i, ray);
		cast_reflection(ray, i, player);
	}
	else if (ray->v_i.w < player->cam->f)
	{
		ray->d = ray->v_i.w;
		ray->h = (WALL_SIZE * player->cam->f) / (ray->v_i.w * cos(correction));
		ray->filter = get_filter_value(player->tile->data, ray->v_i.w);
		cast_background(ray, i, player);
		draw_tile(&player->cam->screen, i, ray);
		cast_reflection(ray, i, player);
	}
	else
		ray->d = player->cam->f;
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
	ray_l.h_mob = NULL;
	ray_l.v_mob = NULL;
	ray_r.h_mob = NULL;
	ray_r.v_mob = NULL;
	while (++i <= player->cam->half_scr)
	{
		angle = atan((player->cam->half_scr - i) / player->cam->f);
		ray_l.a =  angle + ft_to_rad(player->cam->angle);
		ray_r.a = ft_to_rad(player->cam->angle) - angle;
		cast_ray(&ray_l, player, angle, i);
		cast_ray(&ray_r, player, angle, player->cam->screen.w - i);
		cast_mobs(&ray_l, player, angle, i);
		cast_mobs(&ray_r, player, angle, player->cam->screen.w - i);
	}
	refresh_win();
}
