/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:52:28 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/04 22:20:37 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>
static double	dabs(double f)
{
	return (f < 0 ? -f : f);
}

static void	dl_X_loop(t_vector *pt1, t_vector *pt2, t_mlx_core *core)
{
	double		e;
	double		dx;
	double		dy;
	t_vector	tmp;
	t_vector	inc;

	dx = dabs((double)(pt2->x - pt1->x));
	dy = dabs((double)(pt2->y - pt1->y));
	e = dx / 2;
	inc.x = (pt1->x < pt2->x) ? 1 : -1;
	inc.y = (pt1->y < pt2->y) ? 1 : -1;
	tmp.x = pt1->x;
	tmp.y = pt1->y;
	while ((tmp.x += inc.x) != pt2->x)
	{
		e += dy;
		mlx_pixel_put(core->co, core->win, tmp.x, tmp.y, 0x00FFFFFF);
		if (e >= dx)
		{
			e -= dx;
			tmp.y += inc.y;
		}
	}
}

static void	dl_Y_loop(t_vector *pt1, t_vector *pt2, t_mlx_core *core)
{
	double		e;
	double		dx;
	double		dy;
	t_vector	tmp;
	t_vector	inc;

	dx = dabs((double)(pt2->x - pt1->x));
	dy = dabs((double)(pt2->y - pt1->y));
	e = dx / 2;
	inc.x = (pt1->x < pt2->x) ? 1 : -1;
	inc.y = (pt1->y < pt2->y) ? 1 : -1;
	tmp.x = pt1->x;
	tmp.y = pt1->y;
	while ((tmp.y += inc.y) != pt2->y)
	{
		e += dx;
		mlx_pixel_put(core->co, core->win, tmp.x, tmp.y, 0x00FFFFFF);
		if (e >= dy)
		{
			e -= dy;
			tmp.x += inc.x;
		}
	}
}

void		draw_line(t_vector *pt1, t_vector *pt2, t_mlx_core *core)
{
	double dx;
	double dy;

	dx = dabs((double)(pt2->x - pt1->x));
	dy = dabs((double)(pt2->y - pt1->y));
	if (dx > dy)
		dl_X_loop(pt1, pt2, core);
	else
		dl_Y_loop(pt1, pt2, core);
}

void		draw_polygon(t_vector *p1, t_vector *p2, t_vector *p3, t_vector *p4)
{
	
}
