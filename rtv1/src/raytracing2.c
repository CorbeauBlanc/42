/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 12:56:49 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 17:51:59 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	check_objs(t_ray *ray, t_cell *tmp)
{
	double		t;
	t_vector	n;

	while ((tmp = tmp->next))
	{
		mult_vect(&ray->eq_obj.vconst, tmp->obj->trans_inv, &ray->eq.vconst);
		mult_vect(&ray->eq_obj.vconst, tmp->obj->rot_inv, &ray->eq_obj.vconst);
		mult_vect(&ray->eq_obj.vconst, tmp->obj->scale_inv, &ray->eq_obj.vconst);
		mult_vect(&ray->eq_obj.vdir, tmp->obj->rot_inv, &ray->eq.vdir);
		mult_vect(&ray->eq_obj.vdir, tmp->obj->scale_inv, &ray->eq_obj.vdir);
		if ((t = tmp->obj->intersect(ray, tmp->obj)) > -1)
		{
			if (light)
				return (0);
			equation_get_dot(&res, &ray->eq_obj, t);
			mult_vect(&n, tmp->obj->scale_inv, tmp->obj->get_normal(&res, tmp->obj));
			mult_vect(&n, tmp->obj->rot, &n);
			mult_vect((t_vector*)&res, tmp->obj->scale, (t_vector*)&res);
			mult_vect((t_vector*)&res, tmp->obj->rot, (t_vector*)&res);
			mult_vect((t_vector*)&res, tmp->obj->trans, (t_vector*)&res);
			t = get_dot_dist(&scene->cam->crd, &res);
			if (!ray->i.obj || t < ray->i.dist)
				ray->i = (t_intersect){t, 0, res, tmp->obj, n};
		}
	}
}

int			check_objs_intersect(t_scene *scene, t_ray *ray, int light)
{
	t_dot		res;

	check_objs(ray, &(t_cell){NULL, scene->collection});
	if (!ray->i.obj || light)
		return (light);
	init_equation(&ray->eq, &(t_vector){scene->light->crd.x - ray->i.dot.x,
					scene->light->crd.y - ray->i.dot.y,
					scene->light->crd.z - ray->i.dot.z}, (t_vector*)&ray->i.dot);
	ray->i.ldist = get_vect_len(&ray->eq.vdir);
	return (check_objs_intersect(scene, ray, 1));
}
