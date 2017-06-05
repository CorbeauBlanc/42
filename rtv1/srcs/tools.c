/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:43:59 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/30 19:41:14 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

int		is_in_window(t_vector *vect)
{
	return (vect && vect->x > 0 && vect->x < WIDTH && vect->y > 0 &&
			vect->y < HEIGHT && vect->z < 0);
}

double	dabs(double f)
{
	return (f < 0 ? -f : f);
}

double	to_rad(double deg)
{
	return (deg * (M_PI / 180.0f));
}

double	max(double d1, double d2)
{
	return (d1 > d2 ? d1 : d2);
}

double	min(double d1, double d2)
{
	return (d1 < d2 ? d1 : d2);
}
