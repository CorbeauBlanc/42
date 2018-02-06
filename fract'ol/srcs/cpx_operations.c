/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpx_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:23:12 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/17 18:30:09 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

t_complex	*cpx_mult(t_complex *res, t_complex *nb1, t_complex *nb2)
{
	double	tmp_r;
	double	tmp_i;

	tmp_i = nb1->real_part * nb2->img_part + nb2->real_part * nb1->img_part;
	tmp_r = nb1->real_part * nb2->real_part - nb1->img_part * nb2->img_part;
	res->img_part = tmp_i;
	res->real_part = tmp_r;
	return (res);
}

t_complex	*cpx_div(t_complex *res, t_complex *nb1, t_complex *nb2)
{
	double	tmp_r;
	double	tmp_i;

	tmp_i = (nb1->img_part * nb2->real_part - nb1->real_part * nb2->img_part) /
			(pow(nb2->real_part, 2) + pow(nb2->img_part, 2));
	tmp_r = (nb1->real_part * nb2->real_part + nb1->img_part * nb2->img_part) /
			(pow(nb2->real_part, 2) + pow(nb2->img_part, 2));
	res->img_part = tmp_i;
	res->real_part = tmp_r;
	return (res);
}

t_complex	*cpx_add(t_complex *res, t_complex *nb1, t_complex *nb2)
{
	double	tmp_r;
	double	tmp_i;

	tmp_i = nb1->img_part + nb2->img_part;
	tmp_r = nb1->real_part + nb2->real_part;
	res->img_part = tmp_i;
	res->real_part = tmp_r;
	return (res);
}

t_complex	*cpx_sub(t_complex *res, t_complex *nb1, t_complex *nb2)
{
	double	tmp_r;
	double	tmp_i;

	tmp_i = nb1->img_part - nb2->img_part;
	tmp_r = nb1->real_part - nb2->real_part;
	res->img_part = tmp_i;
	res->real_part = tmp_r;
	return (res);
}

double		cpx_mod(t_complex *nb)
{
	return (sqrt(pow(nb->real_part, 2) + pow(nb->img_part, 2)));
}
