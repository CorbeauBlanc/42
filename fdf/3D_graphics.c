/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:02:13 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/16 20:48:04 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_camera	*new_camera(int fov)
{
	t_camera	*cam;

	if (!(cam = malloc(sizeof(t_camera))))
		return (NULL);
	cam->fov = fov;
	cam->theta = 90;
	cam->phi = 90;
	cam->r = 1 / tan(to_rad(fov) / 2.0);
	return (cam);
}

void		set_camera_fov(t_camera	*cam, int fov)
{
	cam->fov = fov;
	cam->r = 1 / tan(to_rad(fov) / 2.0);
}

void		transform_map(t_map *map, t_matrix *mat)
{
	t_map	*r_head;

	while (map)
	{
		if (!map->left)
			r_head = map;
		mult_vector(map->vect, mat, map->vect);
		if (map->right)
			map = map->right;
		else
			map = r_head->down;
	}
}

void		projection(t_camera *cam, t_map *map)
{
	t_vector	p1;
	t_vector	p2;
	t_vector	p3;
	t_vector	p4;
	t_map		*r_head;
	int			flag;

	flag = 1;
	while (flag)
	{
		transform_vector(&p1, map->vect, cam->r);
		transform_vector(&p2, map->right->vect, cam->r);
		transform_vector(&p3, map->right->down->vect, cam->r);
		transform_vector(&p4, map->down->vect, cam->r);
		if (!(map->left))
			r_head = map;
		if (is_in_window(&p1) || is_in_window(&p2) || is_in_window(&p3) ||
			is_in_window(&p4))
			mlx_draw_quadrangle(&p1, &p2, &p3, &p4);
		if (map->right->right)
			map = map->right;
		else if (r_head->down->down)
			map = r_head->down;
		else
			flag = 0;
	}
}
