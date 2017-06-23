/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 12:56:49 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/23 21:55:47 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_objs_intersect(t_scene *scene, t_ray *ray, int light)
{
	double	t;
	t_dot	res;
	t_vector	vd;
	t_cell		*tmp;
	static long i = 0;
i += !(light);

	tmp = scene->collection;
	SDL_SetRenderDrawColor(get_sdl_core()->renderer, 255, 255, 255, 255);
	while (tmp)
	{
		if ((t = tmp->obj->intersect(ray, tmp->obj)) > -1)
		{
			equation_get_dot(&res, &ray->eq, t);
			if (!light)
			{
				set_vector(&vd, scene->light.crd.x - res.x,
								res.y - scene->light.crd.y,
								scene->light.crd.z - res.z);
				init_equation(&ray->eq, &vd, (t_vector*)&res);
				return (check_objs_intersect(scene, ray, 1));
			}
			return (0);
		}
		tmp = tmp->next;
	}
	return (light);
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
			set_vector(&vd, scene->cam->screen[i][j].x - scene->cam->crd.x,
						scene->cam->screen[i][j].y - scene->cam->crd.y,
						scene->cam->screen[i][j].z - scene->cam->crd.z);
			init_equation(&ray.eq, &vd, (t_vector*)&scene->cam->crd);
			if (check_objs_intersect(scene, &ray, 0))
			{
				SDL_RenderDrawPoint(get_sdl_core()->renderer, i, j);
			}
		}
	}
	refresh_win();
}
