/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 22:16:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/12 22:34:39 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cast_background(t_ray *ray, int i, t_player *player)
{
	SDL_Rect srect;
	SDL_Rect drect;

	set_rect_crd(&srect, (int)(player->tile->data->bg_fact * ft_to_deg(ray->a) + player->tile->data->bgd->w) % player->tile->data->bgd->w, 0);
	set_rect_dim(&srect, 1, player->tile->data->floor.a ?
							player->cam->half_scr : player->cam->screen.h);
	set_rect_crd(&drect, i, 0);
	set_rect_dim(&drect, 1, player->tile->data->floor.a ?
							player->cam->half_scr : player->cam->screen.h);
	SDL_RenderCopy(SDL_GetCore()->renderer, player->tile->data->bgd->text, &srect, &drect);
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
		xt = (int)(ray->h_i.x * wall->texture->mapping_fact) % wall->texture->w;
	else if ((wall = ray->v_wall))
		xt = (int)(ray->v_i.y * wall->texture->mapping_fact) % wall->texture->w;
	else
		return (1);
	set_rect_crd(&srect, xt, 0);
	set_rect_dim(&srect, 1, wall->reflect->h);
	SDL_SetTextureColorMod(wall->reflect->text,
							ray->filter, ray->filter, ray->filter);
	SDL_RenderCopy(SDL_GetCore()->renderer, wall->reflect->text, &srect, &drect);
	return (0);
}

static void	draw_floor_strip(int i, SDL_Texture *t)
{
	SDL_Rect	src;
	SDL_Rect	dst;

	set_rect_crd(&src, 0, 0);
	set_rect_dim(&src, SDL_GetCore()->width, 1);
	set_rect_crd(&dst, 0, i);
	set_rect_dim(&dst, SDL_GetCore()->width, 1);
	SDL_RenderCopy(SDL_GetCore()->renderer, t, &src, &dst);
}

void	cast_floor(t_player *player)
{
	SDL_Surface	*tmp;
	SDL_Texture	*txt;
	SDL_Rect	dim;
	int			i;
	Uint8		filter;

	set_rect_crd(&dim, 0, 0);
	set_rect_dim(&dim, SDL_GetCore()->width, 1);
	tmp = SDL_CreateRGBSurface(0, SDL_GetCore()->width, 1, 32, 0, 0, 0, 0);
	SDL_FillRect(tmp, &dim, get_color(0, 255, 0));
	txt = SDL_CreateTextureFromSurface(SDL_GetCore()->renderer, tmp);
	i = player->cam->half_scr;
	while (++i <= SDL_GetCore()->height)
	{
		filter = get_filter_value(get_player()->tile->data,
			((WALL_SIZE / 2) * player->cam->f) / (i - player->cam->half_scr));
		SDL_SetTextureColorMod(txt, filter, filter, filter);
		draw_floor_strip(i - 1, txt);
	}
	SDL_FreeSurface(tmp);
	SDL_DestroyTexture(txt);
}
