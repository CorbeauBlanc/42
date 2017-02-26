/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:11:41 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/26 19:49:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** P = cosh(z) - 1
*/
int			is_in_newton_2(double x, double y, int precision)
{
	t_complex	z;
	t_complex	z2;
	t_complex	z3;
	int			i;

	i = -1;
	set_nbr(&z, x, y);
	while (++i < precision && cpx_mod(&z) < 2)
	{
		cpx_sub(&z3, cpx_mult(&z2, &z, cpx_sinh(&z2, &z)), cpx_cosh(&z3, &z));
		++z3.real_part;
		cpx_div(&z, &z3, cpx_sinh(&z2, &z));
	}
	return (i == precision ? i : -i);
}

t_fractal	*create_newton_2()
{
	t_fractal	*ftl;


	if ((ftl = new_fractal("newton_2", &is_in_newton_2, 250)))
	{
		ftl->x_min = -1;
		ftl->x_max = 1;
		ftl->y_min = -1;
		ftl->y_max = 1;
		ftl->precision = 50;
		ftl->init.img_part = 0.01;
		ftl->init.real_part = 0.285;
	}
	return (ftl);
}
