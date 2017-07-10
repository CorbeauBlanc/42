/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 19:41:43 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/10 21:48:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static double			cylinder_intersect(t_ray *ray, t_cylinder *s)
{
	t_dot		res;
	t_vector	*vd;
	t_vector	*vc;
	double		t;

	t = -1;
	vc = &ray->eq_obj.vconst;
	vd = &ray->eq_obj.vdir;
	if (get_quad_equation_sol(&res, pow(vd->x, 2) + pow(vd->z, 2),
							2 * (vd->x * vc->x + vd->z * vc->z),
							pow(vc->x, 2) + pow(vc->z, 2) - s->r2))
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
	return (t);
}

static const t_vector	*get_cylinder_normal(t_dot *d, t_cylinder *c)
{
	(void)c;
	set_vector(&c->normal, 2 * d->x, 0, 2 * d->z);
	return (&c->normal);
}

t_cylinder				*new_cylinder(t_dot pos, double x_angle, double z_angle,
									double radius)
{
	t_cylinder	*c;

	c = (t_cylinder*)new_object(CYLINDER, &cylinder_intersect,
								&get_cylinder_normal, sizeof(t_cylinder));
	translation(&c->trans, pos.x, pos.y, pos.z);
	translation(&c->trans_inv, -pos.x, -pos.y, -pos.z);
	x_rotation(&c->rot, x_angle);
	z_rotation(&c->rot, z_angle);
	get_inv_3x3mat(c->rot_inv, c->rot);
	c->radius = radius;
	c->r2 = pow(radius, 2);
	c->center = pos;
	c->phi = ft_to_rad(x_angle);
	c->theta = ft_to_rad(z_angle);
	c->rho = 1;
	return (c);
}
