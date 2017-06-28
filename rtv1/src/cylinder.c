/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 19:41:43 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/28 20:44:08 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static double	cylinder_intersect(t_ray *ray, t_cylinder *s)
{
	
}

t_cylinder		*new_cylinder(t_dot pos, double x_angle, double z_angle, double radius)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder*)new_object(SPHERE, &cylinder_intersect, sizeof(t_cylinder));
	cylinder->radius = radius;
	cylinder->center = pos;
	cylinder->phi = x_angle;
	cylinder->theta = z_angle;
	cylinder->rho = 1;
	return (cylinder);
}
