/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:12:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/02 01:23:49 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

t_matrix	*set_view_mtx(double theta, double phi, double d)
{
	t_matrix	*m;
	(void)d;

	m = create_identity(4);
	m->mat[0][0] = -cos(to_rad(theta));
	m->mat[0][1] = sin(to_rad(theta));
	m->mat[0][2] = 0;
	m->mat[0][3] = 1;
	m->mat[1][0] = (cos(to_rad(theta - phi)) - cos(to_rad(theta + phi))) / -2;
	m->mat[1][1] = (sin(to_rad(phi + theta)) + sin(to_rad(phi - theta))) / -2;
	m->mat[1][2] = cos(to_rad(phi));
	m->mat[1][3] = 1;
	m->mat[2][0] = (sin(to_rad(theta + phi)) + sin(to_rad(theta - phi))) / 2;
	m->mat[2][1] = (cos(to_rad(theta - phi)) + cos(to_rad(theta + phi))) / 2;
	m->mat[2][2] = sin(to_rad(phi));
	m->mat[2][3] = -d * sin(to_rad(phi));
	m->mat[3][0] = 0;
	m->mat[3][1] = 0;
	m->mat[3][2] = 0;
	m->mat[3][3] = 1;
	return (m);
}

t_camera	*new_camera(int fov, double h_ang, double v_ang, double d)
{
	t_camera	*cam;

	if (!(cam = malloc(sizeof(t_camera))))
		return (NULL);
	cam->fov = fov;
	cam->theta = v_ang;
	cam->phi = h_ang;
	cam->r = d;
	cam->f = HEIGHT / (2 * tan(to_rad(fov) / 2.0f));
	cam->view = set_view_mtx(v_ang, h_ang, d);
	cam->screen = create_image(WIDTH, HEIGHT, 32);
	return (cam);
}

void		delete_camera(t_camera *cam)
{
	delete_matrix(cam->view);
	delete_image(cam->screen);
	free(cam);
}

void		set_camera_fov(t_camera *cam, int fov)
{
	cam->fov = fov;
	cam->f = HEIGHT / (2 * tan(to_rad(cam->fov) / 2.0f));
}

void		set_camera_crd(t_camera *cam, double h_ang, double v_ang, double d)
{
	cam->theta = v_ang;
	cam->phi = h_ang;
	cam->r = d;
	cam->f = HEIGHT / (2 * tan(to_rad(cam->fov) / 2.0f));
	cam->view = set_view_mtx(v_ang, h_ang, d);
}
