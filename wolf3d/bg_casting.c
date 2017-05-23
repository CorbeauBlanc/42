/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 22:16:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/23 20:49:52 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	cast_background(t_ray *ray, int i, t_player *plr)
{
	SDL_Rect	srect;
	SDL_Rect	drect;
	t_map_data	*data;

	data = plr->tile->data;
	set_rect_crd(&srect, (int)(data->bg_fact * ft_to_deg(ray->a) + data->bgd->w) % data->bgd->w, 0);
	set_rect_dim(&srect, 1, data->floor.a ? plr->cam->half_scr : SDL_GetCore()->height);
	set_rect_crd(&drect, i, 0);
	set_rect_dim(&drect, 1, data->floor.a ? plr->cam->half_scr : SDL_GetCore()->height);
	SDL_RenderCopy(SDL_GetCore()->renderer, data->bgd->text, &srect, &drect);
	if (data->floor.a)
	{
		if (data->reflection)
		{
			srect.y = plr->cam->half_scr;
			drect.y = srect.y;
			srect.h = SDL_GetCore()->height - srect.y;
			drect.h = srect.h;
			SDL_SetTextureAlphaMod(data->bgd->text, data->reflection);
			SDL_RenderCopy(SDL_GetCore()->renderer, data->bgd->text, &srect, &drect);
			SDL_SetTextureAlphaMod(data->bgd->text, 255);
		}
	}
}

int		cast_reflection(t_ray *ray, int i, t_player *plr)
{
	int			xt;
	SDL_Rect	srect;
	SDL_Rect	drect;
	t_map		*wall;

	set_rect_crd(&drect, i, plr->cam->half_scr - ray->h / 2 + ray->h - 2);
	set_rect_dim(&drect, 1, ray->h);
	if (ray->h_i.w < ray->v_i.w && (wall = ray->h_wall))
		xt = (int)(ray->h_i.x * wall->reflections[ray->side]->mapping_fact) % wall->reflections[ray->side]->w;
	else if ((wall = ray->v_wall))
		xt = (int)(ray->v_i.y * wall->reflections[ray->side]->mapping_fact) % wall->reflections[ray->side]->w;
	else
		return (1);
	set_rect_crd(&srect, xt, 0);
	set_rect_dim(&srect, 1, wall->reflections[ray->side]->h);
	if (!wall->data->bgd && ray->filter > wall->data->reflection)
		SDL_SetTextureAlphaMod(wall->reflections[ray->side]->text, wall->data->reflection);
	else if (!wall->data->bgd)
		SDL_SetTextureAlphaMod(wall->reflections[ray->side]->text, ray->filter);
	SDL_SetTextureColorMod(wall->reflections[ray->side]->text, ray->filter, ray->filter, ray->filter);
	SDL_RenderCopy(SDL_GetCore()->renderer, wall->data->floor_ceiling_txt, &drect, &drect);
	SDL_RenderCopy(SDL_GetCore()->renderer, wall->reflections[ray->side]->text, &srect, &drect);
	return (0);
}

static void	draw_floor_ceiling_strip(int i, SDL_Surface *tmp, SDL_Color *col)
{
	SDL_Rect	dim;
	Uint8		filter;
	t_player	*plr;

	plr = get_player();
	set_rect_crd(&dim, 0, i);
	set_rect_dim(&dim, SDL_GetCore()->width, 1);
	filter = get_filter_value(plr->tile->data, ((WALL_SIZE / 2) * plr->cam->f) /
												fabs((i - plr->cam->half_scr)));
	SDL_FillRect(tmp, &dim, get_color(col->r * (filter / 255.0),
									col->g * (filter / 255.0),
									col->b * (filter / 255.0)));
}

void	cast_floor_ceiling(t_player *plr)
{
	SDL_Surface	*tmp;
	int			i;

	tmp = SDL_CreateRGBSurface(0, SDL_GetCore()->width, SDL_GetCore()->height,
								32, 0, 0, 0, 0);
	i = plr->cam->half_scr;
	while (++i <= SDL_GetCore()->height)
		draw_floor_ceiling_strip(i - 1, tmp, &plr->tile->data->floor);
	i = plr->cam->half_scr;
	if (!(plr->tile->data->bgd))
		while (--i)
			draw_floor_ceiling_strip(i, tmp, &plr->tile->data->ceiling);
	SDL_DestroyTexture(plr->tile->data->floor_ceiling_txt);
	plr->tile->data->floor_ceiling_txt = SDL_CreateTextureFromSurface(SDL_GetCore()->renderer, tmp);
	SDL_RenderCopy(SDL_GetCore()->renderer, plr->tile->data->floor_ceiling_txt, NULL, NULL);
	SDL_FreeSurface(tmp);
}
