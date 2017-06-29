/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 12:56:49 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/29 17:00:28 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_objs_intersect(t_scene *scene, t_ray *ray, int light)
{
	t_dot		res;
	t_cell		*tmp;
	double		t;

	tmp = scene->collection;
	while (tmp)
	{
		if ((t = tmp->obj->intersect(ray, tmp->obj)) > -1)
		{
			if (light)
				return (0);
			equation_get_dot(&res, &ray->eq, t);
			t = get_vect_norm((t_vector*)&res);
			if (t < ray->i.dist || !ray->i.dist)
				ray->i = (t_intersect){t, res, tmp->obj};
		}
		tmp = tmp->next;
	}
	if (!ray->i.dist || light)
		return (light);
	init_equation(&ray->eq, &(t_vector){scene->light.crd.x - ray->i.dot.x,
					scene->light.crd.y - ray->i.dot.y,
					scene->light.crd.z - ray->i.dot.z}, (t_vector*)&ray->i.dot);
	return (check_objs_intersect(scene, ray, 1));
}

void		render_scene(t_scene *scene)
{
	int	i;
	int	j;
	t_ray	ray;
	t_vector vd;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			ray.i.dist = 0;
			set_vector(&vd, scene->cam->screen[i][j].x - scene->cam->crd.x,
						scene->cam->screen[i][j].y - scene->cam->crd.y,
						scene->cam->screen[i][j].z - scene->cam->crd.z);
			init_equation(&ray.eq, &vd, (t_vector*)&scene->cam->crd);
			if (check_objs_intersect(scene, &ray, 0))
				SDL_SetRenderDrawColor(get_sdl_core()->renderer, 255, 255, 255, 255);
			else
				SDL_SetRenderDrawColor(get_sdl_core()->renderer, 0, 0, 0, 255);
			SDL_RenderDrawPoint(get_sdl_core()->renderer, i, HEIGHT - j);
		}
	}
	refresh_win();
}
