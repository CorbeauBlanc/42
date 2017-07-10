/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:54:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/05 17:17:40 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_dot	*new_dot(double x, double y, double z)
{
	t_dot	*dot;

	dot = (t_dot*)new_vector(x, y, z);
	dot->w = 1;
	return (dot);
}

void	set_dot(t_dot *dot, double x, double y, double z)
{
	dot->x = x;
	dot->y = y;
	dot->z = z;
}

double	get_dot_dist(t_dot *d1, t_dot *d2)
{
	return (sqrt(pow(d2->x - d1->x, 2) + pow(d2->y - d1->y, 2) +
				pow(d2->z - d1->z, 2)));
}
