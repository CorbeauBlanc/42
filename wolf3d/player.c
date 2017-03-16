/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:33:13 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/16 22:35:32 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "floorcasting.h"
#include "wolf3d.h"

t_player	*create_player(t_camera *cam, int x, int y, t_map *map)
{
	t_player	*player;

	if (!(player = malloc(sizeof(t_player))))
		exit_error(NULL);
	player->cam = cam;
	player->pos.x = x;
	player->pos.y = y;
	if (!(player->tile = goto_tile(&player->pos, map)))
	{
		free(player);
		return (NULL);
	}
	return (player);
}

void		delete_player(t_player *player)
{
	delete_camera(player->cam);
	free(player);
}

void			scan_environment(t_player *player)
{
	int			i;
	t_ray		ray;

	i = -1;
	ray.h_i.w = player->cam->f;
	ray.v_i.w = player->cam->f;
	clear_screen(player->cam->screen);
	while (++i <= player->cam->screen->width)
	{
		ray.a = atan((player->cam->half_scr - i) / player->cam->f) +
				ft_to_rad(player->cam->angle);
		if (ray.a && fabs(ray.a) != M_PI)
			horiz_intersec(&ray, player);
		if (fabs(ray.a) != M_PI_2 && fabs(ray.a) != (M_PI + M_PI_2))
			vert_intersec(&ray, player);
		ray.a -= ft_to_rad(player->cam->angle);
		if (ray.h_i.w < player->cam->f && ray.h_i.w < ray.v_i.w)
		{
			ray.h = (WALL_SIZE * player->cam->f) / (ray.h_i.w * cos(ray.a));
			draw_vert_line(player->cam->screen, i, ray.h, get_color(255, 0, 0));
			//cast_floor(&ray, player, i);
		}
		else if (ray.v_i.w < player->cam->f)
		{
			ray.h = (WALL_SIZE * player->cam->f) / (ray.v_i.w * cos(ray.a));
			draw_vert_line(player->cam->screen, i, ray.h, get_color(0, 255, 0));
			//cast_floor(&ray, player, i);
		}
	}
	refresh_cam(player->cam);
}
