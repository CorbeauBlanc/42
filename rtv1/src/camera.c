/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:12:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/11 16:16:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

void		init_cam_screen(t_camera *cam)
{
	t_dot		tmp;
	t_matrix	*transfo;
	int			i;
	int			j;

	transfo = create_identity(4);
	translation(&transfo, cam->crd.x, cam->crd.y, cam->crd.z);
	y_rotation(&transfo, cam->theta);
	x_rotation(&transfo, cam->phi);
	tmp.x = -WIN_WIDTH / 2;
	i = 0;
	while ((i += cam->resolution) < WIN_WIDTH)
	{
		tmp.x += cam->resolution;
		tmp.y = -WIN_HEIGHT / 2;
		j = 0;
		while ((j += cam->resolution) < WIN_HEIGHT)
		{
			tmp.y += cam->resolution;
			set_dot(&cam->screen[i][j], tmp.x, tmp.y, cam->f);
			mult_vect((t_vector*)&cam->screen[i][j], transfo,
						(t_vector*)&cam->screen[i][j]);
		}
	}
}

t_camera	*new_camera(int fov, const t_dot crd, double h_ang, double v_ang)
{
	t_camera	*cam;

	if (!(cam = malloc(sizeof(t_camera))))
		exit_error("rtv1", "malloc");
	cam->fov = fov;
	cam->crd = crd;
	cam->theta = h_ang;
	cam->phi = -v_ang;
	cam->f = WIN_WIDTH / (2 * tan(ft_to_rad(fov) / 2.0f));
	cam->low_resolution = DEFAULT_LR;
	cam->resolution = 1;
	init_cam_screen(cam);
	return (cam);
}

void		delete_camera(t_camera *cam)
{
	free(cam);
}

void		set_camera_fov(t_camera *cam, int fov)
{
	cam->fov = fov;
	cam->f = WIN_WIDTH / (2 * tan(ft_to_rad(cam->fov) / 2.0f));
}
