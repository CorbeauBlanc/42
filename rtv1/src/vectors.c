/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:45:00 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/19 15:30:47 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	*new_vector(double x, double y, double z)
{
	t_vector	*vect;

	if (!(vect = malloc(sizeof(t_dot))))
		return (NULL);
	vect->x = x;
	vect->y = y;
	vect->z = z;
	return (vect);
}

void	set_vector(t_vector *vect, double x, double y, double z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}
