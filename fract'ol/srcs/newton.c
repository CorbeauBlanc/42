/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:11:41 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/26 17:25:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** P = z³ - 1
*/
int			is_in_newton(double x, double y, int precision)
{
	t_complex	z;
	t_complex	z2;
	t_complex	z3;
	int			i;

	i = -1;
	set_nbr(&z, x, y);
	while (++i < precision && cpx_mod(&z) < 2)
	{
		cpx_mult(&z2, &z, &z);
		cpx_mult(&z3, &z2, &z);
		cpx_real_mult(&z3, &z3, 2);
		++z3.real_part;
		cpx_real_mult(&z2, &z2, 3);
		cpx_div(&z, &z3, &z2);
	}
	return (i == precision ? i : -i);
}

t_fractal	*create_newton()
{
	t_fractal	*ftl;


	if ((ftl = new_fractal("newton", &is_in_newton, 250)))
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
