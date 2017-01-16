/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:52:28 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/16 20:29:17 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

t_mlx_core	*get_mlx_core(void)
{
	static t_mlx_core	*core = NULL;

	if (!core)
	{
		if (!(core = malloc(sizeof(t_mlx_core))))
			return (NULL);
		if (!(core->co = mlx_init()))
			return (NULL);
		core->win = mlx_new_window(core->co, 500, 500, "TEST");
	}
	return (core);
}

static void	dl_x_loop(t_vector *pt1, t_vector *pt2, t_mlx_core *core)
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
	mlx_pixel_put(core->co, core->win, tmp.x, tmp.y, 0x00FFFFFF);
	while ((tmp.x += inc.x) < pt2->x && tmp.x < WIDTH && tmp.y < HEIGHT)
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

static void	dl_y_loop(t_vector *pt1, t_vector *pt2, t_mlx_core *core)
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
	mlx_pixel_put(core->co, core->win, tmp.x, tmp.y, 0x00FFFFFF);
	while ((tmp.y += inc.y) < pt2->y && tmp.x < WIDTH && tmp.y < HEIGHT)
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

void		mlx_draw_line(t_vector *pt1, t_vector *pt2)
{
	double dx;
	double dy;
	t_mlx_core	*core;

	core = get_mlx_core();
	dx = dabs((double)(pt2->x - pt1->x));
	dy = dabs((double)(pt2->y - pt1->y));
	if (dx > dy)
	{
		if (pt1->x < pt2->x)
			dl_x_loop(pt1, pt2, core);
		else
			dl_x_loop(pt2, pt1, core);
	}
	else
	{
		if (pt1->y < pt2->y)
			dl_y_loop(pt1, pt2, core);
		else
			dl_y_loop(pt2, pt1, core);
	}
}

void		mlx_draw_quadrangle(t_vector *pt1, t_vector *pt2,
								t_vector *pt3, t_vector *pt4)
{
	mlx_draw_line(pt1, pt2);
	mlx_draw_line(pt2, pt3);
	mlx_draw_line(pt3, pt4);
	mlx_draw_line(pt4, pt1);
}
