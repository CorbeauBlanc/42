/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:26:44 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/30 19:25:12 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int			get_color(t_vector *pt1, t_vector *pt2, double delta)
{
	double	z;

	z = pt1->w / SCALE_Z;
	if (pt1->w < pt2->w)
		pt1->w += SCALE_Z;
	else if (pt1->w > pt2->w)
		pt1->w -= SCALE_Z;
	if (z < 0)
	{
		if (z > -delta / 3)
			return (0x006600);
		else if (z > -2 * delta / 3)
			return (0x663300);
		else
			return (0x333333);
	}
	else
	{
		if (z < delta / 3)
			return (0x339900);
		else if (z < 2 * delta / 3)
			return (0x33BB00);
		else
			return (0xDDDDDD);
	}
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

static void	dl_x_loop(t_image *img, t_vector *pt1, t_vector *pt2, double delta)
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
	mlx_pixel_put_img(img, tmp.x, tmp.y, get_color(&tmp, pt2, delta));
	while ((tmp.x += inc.x) < pt2->x && tmp.x < WIDTH && tmp.y < HEIGHT)
	{
		e += dy;
		mlx_pixel_put_img(img, tmp.x, tmp.y, get_color(&tmp, pt2, delta));
		if (e >= dx)
		{
			e -= dx;
			tmp.y += inc.y;
		}
	}
}

static void	dl_y_loop(t_image *img, t_vector *pt1, t_vector *pt2, double delta)
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
	mlx_pixel_put_img(img, tmp.x, tmp.y, get_color(&tmp, pt2, delta));
	while ((tmp.y += inc.y) < pt2->y && tmp.x < WIDTH && tmp.y < HEIGHT)
	{
		e += dx;
		mlx_pixel_put_img(img, tmp.x, tmp.y, get_color(&tmp, pt2, delta));
		if (e >= dy)
		{
			e -= dy;
			tmp.x += inc.x;
		}
	}
}

void		mlx_draw_line_img(t_image *img, t_vector *pt1, t_vector *pt2,
							double delta)
{
	double dx;
	double dy;

	dx = dabs(pt2->x - pt1->x);
	dy = dabs(pt2->y - pt1->y);
	if (!dx && !dy)
		mlx_pixel_put_img(img, pt1->x, pt1->y, get_color(pt1, pt2, delta));
	else if (dx > dy)
	{
		if (pt1->x < pt2->x)
			dl_x_loop(img, pt1, pt2, delta);
		else
			dl_x_loop(img, pt2, pt1, delta);
	}
	else
	{
		if (pt1->y < pt2->y)
			dl_y_loop(img, pt1, pt2, delta);
		else
			dl_y_loop(img, pt2, pt1, delta);
	}
}
