/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 12:33:37 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/10 18:05:46 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static double			sphere_intersect(t_ray *ray, t_sphere *s)
{
	t_dot		res;
	t_vector	*vd;
	t_vector	*vc;
	double		t;

	t = -1;
	vc = &ray->eq_obj.vconst;
	vd = &ray->eq_obj.vdir;
	/*vc = (t_vector){vc.x - s->center.x, vc.y - s->center.y, vc.z - s->center.z};
	mult_vect(&vd, s->trans_inv, &ray->eq.vdir);
	mult_vect(&vc, s->trans_inv, &vc);*/
	if (get_quad_equation_sol(&res,
			pow(vd->x, 2) + pow(vd->y, 2) + pow(vd->z, 2),
			2 * (vd->x * (vc->x) + vd->y * (vc->y) + vd->z * (vc->z)),
			pow(vc->x, 2) + pow(vc->y, 2) + pow(vc->z, 2) - s->r2))
	{
		if ((long)(res.x * pow(10, 13)) > 0)
		{
			if ((long)(res.y * pow(10, 13)) > 0)
				t = (res.x < res.y ? res.x : res.y);
			else
				t = (res.x);
		} else if ((long)(res.y * pow(10, 13)) > 0)
			t = (res.y);
	}
	/*equation_get_dot(&res, &(t_param_eq){vd, vc}, t);
	mult_vect((t_vector*)&res, s->trans, (t_vector*)&res);
	ray->i.dot = (t_dot){res.x + s->center.x, res.y + s->center.y, res.z + s->center.z, 0};*/
	return (t);
}

static const t_vector	*get_sphere_normal(t_dot *d, t_sphere *s)
{
	s->normal = (t_vector){d->x - s->center.x, d->y - s->center.y,
				d->z - s->center.z};
	return (&s->normal);
}

t_sphere				*new_sphere(double x, double y, double z, double radius)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)new_object(SPHERE, &sphere_intersect,
									&get_sphere_normal, sizeof(t_sphere));
	sphere->radius = radius;
	sphere->r2 = pow(radius, 2);
	set_dot(&sphere->center, x, y, z);
	translation(&sphere->trans, x, y, z);
	translation(&sphere->trans_inv, -x, -y, -z);
	x_rotation(&sphere->rot, 50);
	get_inv_3x3mat(sphere->rot_inv, sphere->rot);
	return (sphere);
}

void					delete_sphere(t_sphere *s)
{
	delete_object((t_object*)s);
}
