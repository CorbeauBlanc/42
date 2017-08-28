/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:09:17 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/24 14:44:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static int				is_in_box(t_plane *p, t_box *b, t_dot *d)
{
	if (p == b->front || p == b->back)
		return (d->x <= b->btr_corner.x && d->x >= b->fbl_corner.x &&
				d->y <= b->btr_corner.y && d->y >= b->fbl_corner.y);
	else if (p == b->top || p == b->bottom)
		return (d->x <= b->btr_corner.x && d->x >= b->fbl_corner.x &&
				d->z <= b->btr_corner.z && d->z >= b->fbl_corner.z);
	else if (p == b->left || p == b->right)
	{
		return (d->y <= b->btr_corner.y && d->y >= b->fbl_corner.y &&
				d->z <= b->btr_corner.z && d->z >= b->fbl_corner.z);
	}
	return (0);
}

static void				box_plane_intersect(t_ray *ray, t_plane *p,
											t_box_intersect *its)
{
	double		t;
	double		dist;
	t_dot		res;

	if ((t = p->intersect(ray, p)) > -1)
	{
		equation_get_dot(&res, &ray->eq_obj, t);
		dist = get_dot_dist((t_dot*)&ray->eq_obj.vconst, &res);
		if ((dist < its->dist || its->dist < 0) && is_in_box(p, its->box, &res))
		{
			its->dist = dist;
			its->t = t;
		}
	}
}

static double			box_intersect(t_ray *ray, t_box *b)
{
	t_box_intersect	its;

	its.dist = -1;
	its.t = -1;
	its.box = b;
	box_plane_intersect(ray, b->front, &its);
	box_plane_intersect(ray, b->back, &its);
	box_plane_intersect(ray, b->bottom, &its);
	box_plane_intersect(ray, b->top, &its);
	box_plane_intersect(ray, b->left, &its);
	box_plane_intersect(ray, b->right, &its);
	return (its.t);
}

static const t_vector	*get_box_normal(t_dot *d, t_box *b)
{
	if (is_in_plane(d, b->front))
		return (&b->front->normal);
	else if (is_in_plane(d, b->back))
		return (&b->back->normal);
	else if (is_in_plane(d, b->bottom))
		return (&b->bottom->normal);
	else if (is_in_plane(d, b->top))
		return (&b->top->normal);
	else if (is_in_plane(d, b->left))
		return (&b->left->normal);
	else
		return (&b->right->normal);
}

t_box					*new_box(t_dot fbl_corner, double x_width,
								double y_width, double z_width)
{
	t_box	*box;

	box = (t_box*)new_object(BOX, &box_intersect, &get_box_normal,
							sizeof(t_box));
	box->fbl_corner = fbl_corner;
	box->btr_corner = (t_dot){fbl_corner.x + x_width, fbl_corner.y + y_width,
							fbl_corner.z + z_width, 0};
	box->front = new_plane(fbl_corner, 90, 0);
	box->bottom = new_plane(fbl_corner, 0, 0);
	box->left = new_plane(fbl_corner, 0, 90);
	box->back = new_plane((t_dot){fbl_corner.x, fbl_corner.y,
								box->btr_corner.z, 0}, 90, 0);
	box->top = new_plane((t_dot){fbl_corner.x, box->btr_corner.y,
								fbl_corner.z, 0}, 0, 0);
	box->right = new_plane((t_dot){box->btr_corner.x, fbl_corner.y,
								fbl_corner.z, 0}, 0, 90);
	translation(&box->trans, fbl_corner.x, fbl_corner.y, fbl_corner.z);
	translation(&box->trans_inv, -fbl_corner.x, -fbl_corner.y, -fbl_corner.z);
	return (box);
}
