/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 12:33:37 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/28 20:06:58 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static double	sphere_intersect(t_ray *ray, t_sphere *s)
{
	t_dot		res;
	t_vector	*vd;
	t_vector	*vc;

	vd = &ray->eq.vdir;
	vc = &ray->eq.vconst;
	if (get_quad_equation_sol(&res,
			pow(vd->x, 2) + pow(vd->y, 2) + pow(vd->z, 2),
			2 * (vd->x * (vc->x - s->center.x) + vd->y * (vc->y - s->center.y) + vd->z * (vc->z - s->center.z)),
			pow(vc->x - s->center.x, 2) + pow(vc->y - s->center.y, 2) + pow(vc->z - s->center.z, 2) - s->r2))
	{
		if ((long)(res.x * pow(10, 13)) > 0)
		{
			if ((long)(res.y * pow(10, 13)) > 0)
				return (res.x < res.y ? res.x : res.y);
			return (res.x);
		}
		if ((long)(res.y * pow(10, 13)) > 0)
			return (res.y);
	}
	return (-1);
}

t_sphere		*new_sphere(double x, double y, double z, double radius)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)new_object(SPHERE, &sphere_intersect, sizeof(t_sphere));
	sphere->radius = radius;
	sphere->r2 = pow(radius, 2);
	set_dot(&sphere->center, x, y, z);
	return (sphere);
}
