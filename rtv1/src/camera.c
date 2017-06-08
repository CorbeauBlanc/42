/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:12:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 18:48:38 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

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
	set_rect_crd(&cam->screen, 0, 0);
	set_rect_dim(&cam->screen, get_sdl_core()->width, get_sdl_core()->height);
	return (cam);
}

void		delete_camera(t_camera *cam)
{
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
}
