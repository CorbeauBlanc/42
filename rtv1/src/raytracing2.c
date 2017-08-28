/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 12:56:49 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 19:49:43 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	transformation_cam(t_ray *ray, t_cell *c)
{
	mult_vect(&ray->eq_obj.vconst, c->obj->trans_inv, &ray->eq.vconst);
	mult_vect(&ray->eq_obj.vconst, c->obj->rot_inv, &ray->eq_obj.vconst);
	mult_vect(&ray->eq_obj.vconst, c->obj->scale_inv, &ray->eq_obj.vconst);
	mult_vect(&ray->eq_obj.vdir, c->obj->rot_inv, &ray->eq.vdir);
	mult_vect(&ray->eq_obj.vdir, c->obj->scale_inv, &ray->eq_obj.vdir);
}

static void	transformation_cam_inv(t_cell *c, t_dot *res, t_vector *n)
{
	mult_vect(n, c->obj->scale_inv, c->obj->get_normal(res, c->obj));
	mult_vect(n, c->obj->rot, n);
	mult_vect((t_vector*)res, c->obj->scale, (t_vector*)res);
	mult_vect((t_vector*)res, c->obj->rot, (t_vector*)res);
	mult_vect((t_vector*)res, c->obj->trans, (t_vector*)res);
}

static void	init_ray_new_equation(t_ray *ray, t_scene *scene)
{
	init_equation(&ray->eq, &(t_vector){scene->light->crd.x - ray->i.dot.x,
					scene->light->crd.y - ray->i.dot.y,
					scene->light->crd.z - ray->i.dot.z},
					(t_vector*)&ray->i.dot);
}

int			check_objs_intersect(t_scene *scene, t_ray *ray, int light)
{
	t_dot		res;
	t_cell		*c;
	double		t;
	t_vector	n;

	c = &(t_cell){NULL, scene->collection};
	while ((c = c->next))
	{
		transformation_cam(ray, c);
		if ((t = c->obj->intersect(ray, c->obj)) > -1)
		{
			if (light)
				return (0);
			equation_get_dot(&res, &ray->eq_obj, t);
			transformation_cam_inv(c, &res, &n);
			t = get_dot_dist(&scene->cam->crd, &res);
			if (!ray->i.obj || t < ray->i.dist)
				ray->i = (t_intersect){t, 0, res, c->obj, n};
		}
	}
	if (!ray->i.obj || light)
		return (light);
	init_ray_new_equation(ray, scene);
	ray->i.ldist = get_vect_len(&ray->eq.vdir);
	return (check_objs_intersect(scene, ray, 1));
}
