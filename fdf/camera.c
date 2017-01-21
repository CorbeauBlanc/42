/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:12:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/21 13:19:40 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
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
	delete_matrix(tmp1);
	delete_matrix(tmp2);
	return (cam);
}

void		delete_camera(t_camera *cam)
{
	delete_matrix(cam->proj);
	free(cam);
}

void		set_camera_fov(t_camera	*cam, int fov)
{
	cam->fov = fov;
	cam->f = HEIGHT / (2 *tan(to_rad(cam->fov) / 2.0f));
}

void		set_camera_crd(t_camera *cam, double h_ang, double v_ang, double d)
{
	t_matrix	*tmp1;
	t_matrix	*tmp2;

	cam->theta = v_ang;
	cam->phi = h_ang;
	cam->r = d;
	cam->f = HEIGHT / (2 *tan(to_rad(cam->fov) / 2.0f));
	tmp1 = create_identity(4);
	translation(&tmp1, -d * cos(v_ang) * cos(h_ang),
				-d * sin(v_ang) * cos(h_ang),
				-d * sin(h_ang));
	x_rotation(&tmp1, 90 + h_ang);
	z_rotation(&tmp1, v_ang - 90);
	tmp2 = create_identity(4);
	tmp2->mat[1][1] = -1;
	cam->proj = mult_matrix(tmp1, tmp2);
	delete_matrix(tmp1);
	delete_matrix(tmp2);
}
