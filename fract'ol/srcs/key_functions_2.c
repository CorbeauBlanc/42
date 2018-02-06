/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:17:20 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/03 21:57:45 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	increase_precision(t_mouse_evt *arg)
{
	++arg->ftl->precision;
	draw_fractal(arg->img, arg->ftl);
}

void	decrease_precision(t_mouse_evt *arg)
{
	if (arg->ftl->precision > 1)
		--arg->ftl->precision;
	draw_fractal(arg->img, arg->ftl);
}

void	toggle_julia(t_mouse_evt *arg)
{
	arg->ftl->move = !(arg->ftl->move);
}
