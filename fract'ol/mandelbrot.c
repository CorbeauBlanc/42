/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:57:28 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/16 18:09:14 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			is_in_mandelbrot(double x, double y, int precision)
{
	t_complex	c;
	t_complex	z;
	int			i;

	i = -1;
	set_nbr(&c, x, y);
	set_nbr(&z, 0, 0);
	while (++i < precision && cpx_mod(&z) < 2)
		cpx_add(&z, cpx_mult(&z, &z, &z), &c);
	return (i == precision ? i : -i);
}

t_fractal	*create_mandelbrot()
{
	t_fractal	*ftl;

	if ((ftl = new_fractal("mandelbrot", &is_in_mandelbrot, 250)))
	{
		ftl->x_min = -2.1;
		ftl->x_max = 0.6;
		ftl->y_min = -1.2;
		ftl->y_max = 1.2;
		ftl->precision = 50;
	}
	return (ftl);
}
