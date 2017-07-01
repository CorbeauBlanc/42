/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 19:41:43 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/01 17:30:21 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static double			cylinder_intersect(t_ray *ray, t_cylinder *s)
{
	t_dot		res;
	t_vector	*vd;
	t_vector	*vc;
	t_dot		cst;

	vd = &ray->eq.vdir;
	vc = &ray->eq.vconst;
	cst.x = cos(s->theta) * vd->y - sin(s->theta) * vd->x;
	cst.y = cos(s->theta) * (vc->y - s->center.y) - sin(s->theta) * (vc->x - s->center.x);
	cst.z = cos(s->phi) * (sin(s->theta) * vd->y + vd->z) -
			cos(s->theta) * sin(s->phi) * vd->x;
	cst.w = cos(s->phi) * (sin(s->theta) * (vc->y - s->center.y) + (vc->z - s->center.z)) -
			cos(s->theta) * sin(s->phi) * (vc->x - s->center.x);
	if (get_quad_equation_sol(&res, pow(cst.x, 2) + pow(cst.z, 2),
							2 * (cst.x * cst.y + cst.z * cst.w),
							pow(cst.y, 2) + pow(cst.w, 2) - s->r2))
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

static const t_vector	*get_cylinder_normal(t_dot *d, t_cylinder *c)
{
	c->normal = (t_vector){d->x * c->grad.x, d->y * c->grad.y,
				d->z * c->grad.z};
	return (&c->normal);
}

t_cylinder				*new_cylinder(t_dot pos, double x_angle, double z_angle,
									double radius)
{
	t_cylinder	*c;

	c = (t_cylinder*)new_object(CYLINDER, &cylinder_intersect,
								&get_cylinder_normal, sizeof(t_cylinder));
	c->radius = radius;
	c->r2 = pow(radius, 2);
	c->center = pos;
	c->phi = ft_to_rad(x_angle);
	c->theta = ft_to_rad(z_angle - x_angle);
	c->rho = 1;
	c->grad.x = 2 * (pow(sin(c->theta), 2) +
		pow(cos(c->theta), 2) * pow(sin(c->phi), 2) +
		sin(c->theta) * cos(c->theta) * (1 - sin(c->phi) * cos(c->phi)) +
		cos(c->theta) * sin(c->phi) * cos(c->phi));
	c->grad.y = 2 * (pow(cos(c->theta), 2) +
		sin(c->theta) * pow(cos(c->phi), 2) * (1 + sin(c->theta)) +
		sin(c->theta) * cos(c->theta) * (1 - sin(c->phi) * cos(c->phi)));
	c->grad.z = 2 * cos(c->phi) * (cos(c->phi) * (1 + sin(c->theta)) +
		cos(c->theta) * sin(c->phi));
	return (c);
}
