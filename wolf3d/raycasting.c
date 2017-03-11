/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:52:35 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/11 17:27:17 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_vector	horiz_intersec(double angle, t_player *player)
{
	t_vector	h_i;
	double		xi;
	t_map		*tile;

	h_i.y = angle < M_PI && angle > 0 ? player->tile->min.y : player->tile->max.y;
	h_i.x = player->position.x + (fabs(angle) == M_PI_2 ? 0 :
			fabs((player->position.y - h_i.y) / tan(angle)));
	xi = (fabs(angle) == M_PI_2) ? 0 : fabs(WALL_SIZE / tan(angle));
	while ((h_i.w = fabs((player->position.y - h_i.y) / sin(angle))) <
			player->cam->f)
	{
		if (!(tile = goto_tile(&h_i, player->tile)))
			return (h_i);
		if (angle < M_PI && angle > 0 && (!tile->up || (tile->up && tile->up->type == WALL)))
		{
			return (h_i);
		}
		else if (angle < 0 &&
				(!tile->down || (tile->down && tile->down->type == WALL)))
		{
			return (h_i);
		}
		h_i.x += (fabs(angle) < M_PI_2) ? xi : -xi;
		h_i.y += (angle < M_PI && angle > 0) ? -WALL_SIZE : WALL_SIZE;
	}
	return (h_i);
}

static t_vector	vert_intersec(double angle, t_player *player)
{
	t_vector	v_i;
	double		yi;
	t_map		*tile;

	v_i.x = (fabs(angle) < M_PI_2) ? player->tile->max.x : player->tile->min.x;
	v_i.y = player->position.y + (!angle || angle == M_PI ? 0 :
			fabs((player->position.x - v_i.x) * tan(angle)));
	yi = (!angle || angle == M_PI) ? 0 : fabs(WALL_SIZE * tan(angle));
	while ((v_i.w = fabs((player->position.x - v_i.x) / cos(angle))) <
			player->cam->f)
	{
		if (!(tile = goto_tile(&v_i, player->tile)))
			return (v_i);
		if (fabs(angle) < M_PI_2 &&
			(!tile->right || (tile->right && tile->right->type == WALL)))
		{
			return (v_i);
		}
		else if (fabs(angle) > M_PI_2 &&
				(!tile->left || (tile->left && tile->left->type == WALL)))
		{
			return (v_i);
		}
		v_i.x += (fabs(angle) < M_PI_2) ? WALL_SIZE : -WALL_SIZE;
		v_i.y += (angle < M_PI && angle > 0) ? -yi : yi;
	}
	return (v_i);
}

static void		draw_vert_line(t_screen *scr, int x, double h, Uint32 color)
{
	int	y;

	if (h < SDL_GetCore()->height)
	{
		y = (SDL_GetCore()->height - h) / 2 - 1;
		h += y;
		while (++y < h)
			put_pxl_screen(scr, x, y, color);
	}
}

void			scan_environment(t_player *player)
{
	double		angle;
	int			i;
	t_vector	h_i;
	t_vector	v_i;

	i = -1;
	h_i.w = -1;
	v_i.w = -1;
	while (++i <= player->cam->screen->width)
	{
		angle = atan((player->cam->half_scr - i) / player->cam->f) +
				ft_to_rad(player->cam->angle);
		if (angle && angle != M_PI)
			h_i = horiz_intersec(angle, player);
		if (fabs(angle) != M_PI_2)
			v_i = vert_intersec(angle, player);
		angle -= ft_to_rad(player->cam->angle);
		printf("%.2f - %.2f\n", h_i.w, v_i.w);
		if (h_i.w > -1 && h_i.w < v_i.w)
			draw_vert_line(player->cam->screen, i, (WALL_SIZE * player->cam->f) / (h_i.w * cos(angle)),
												get_color(255, 0, 0));
			/* Dessiner mur de hauteur (WALL_SIZE / h_i.w) * player->cam->f */
		else if (v_i.w > -1)
			draw_vert_line(player->cam->screen, i, (WALL_SIZE * player->cam->f) / (v_i.w * cos(angle)),
													get_color(0, 255, 0));
			/* Dessiner mur de hauteur (WALL_SIZE / v_i.w) * player->cam->f */
	}
	refresh_cam(player->cam);
}
