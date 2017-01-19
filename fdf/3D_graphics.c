/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:02:13 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/19 13:40:04 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_camera	*new_camera(int fov, double h_ang, double v_ang, double d)
{
	t_camera	*cam;
	t_matrix	*tmp1;
	t_matrix	*tmp2;

	if (!(cam = malloc(sizeof(t_camera))))
		return (NULL);
	cam->fov = fov;
	cam->theta = v_ang;
	cam->phi = h_ang;
	cam->r = d;
	cam->f = HEIGHT / (2 *tan(to_rad(fov) / 2.0f));
	tmp1 = create_identity(4);
	translation(&tmp1, -d * cos(v_ang) * cos(h_ang),
				-d * sin(v_ang) * cos(h_ang),
				-d * sin(h_ang));
	x_rotation(&tmp1, 90 + h_ang);
	z_rotation(&tmp1, v_ang - 90);
	tmp2 = create_identity(4);
	tmp2->mat[1][1] = -1;
	cam->proj = mult_matrix(tmp1, tmp2);
	delete_matrix(&tmp1);
	delete_matrix(&tmp2);
	return (cam);
}

void		set_camera_fov(t_camera	*cam, int fov)
{
	cam->fov = fov;
	cam->f = 1 / tan(to_rad(fov) / 2.0f);
}

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

void		projection(t_camera *cam, t_map *map)
{
	t_vector	p1;
	t_vector	p2;
	t_vector	p3;
	t_vector	p4;
	int			flag;

	flag = 1;
	while (flag)
	{
		transform_vector(&p1, map->vect, cam);
		transform_vector(&p2, map->right->vect, cam);
		transform_vector(&p3, map->right->down->vect, cam);
		transform_vector(&p4, map->down->vect, cam);
		printf("(%f, %f)", p1.x, p1.y);
		printf("(%f, %f)\n", p2.x, p2.y);
		printf("(%f, %f)", p4.x, p4.y);
		printf("(%f, %f)\n\n", p3.x, p3.y);
		if (is_in_window(&p1) || is_in_window(&p2) || is_in_window(&p3) ||
			is_in_window(&p4))
			mlx_draw_quadrangle(&p1, &p2, &p3, &p4);
		if (map->right->right)
			map = map->right;
		else if (map->r_head->down->down)
			map = map->r_head->down;
		else
			flag = 0;
	}
}
