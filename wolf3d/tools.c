/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:35:27 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/13 16:10:49 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_rect_dim(SDL_Rect *rect, int w, int h)
{
	rect->h = h;
	rect->w = w;
}

void		set_rect_crd(SDL_Rect *rect, int x, int y)
{
	rect->x = x;
	rect->y = y;
}

t_ray		*set_wall(t_ray *ray, t_map **ray_wall, t_map *wall)
{
	*ray_wall = wall;
	return (ray);
}

void		set_vect_crd(t_vector *vect, double x, double y)
{
	vect->x = x;
	vect->y = y;
}
