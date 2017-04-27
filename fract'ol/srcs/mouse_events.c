/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:51:23 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/27 15:54:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <math.h>

int	mouse_hook(int button, int x, int y, void *param)
{
	t_mouse_evt	*arg;
	int			sn;

	arg = (t_mouse_evt*)param;
	if ((button == M_SCROLL_UP || button == M_L_CLICK) && y > 0)
		sn = 1;
	else if ((button == M_SCROLL_DOWN || button == M_R_CLICK) && y > 0)
		sn = -1;
	else
		return (1);
	arg->ftl->zoom += (sn * 20);
	arg->ftl->x_max += (sn * ((x - arg->img->o_x) / arg->ftl->zoom));
	arg->ftl->x_min += (sn * ((x - arg->img->o_x) / arg->ftl->zoom));
	arg->ftl->y_max += (sn * ((y - arg->img->o_y) / arg->ftl->zoom));
	arg->ftl->y_min += (sn * ((y - arg->img->o_y) / arg->ftl->zoom));
	clear_image(arg->img);
	draw_fractal(arg->img, arg->ftl);
	return (1);
}

int	move_hook(int x, int y, void *param)
{
	t_mouse_evt	*arg;

	arg = (t_mouse_evt*)param;
	if (ft_strequ("julia", arg->ftl->name) && arg->ftl->move)
	{
		arg->ftl->init.real_part = (double)x / (double)arg->img->width;
		arg->ftl->init.img_part = (double)y / (double)arg->img->height;
		draw_fractal(arg->img, arg->ftl);
	}
	return (1);
}
