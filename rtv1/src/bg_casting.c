/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 22:16:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/26 15:11:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static void	draw_bg_reflection(t_map_data *data, SDL_Rect *srect,
								SDL_Rect *drect, t_player *plr)
{
	(void)plr;
	if (data->floor.a)
	{
		if (data->reflection)
		{
			srect->y = data->bgd->h / 2;
			srect->h = srect->y;
			drect->y = get_sdl_core()->height / 2;
			drect->h = drect->y;
			SDL_SetTextureAlphaMod(data->bgd->text, data->reflection);
			SDL_RenderCopy(get_sdl_core()->renderer, data->bgd->text, srect,
							drect);
			SDL_SetTextureAlphaMod(data->bgd->text, 255);
		}
	}
}

void		cast_background(t_ray *ray, int i, t_player *plr)
{
	SDL_Rect	srect;
	SDL_Rect	drect;
	t_map_data	*data;

	data = plr->tile->data;
	set_rect_crd(&srect, (int)(data->bg_fact * ft_to_deg(ray->a) + data->bgd->w)
						% data->bgd->w, 0);
	set_rect_dim(&srect, 1, data->floor.a ? data->bgd->h / 2 : data->bgd->h);
	set_rect_crd(&drect, i, 0);
	set_rect_dim(&drect, 1, data->floor.a ? get_sdl_core()->height / 2 :
											get_sdl_core()->height);
	SDL_RenderCopy(get_sdl_core()->renderer, data->bgd->text, &srect, &drect);
	draw_bg_reflection(data, &srect, &drect, plr);
}

static void	draw_wall_reflection(t_map *wall, t_ray *ray, SDL_Rect *srect,
								SDL_Rect *drect)
{
	SDL_SetTextureColorMod(wall->reflections[ray->side]->text, ray->filter,
							ray->filter, ray->filter);
	SDL_RenderCopy(get_sdl_core()->renderer, wall->data->floor_ceiling_txt,
					drect, drect);
	SDL_RenderCopy(get_sdl_core()->renderer, wall->reflections[ray->side]->text,
					srect, drect);
}

int			cast_reflection(t_ray *ray, int i, t_player *plr)
{
	int			xt;
	SDL_Rect	srect;
	SDL_Rect	drect;
	t_map		*wall;

	set_rect_crd(&drect, i, plr->cam->half_scr - ray->h / 2 + ray->h - 2);
	set_rect_dim(&drect, 1, ray->h);
	if (ray->h_i.w < ray->v_i.w && (wall = ray->h_wall))
		xt = (int)(ray->h_i.x * wall->reflections[ray->side]->mapping_fact) %
				wall->reflections[ray->side]->w;
	else if ((wall = ray->v_wall))
		xt = (int)(ray->v_i.y * wall->reflections[ray->side]->mapping_fact) %
				wall->reflections[ray->side]->w;
	else
		return (1);
	set_rect_crd(&srect, xt, 0);
	set_rect_dim(&srect, 1, wall->reflections[ray->side]->h);
	if (!wall->data->bgd && ray->filter > wall->data->reflection)
		SDL_SetTextureAlphaMod(wall->reflections[ray->side]->text,
								wall->data->reflection);
	else if (!wall->data->bgd)
		SDL_SetTextureAlphaMod(wall->reflections[ray->side]->text, ray->filter);
	draw_wall_reflection(wall, ray, &srect, &drect);
	return (0);
}
