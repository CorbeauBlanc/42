/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:02:13 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/21 19:00:04 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		transform_map(t_map *map, t_matrix *mat)
{
	while (map)
	{
		mult_vector(map->vect, mat, map->vect);
		if (map->right)
			map = map->right;
		else
			map = map->r_head->down;
	}
}

static void	draw_map_tile(t_image *img, t_tile *tile, t_map *map, t_camera *cam)
{
	transform_vector(&tile->p1, map->vect, cam);
	transform_vector(&tile->p2, map->right->vect, cam);
	transform_vector(&tile->p3, map->right->down->vect, cam);
	transform_vector(&tile->p4, map->down->vect, cam);
	printf("(%.2f, %.2f, %.2f)", tile->p1.x, tile->p1.y, tile->p1.z);
	printf("(%.2f, %.2f, %.2f)\n", tile->p2.x, tile->p2.y, tile->p2.z);
	printf("(%.2f, %.2f, %.2f)", tile->p4.x, tile->p4.y, tile->p4.z);
	printf("(%.2f, %.2f, %.2f)\n\n", tile->p3.x, tile->p3.y, tile->p3.z);
	if (is_in_window(&tile->p1) || is_in_window(&tile->p2) ||
		is_in_window(&tile->p3) || is_in_window(&tile->p4))
	{
		mlx_draw_line_img(img, &tile->p1, &tile->p2);
		mlx_draw_line_img(img, &tile->p2, &tile->p3);
		mlx_draw_line_img(img, &tile->p3, &tile->p4);
		mlx_draw_line_img(img, &tile->p4, &tile->p1);
	}
}

void		projection(t_image *img, t_map *map, t_camera *cam)
{
	t_tile		tile;
	int			flag;

	flag = 1;
	clear_image(img);
	while (flag)
	{
		draw_map_tile(img, &tile, map, cam);
		if (map->right->right)
			map = map->right;
		else if (map->r_head->down->down)
			map = map->r_head->down;
		else
			flag = 0;
	}
	display_image(img, 0, 0);
}
