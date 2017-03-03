/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:52:35 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/03 15:09:51 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


static void	dl_x_loop(t_image *img, t_vector *pt1, t_vector *pt2, double color)
{
	double		e;
	double		dx;
	double		dy;
	t_vector	tmp;
	t_vector	inc;

	dx = dabs(pt2->x - pt1->x);
	dy = dabs(pt2->y - pt1->y);
	e = dx / 2;
	inc.x = (pt1->x < pt2->x) ? 1 : -1;
	inc.y = (pt1->y < pt2->y) ? 1 : -1;
	tmp.x = pt1->x;
	tmp.y = pt1->y;
	tmp.w = pt1->w;
	mlx_pixel_put_img(img, tmp.x, tmp.y, color);
	while ((tmp.x += inc.x) < pt2->x && tmp.x < WIDTH && tmp.y < HEIGHT)
	{
		e += dy;
		mlx_pixel_put_img(img, tmp.x, tmp.y, color);
		if (e >= dx)
		{
			e -= dx;
			tmp.y += inc.y;
		}
	}
}

static void	dl_y_loop(t_image *img, t_vector *pt1, t_vector *pt2, double color)
{
	double		e;
	double		dx;
	double		dy;
	t_vector	tmp;
	t_vector	inc;

	dx = dabs(pt2->x - pt1->x);
	dy = dabs(pt2->y - pt1->y);
	e = dx / 2;
	inc.x = (pt1->x < pt2->x) ? 1 : -1;
	inc.y = (pt1->y < pt2->y) ? 1 : -1;
	tmp.x = pt1->x;
	tmp.y = pt1->y;
	tmp.w = pt1->w;
	mlx_pixel_put_img(img, tmp.x, tmp.y, color);
	while ((tmp.y += inc.y) < pt2->y && tmp.x < WIDTH && tmp.y < HEIGHT)
	{
		e += dx;
		mlx_pixel_put_img(img, tmp.x, tmp.y, color);
		if (e >= dy)
		{
			e -= dy;
			tmp.x += inc.x;
		}
	}
}

void		mlx_draw_line_img(t_image *img, t_vector *pt1, t_vector *pt2,
							t_map *map)
{
	double	dx;
	double	dy;
	int		color;

	dx = dabs(pt2->x - pt1->x);
	dy = dabs(pt2->y - pt1->y);
	color = get_color(max(pt1->w, pt2->w) / SCALE_Z, map);
	if (!dx && !dy)
		mlx_pixel_put_img(img, pt1->x, pt1->y, color);
	else if (dx > dy)
	{
		if (pt1->x < pt2->x)
			dl_x_loop(img, pt1, pt2, color);
		else
			dl_x_loop(img, pt2, pt1, color);
	}
	else
	{
		if (pt1->y < pt2->y)
			dl_y_loop(img, pt1, pt2, color);
		else
			dl_y_loop(img, pt2, pt1, color);
	}
}
