/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_scanning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:49:10 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/23 21:55:32 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "raycasting.h"
#include "bg_casting.h"

static void	draw_h_inter(t_ray *ray, t_player *player, double correction, int i)
{
	ray->side = get_horiz_side(ray->a);
	ray->d = ray->h_i.w;
	ray->h = (WALL_SIZE * player->cam->f) / (ray->h_i.w * cos(correction));
	ray->filter = get_filter_value(player->tile->data, ray->h_i.w);
	if (player->tile->data->bgd)
		cast_background(ray, i, player);
	draw_tile(player, i, ray);
	if (player->tile->data->reflection)
		cast_reflection(ray, i, player);
}

static void	draw_v_inter(t_ray *ray, t_player *player, double correction, int i)
{
	ray->side = get_vert_side(ray->a);
	ray->d = ray->v_i.w;
	ray->h = (WALL_SIZE * player->cam->f) / (ray->v_i.w * cos(correction));
	ray->filter = get_filter_value(player->tile->data, ray->v_i.w);
	if (player->tile->data->bgd)
		cast_background(ray, i, player);
	draw_tile(player, i, ray);
	if (player->tile->data->reflection)
		cast_reflection(ray, i, player);
}

static void	cast_ray(t_ray *ray, t_player *player, double correction, int i)
{
	if (ray->a && fabs(ray->a) != M_PI)
		horiz_intersec(ray, player);
	if (fabs(ray->a) != M_PI_2 && fabs(ray->a) != (M_PI + M_PI_2))
		vert_intersec(ray, player);
	if (ray->h_i.w < player->cam->f && ray->h_i.w < ray->v_i.w)
		draw_h_inter(ray, player, correction, i);
	else if (ray->v_i.w < player->cam->f)
		draw_v_inter(ray, player, correction, i);
	else
		ray->d = player->cam->f;
}

void		scan_environment(t_player *player)
{
	int			i;
	double		angle;
	t_ray		ray;
	double		half_scr;

	i = -1;
	ray.h_i.w = player->cam->f;
	ray.v_i.w = player->cam->f;
	half_scr = SDL_GetCore()->height / 2;
	if (player->tile->data->floor.a)
		cast_floor_ceiling(player);
	while (++i <= player->cam->screen.w)
	{
		angle = atan((half_scr - i) / player->cam->f);
		ray.a =  angle + ft_to_rad(player->cam->angle);
		SDL_LockMutex(get_mutexes()->mob_mvt);
		cast_ray(&ray, player, angle, i);
		SDL_UnlockMutex(get_mutexes()->mob_mvt);
	}
	refresh_win();
}
