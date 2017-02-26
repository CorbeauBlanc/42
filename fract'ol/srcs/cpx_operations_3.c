/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpx_operations_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:45:29 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/26 19:39:38 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>

t_complex	*cpx_cos(t_complex *res, t_complex *nb)
{
	double	img;
	double	real;

	real = cos(nb->real_part) * cosh(nb->img_part);
	img = -sin(nb->real_part) * sinh(nb->img_part);
	set_nbr(res, real, img);
	return (res);
}

t_complex	*cpx_cosh(t_complex *res, t_complex *nb)
{
	double	img;
	double	real;

	real = cosh(nb->real_part) * cos(nb->img_part);
	img = sinh(nb->real_part) * sin(nb->img_part);
	set_nbr(res, real, img);
	return (res);
}

t_complex	*cpx_sinh(t_complex *res, t_complex *nb)
{
	double	img;
	double	real;

	real = sinh(nb->real_part) * cos(nb->img_part);
	img = cosh(nb->real_part) * sin(nb->img_part);
	set_nbr(res, real, img);
	return (res);
}
