/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:26:44 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/02 00:16:37 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int			get_color(double z, t_map *map)
{
	double	delta;

	z = dabs(z - map->lowest);
	delta = dabs(map->highest - map->lowest);
	if (z < delta / 6)
		return (0x333333);
	else if (z < 2 * delta / 6)
		return (0x663300);
	else if (z < 3 * delta / 6)
		return (0x006600);
	else if (z < 4 * delta / 6)
		return (0x339900);
	else if (z < 5 * delta / 6)
		return (0x33BB00);
	else
		return (0xDDDDDD);
}

void		mlx_pixel_put_img(t_image *img, int x, int y, int color)
{
	int bytes;

	if (x < img->width && y < img->height && x >= 0 && y >= 0)
	{
		bytes = img->depth / 8;
		*((int*)(img->data + y * img->size_line + x * bytes)) = color;
	}
}

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
