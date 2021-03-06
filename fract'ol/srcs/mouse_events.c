/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:51:23 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/03 22:12:59 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <math.h>

int	mouse_hook(int button, int x, int y, void *param)
{
	t_mouse_evt	*arg;
	int			sign;

	arg = (t_mouse_evt*)param;
	if ((button == M_SCROLL_UP || button == M_L_CLICK) && y > 0)
		sign = 1;
	else if ((button == M_SCROLL_DOWN || button == M_R_CLICK) && y > 0)
		sign = -1;
	else
		return (1);
	arg->ftl->zoom += (sign * 20);
	arg->ftl->x_max += (sign * ((x - arg->img->o_x) / arg->ftl->zoom));
	arg->ftl->x_min += (sign * ((x - arg->img->o_x) / arg->ftl->zoom));
	arg->ftl->y_max += (sign * ((y - arg->img->o_y) / arg->ftl->zoom));
	arg->ftl->y_min += (sign * ((y - arg->img->o_y) / arg->ftl->zoom));
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
