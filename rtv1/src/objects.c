/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:32:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/23 21:54:28 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_object		*new_object(t_type type, double (*intersect)(), size_t size)
{
	t_object	*obj;

	if (!size)
		size = sizeof(t_object);
	if (!(obj = malloc(size)))
		exit_error("rtv1", "malloc");
	*(t_type*)&obj->obj_type = type;
	obj->intersect = intersect;
	return (obj);
}

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
