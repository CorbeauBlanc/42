/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpx_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:07:10 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/08 15:32:29 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_nbr(t_complex *nb, double r, double i)
{
	nb->img_part = i;
	nb->real_part = r;
}

t_complex	*new_cpx(double r, double i)
{
	t_complex	*nb;

	if (!(nb = malloc(sizeof(t_complex))))
		return (NULL);
	nb->img_part = i;
	nb->real_part = r;
	return (nb);
}
