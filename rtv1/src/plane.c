/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 12:35:04 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/28 17:59:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static double	plane_intersect(t_ray *ray, t_plane *p)
{
	double	t;
	double	denom;
	t_vector	*vd;
	t_vector	*vc;

	vd = &ray->eq.vdir;
	vc = &ray->eq.vconst;
	denom = (p->a * vd->x + p->b * vd->y + p->c * vd->z);
	if (!denom)
		return (-1);
	t = -((p->a * vc->x + p->b * vc->y + p->c * vc->z + p->d) / denom);
	if ((long)(t * pow(10, 13)) > 0/*t > p->z*/)
		return (t);
	return (-1);
}

t_plane			*new_plane(t_dot pos, double x_angle, double z_angle)
{
	t_plane		*plane;
	t_dot		norm;
	t_matrix	*trans;

	plane = (t_plane*)new_object(PLANE, &plane_intersect, sizeof(t_plane));
	set_dot(&norm, 0, 1, 0);
	trans = create_identity(4);
	x_rotation(&trans, x_angle);
	z_rotation(&trans, z_angle);
	mult_dot(&norm, trans, &norm);
	plane->a = norm.x;
	plane->b = norm.y;
	plane->c = norm.z;
	plane->d = -(norm.x * pos.x + norm.y * pos.y + norm.z * pos.z);
	plane->z = pos.z / 1000;
	return (plane);
}
