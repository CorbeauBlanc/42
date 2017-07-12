/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 12:56:49 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/12 20:06:08 by edescoin         ###   ########.fr       */
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

static int	trace_ray(void *arguments)
{
	t_thread_args	*args;
	t_ray			ray;
	t_vector		vd;

	args = (t_thread_args*)arguments;
	ray.i.obj = NULL;
	set_vector(&vd,
		args->scene->cam->screen[args->i][args->j].x - args->scene->cam->crd.x,
		args->scene->cam->screen[args->i][args->j].y - args->scene->cam->crd.y,
		args->scene->cam->screen[args->i][args->j].z - args->scene->cam->crd.z);
	init_equation(&ray.eq, &vd, (t_vector*)&args->scene->cam->crd);
	if (check_objs_intersect(args->scene, &ray, 0))
		get_shade_color(&ray.color, &ray, args->scene);
	else
		get_shadow_color(&ray.color, &ray, args->scene);
	SDL_LockMutex(get_sdl_core()->mutex);
	SDL_SetRenderDrawColor(get_sdl_core()->renderer,
						ray.color.r, ray.color.g, ray.color.b, 255);
	SDL_RenderDrawPoint(get_sdl_core()->renderer, args->i, HEIGHT - args->j);
	SDL_UnlockMutex(get_sdl_core()->mutex);
	return (1);
}

void		render_scene(t_scene *scene)
{
	int			i;
	int			j;
	int			t;
	SDL_Thread	*threads[MAX_THREADS];

	i = -1;
	for (t = 0; t < MAX_THREADS; t++) {
		threads[t] = NULL;
	}
	t = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			t = (t + 1) % MAX_THREADS;
			SDL_WaitThread(threads[t], NULL);
			if (!(threads[t] = SDL_CreateThread(trace_ray, "rt",
											&(t_thread_args){i, j, scene})))
				exit_custom_error("rtv1 : SDL2 : ", (char*)SDL_GetError());
		}
	}
	t = -1;
	while (++t < MAX_THREADS)
		SDL_WaitThread(threads[t], NULL);
	refresh_win();
}
