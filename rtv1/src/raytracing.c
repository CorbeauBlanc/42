/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 12:56:49 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/12 20:31:03 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_objs_intersect(t_scene *scene, t_ray *ray, int light)
{
	t_dot		res;
	t_cell		*tmp;
	double		t;
	t_vector	n;

	tmp = scene->collection;
	while (tmp)
	{
		mult_vect(&ray->eq_obj.vconst, tmp->obj->trans_inv, &ray->eq.vconst);
		mult_vect(&ray->eq_obj.vconst, tmp->obj->rot_inv, &ray->eq_obj.vconst);
		mult_vect(&ray->eq_obj.vdir, tmp->obj->rot_inv, &ray->eq.vdir);
		if ((t = tmp->obj->intersect(ray, tmp->obj)) > -1)
		{
			if (light)
				return (0);
			equation_get_dot(&res, &ray->eq_obj, t);
			mult_vect(&n, tmp->obj->rot, tmp->obj->get_normal(&res, tmp->obj));
			mult_vect((t_vector*)&res, tmp->obj->rot, (t_vector*)&res);
			mult_vect((t_vector*)&res, tmp->obj->trans, (t_vector*)&res);
			t = get_dot_dist(&scene->cam->crd, &res);
			if (!ray->i.obj || t < ray->i.dist)
				ray->i = (t_intersect){t, 0, res, tmp->obj, n};
		}
		tmp = tmp->next;
	}
	if (!ray->i.obj || light)
		return (light);
	init_equation(&ray->eq, &(t_vector){scene->light->crd.x - ray->i.dot.x,
					scene->light->crd.y - ray->i.dot.y,
					scene->light->crd.z - ray->i.dot.z}, (t_vector*)&ray->i.dot);
	ray->i.ldist = get_vect_len(&ray->eq.vdir);
	return (check_objs_intersect(scene, ray, 1));
}

static void	get_shade_color(SDL_Color *dest, const t_ray *ray, const t_scene *scene)
{
	double		coef;
	SDL_Color	*col;
	t_vector	tmp;

	col = &ray->i.obj->color;
	coef = (vect_dot_product(&ray->eq.vdir, &ray->i.normal) /
		(get_vect_len(&ray->eq.vdir) * get_vect_len(&ray->i.normal))) *
		scene->light->power;
	if (coef < 0)
		coef = 0;
	tmp.x = col->r * (scene->brightness + coef);
	tmp.y = col->g * (scene->brightness + coef);
	tmp.z = col->b * (scene->brightness + coef);
	*dest = (SDL_Color){tmp.x > 255 ? 255 : tmp.x,
						tmp.y > 255 ? 255 : tmp.y,
						tmp.z > 255 ? 255 : tmp.z, 255};
}

static void	get_shadow_color(SDL_Color *dest, const t_ray *ray, const t_scene *scene)
{
	if (!ray->i.obj)
		*dest = (SDL_Color){scene->bgcolor.r, scene->bgcolor.g,
							scene->bgcolor.b, 255};
	else
	{
		dest->r = ray->i.obj->color.r * scene->brightness;
		dest->g = ray->i.obj->color.g * scene->brightness;
		dest->b = ray->i.obj->color.b * scene->brightness;
		dest->a = 255;
	}
}

static void	trace_ray(int i, int j, t_scene *scene)
{
	t_ray			ray;
	t_vector		vd;

	ray.i.obj = NULL;
	set_vector(&vd,
		scene->cam->screen[i][j].x - scene->cam->crd.x,
		scene->cam->screen[i][j].y - scene->cam->crd.y,
		scene->cam->screen[i][j].z - scene->cam->crd.z);
	init_equation(&ray.eq, &vd, (t_vector*)&scene->cam->crd);
	if (check_objs_intersect(scene, &ray, 0))
		get_shade_color(&ray.color, &ray, scene);
	else
		get_shadow_color(&ray.color, &ray, scene);
	SDL_SetRenderDrawColor(get_sdl_core()->renderer,
						ray.color.r, ray.color.g, ray.color.b, 255);
	SDL_RenderDrawPoint(get_sdl_core()->renderer, i, HEIGHT - j);
}

void		render_scene(t_scene *scene)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			trace_ray(i, j, scene);
	}
	refresh_win();
}
