/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:12:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 17:45:59 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_matrix	*set_view_mtx(double theta, double phi, double d)
{
	t_matrix	*m;

	m = create_identity(4);
	m->mat[0][0] = -cos(ft_to_rad(theta));
	m->mat[0][1] = sin(ft_to_rad(theta));
	m->mat[0][2] = 0;
	m->mat[0][3] = 1;
	m->mat[1][0] = (cos(ft_to_rad(theta - phi)) -
					cos(ft_to_rad(theta + phi))) / -2;
	m->mat[1][1] = (sin(ft_to_rad(phi + theta)) +
					sin(ft_to_rad(phi - theta))) / -2;
	m->mat[1][2] = cos(ft_to_rad(phi));
	m->mat[1][3] = 1;
	m->mat[2][0] = (sin(ft_to_rad(theta + phi)) +
					sin(ft_to_rad(theta - phi))) / 2;
	m->mat[2][1] = (cos(ft_to_rad(theta - phi)) +
					cos(ft_to_rad(theta + phi))) / 2;
	m->mat[2][2] = sin(ft_to_rad(phi));
	m->mat[2][3] = -d * sin(ft_to_rad(phi));
	m->mat[3][0] = 0;
	m->mat[3][1] = 0;
	m->mat[3][2] = 0;
	m->mat[3][3] = 1;
	return (m);
}

t_camera	*create_camera(int fov, double h_ang, double v_ang, double d)
{
	t_camera	*cam;

	if (!(cam = malloc(sizeof(t_camera))))
		return (NULL);
	cam->fov = fov;
	cam->theta = v_ang;
	cam->phi = h_ang;
	cam->r = d;
	cam->f = get_sdl_core()->width / (2 * tan(ft_to_rad(fov) / 2.0f));
	cam->view = set_view_mtx(v_ang, h_ang, d);
	set_rect_crd(&cam->screen, 0, 0);
	set_rect_dim(&cam->screen, get_sdl_core()->width, get_sdl_core()->height);
	return (cam);
}

void		delete_camera(t_camera *cam)
{
	delete_matrix(cam->view);
	free(cam);
}

void		set_camera_fov(t_camera *cam, int fov)
{
	cam->fov = fov;
	cam->f = get_sdl_core()->width / (2 * tan(ft_to_rad(cam->fov) / 2.0f));
}

void		set_camera_crd(t_camera *cam, double h_ang, double v_ang, double d)
{
	cam->theta = v_ang;
	cam->phi = h_ang;
	cam->r = d;
	set_camera_fov(cam, cam->fov);
	cam->view = set_view_mtx(v_ang, h_ang, d);
}
