/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 22:16:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/30 18:00:35 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	cast_background(t_ray *ray, int i, t_player *player)
{
	SDL_Rect srect;
	SDL_Rect drect;

	set_rect_crd(&srect, (int)(player->tile->data->bg_fact * ft_to_deg(ray->a) + player->tile->data->bg_w) % player->tile->data->bg_w, 0);
	set_rect_dim(&srect, 1, player->cam->screen.h);
	set_rect_crd(&drect, i, 0);
	set_rect_dim(&drect, 1, player->cam->screen.h);
	SDL_RenderCopy(SDL_GetCore()->renderer, player->tile->data->background, &srect, &drect);
}

void	cast_reflection(t_ray *ray, int i, t_player *player)
{
	int			xt;
	SDL_Rect	srect;
	SDL_Rect	drect;
	t_map		*wall;

	set_rect_crd(&drect, i, (player->cam->screen.h - ray->h) / 2 + ray->h - 2);
	set_rect_dim(&drect, 1, ray->h);
	if (ray->h_i.w < ray->v_i.w)
	{
		xt = (int)(ray->h_i.x) % WALL_SIZE;
		wall = ray->h_wall;
	}
	else
	{
		xt = (int)(ray->v_i.y) % WALL_SIZE;
		wall = ray->v_wall;
	}
	set_rect_crd(&srect, xt, 0);
	set_rect_dim(&srect, 1, wall->refl_size);
	SDL_SetTextureColorMod(wall->reflect,
							ray->filter, ray->filter, ray->filter);
	SDL_RenderCopy(SDL_GetCore()->renderer, wall->reflect, &srect, &drect);
}
