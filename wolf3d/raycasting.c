/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:52:35 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/08 17:58:49 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map		*goto_tile(t_vector *x, t_map *tile)
{
	while (tile && (x->x > tile->max.x || x->x < tile->min.x) &&
			(x->y > tile->max.y || x->y < tile->min.y))
	{
		tile = x->x > tile->max.x ? tile->right : tile->left;
		if (tile)
			tile = x->y > tile->max.y ? tile->down : tile->up;
	}
	return (tile);
}
/*
static t_vector	horiz_intersec(int angle, t_player *player)
{
	//angle = cam->angle + cam->half_fov - i
	t_vector	h_i;
	double		xi;
	t_map		*tile;

	h_i.y = angle < 180 ? player->tile->min.y : player->tile->max.y;
	h_i.x = (angle == 90 || angle == 270) ? player->position.x :
			(fabs(player->position.y - h_i.y)) / tan(angle);
	xi = (angle == 90 || angle == 270) ? 0 : fabs(WALL_SIZE / tan(angle));
	while ((h_i.w = fabs((player->position.y - h_i.y) / sin(angle))) <
			player->cam->f)
	{
		if (!(tile = goto_tile(&h_i, player->tile)))
			return (h_i);
		if (angle < 180 && (!tile->up || (tile->up && tile->up->type == WALL)))
			return (h_i);
		else if (angle > 180 &&
				(!tile->down || (tile->down && tile->down->type == WALL)))
			return (h_i);
		h_i.x += (angle < 90 || angle > 270) ? xi : -xi;
		h_i.y += angle < 180 ? -WALL_SIZE : WALL_SIZE;
	}
	return (h_i);
}

static t_vector	vert_intersec(int angle, t_player *player)
{
	//angle = cam->angle + cam->half_fov - i
	t_vector	v_i;
	double		yi;
	t_map		*tile;

	v_i.x = (angle < 90 || angle > 270) ? player->tile->max.x :
			player->tile->min.x;
	v_i.y = (angle == 0 || angle == 180) ? player->position.y :
			(fabs(player->position.x - v_i.x)) * tan(angle);
	yi = (angle == 0 || angle == 180) ? 0 : fabs(WALL_SIZE * tan(angle));
	while ((v_i.w = (fabs(player->position.x - v_i.x) / cos(angle))) <
			player->cam->f)
	{
		if (!(tile = goto_tile(&v_i, player->tile)))
			return (v_i);
		if ((angle < 90 || angle > 270) &&
			(!tile->right || (tile->right && tile->right->type == WALL)))
			return (v_i);
		else if ((angle > 90 || angle < 270) &&
				(!tile->left || (tile->left && tile->left->type == WALL)))
			return (v_i);
		v_i.x += (angle < 90 || angle > 270) ? WALL_SIZE : -WALL_SIZE;
		v_i.y += angle < 180 ? -yi : yi;
	}
	return (v_i);
}
*/
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
	draw_vert_line(player->cam->screen, 350, 200, get_color(255, 0, 0));
	refresh_cam(player->cam);
/*	int	angle;
	int	i;
	t_vector h_i;
	t_vector v_i;

	angle = player->cam->angle + player->cam->half_fov;
	i = -1;
	h_i.w = -1;
	v_i.w = -1;
	while (++i < player->cam->fov)
	{
		if ((angle - i) && (angle - i) != 180)
			h_i = horiz_intersec(angle - i, player);
		if ((angle - i) != 90 && (angle - i) != 270)
			v_i = vert_intersec(angle - i, player);
		if (h_i.w > -1 && h_i.w > v_i.w)*/
			/* Dessiner mur de hauteur (WALL_SIZE / h_i.w) * player->cam->f */
		//else if (v_i.w > -1)
			/* Dessiner mur de hauteur (WALL_SIZE / v_i.w) * player->cam->f */
	//}
}
