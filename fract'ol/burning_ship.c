/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:35:09 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/17 22:00:18 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

double		dabs(double d)
{
	return (d < 0 ? -d : d);
}

int			is_in_burning_ship(double x, double y, int precision)
{
	t_complex	c;
	t_complex	z;
	int			i;

	i = -1;
	set_nbr(&c, x, y);
	set_nbr(&z, 0, 0);
	while (++i < precision && cpx_mod(&z) < 2)
	{
		z.img_part = dabs(z.img_part);
		z.real_part = dabs(z.real_part);
		cpx_add(&z, cpx_mult(&z, &z, &z), &c);
	}
	return (i == precision ? i : -i);
}

t_fractal	*create_burning_ship()
{
	t_fractal	*ftl;

	if ((ftl = new_fractal("burning_ship", &is_in_burning_ship, 250)))
	{
		ftl->x_min = -2.1;
		ftl->x_max = 1.4;
		ftl->y_min = -1.8;
		ftl->y_max = 0.8;
		ftl->precision = 50;
	}
	return (ftl);
}
