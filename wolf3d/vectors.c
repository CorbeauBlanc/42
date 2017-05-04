/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:38:45 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/04 22:30:12 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

t_vector	*create_vector(double x, double y)
{
	t_vector	*vect;

	if (!(vect = malloc(sizeof(t_vector))))
		return (NULL);
	vect->x = x;
	vect->y = y;
	vect->z = 0;
	vect->w = 0;
	return (vect);
}

void		rotate_vector(t_vector *dst, t_vector *vect, t_vector *ctr, int a)
{
	double cos_a;
	double sin_a;

	cos_a = cos(ft_to_rad(a));
	sin_a = sin(ft_to_rad(a));
	set_vect_crd(dst, (vect->x - ctr->x) * cos_a - (vect->y - ctr->y) * sin_a,
				(vect->x - ctr->x) * sin_a + (vect->y - ctr->y) * cos_a);
}
