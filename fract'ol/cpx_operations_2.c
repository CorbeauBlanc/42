/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpx_operations_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:23:12 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/17 21:52:28 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

t_complex	*cpx_real_mult(t_complex *res, t_complex *nb1, double nb2)
{
	double	tmp_r;
	double	tmp_i;

	tmp_i = nb1->img_part * nb2;
	tmp_r = nb1->real_part * nb2;
	res->img_part = tmp_i;
	res->real_part = tmp_r;
	return (res);
}

t_complex	*cpx_real_div(t_complex *res, t_complex *nb1, double nb2)
{
	double	tmp_r;
	double	tmp_i;

	tmp_i = nb1->img_part / nb2;
	tmp_r = nb1->real_part / nb2;
	res->img_part = tmp_i;
	res->real_part = tmp_r;
	return (res);
}
