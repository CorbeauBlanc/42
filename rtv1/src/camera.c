/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:12:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/14 20:21:17 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static void	init_cam_screen(t_camera *cam)
{
	t_dot		tmp;
	t_matrix	*transfo;
	int			i;
	int			j;

	tmp.x = cam->crd.x - WIDTH / 2 - 1;
	tmp.y = cam->crd.y - HEIGHT / 2 - 1;
	transfo = create_identity(4);
	x_rotation(&transfo, cam->theta);
	y_rotation(&transfo, cam->phi);
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		++tmp.x;
		while (++j < HEIGHT)
		{
			set_dot(cam->screen[i][j], tmp.x, ++tmp.y, cam->crd.z + cam->f);
			mult_dot(cam->screen[i][j], transfo, cam->screen[i][j]);
		}
	}
}

t_camera	*new_camera(int fov, const t_dot *crd, double h_ang, double v_ang)
{
	t_camera	*cam;

	if (!(cam = malloc(sizeof(t_camera))))
		exit_error("rtv1", "malloc");
	cam->fov = fov;
	cam->crd = *crd;
	cam->theta = v_ang;
	cam->phi = h_ang;
	cam->f = WIDTH / (2 * tan(ft_to_rad(fov) / 2.0f));
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
	cam->f = get_sdl_core()->width / (2 * tan(ft_to_rad(cam->fov) / 2.0f));
}
