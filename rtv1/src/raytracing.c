/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 12:56:49 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 19:52:37 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	get_shade_color(SDL_Color *dest, const t_ray *ray,
							const t_scene *scene)
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

static void	get_shadow_color(SDL_Color *dest, const t_ray *ray,
							const t_scene *scene)
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
	t_ray		ray;
	t_vector	vd;

	ray.i.obj = NULL;
	set_vector(&vd, scene->cam->screen[i][j].x - scene->cam->crd.x,
				scene->cam->screen[i][j].y - scene->cam->crd.y,
				scene->cam->screen[i][j].z - scene->cam->crd.z);
	init_equation(&ray.eq, &vd, (t_vector*)&scene->cam->crd);
	if (check_objs_intersect(scene, &ray, 0))
		get_shade_color(&ray.color, &ray, scene);
	else
		get_shadow_color(&ray.color, &ray, scene);
	SDL_SetRenderDrawColor(get_sdl_core()->renderer,
						ray.color.r, ray.color.g, ray.color.b, 255);
	SDL_RenderDrawPoint(get_sdl_core()->renderer, i, WIN_HEIGHT - j - 1);
}

void		render_scene(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	SDL_RenderClear(get_sdl_core()->renderer);
	while ((i += scene->cam->resolution) < WIN_WIDTH)
	{
		j = 0;
		while ((j += scene->cam->resolution) < WIN_HEIGHT)
			trace_ray(i, j, scene);
	}
	refresh_win();
}
