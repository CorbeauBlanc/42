/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:57:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/16 20:16:03 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			is_in_julia(double x, double y, int precision, t_complex *init)
{
	t_complex	c;
	t_complex	z;
	int			i;

	i = -1;
	set_nbr(&c, init->real_part, init->img_part);
	set_nbr(&z, x, y);
	while (++i < precision && cpx_mod(&z) < 2)
		cpx_add(&z, cpx_mult(&z, &z, &z), &c);
	return (i);
}

t_fractal	*create_julia()
{
	t_fractal	*ftl;


	if ((ftl = new_fractal("julia", &is_in_julia, 250)))
	{
		ftl->x_min = -1.2;
		ftl->x_max = 1.2;
		ftl->y_min = -1.2;
		ftl->y_max = 1.2;
		ftl->precision = 50;
		ftl->init.img_part = 0.01;
		ftl->init.real_part = 0.285;
	}
	return (ftl);
}
