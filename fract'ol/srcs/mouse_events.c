/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 17:51:23 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/17 15:36:39 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int	mouse_hook(int button, int x, int y, void *param)
{
	t_mouse_evt	*arg;
	int			sign;

	arg = (t_mouse_evt*)param;
	if ((button == M_SCROLL_UP || button == M_L_CLICK) && y > 0)
		sign = 1;
	else if ((button == M_SCROLL_DOWN || button == M_R_CLICK) && y > 0 &&
			arg->ftl->precision - 10 > 0)
		sign = -1;
	else
		return (1);
	arg->ftl->zoom += (sign * 50);
	arg->ftl->precision += (sign * 10);
	arg->ftl->x_max += (sign * (x - (arg->img->width / 2)) / arg->ftl->zoom);
	arg->ftl->x_min += (sign * (x - (arg->img->width / 2)) / arg->ftl->zoom);
	arg->ftl->y_max += (sign * (y - (arg->img->height / 2)) / arg->ftl->zoom);
	arg->ftl->y_min += (sign * (y - (arg->img->height / 2)) / arg->ftl->zoom);
	clear_image(arg->img);
	draw_fractal(arg->img, arg->ftl);
	return (1);
}

int	move_hook(int x, int y, void *param)
{
	t_mouse_evt	*arg;

	arg = (t_mouse_evt*)param;
	if (ft_strequ("julia", arg->ftl->name))
	{
		arg->ftl->init.real_part = (double)x / (double)arg->img->width;
		arg->ftl->init.img_part = (double)y / (double)arg->img->height;
		draw_fractal(arg->img, arg->ftl);
	}
	return (1);
}
