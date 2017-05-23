/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:12:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/23 21:25:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

t_camera	*create_camera(int fov, double angle, int fps, double sensibility)
{
	t_camera	*cam;

	if (!(cam = malloc(sizeof(t_camera))))
		return (NULL);
	cam->sensi = sensibility;
	cam->fov = fov;
	cam->f = SDL_GetCore()->width / (2 * tan(ft_to_rad(fov) / 2.0f));
	set_rect_crd(&cam->screen, 0, 0);
	set_rect_dim(&cam->screen, SDL_GetCore()->width, SDL_GetCore()->height);
	cam->half_scr = cam->screen.h / 2;
	cam->angle = angle;
	cam->min_cam_mvt = cam->half_scr - (BOBBING * cam->screen.h / 100) * SPEED;
	cam->max_cam_mvt = cam->half_scr + (BOBBING * cam->screen.h / 100) * SPEED;
	cam->refresh_cam = NULL;
	cam->fps = fps;
	cam->state = STOP;
	return (cam);
}

void		delete_camera(t_camera *cam)
{
	free(cam);
}

void		set_camera_fov(t_camera *cam, int fov)
{
	cam->fov = fov;
	cam->f = SDL_GetCore()->width / (2 * tan(ft_to_rad(cam->fov) / 2.0f));
}

void		set_camera_bobbing(t_camera *cam, int bobbing)
{
	cam->min_cam_mvt = cam->half_scr - (bobbing * cam->screen.h / 100) * SPEED;
	cam->max_cam_mvt = cam->half_scr + (bobbing * cam->screen.h / 100) * SPEED;
}

void		set_camera_mvt(t_camera *cam)
{
	static double	x = 0;
	static double	i = SPEED;
	double			y;

	y = (SDL_GetCore()->height / 2) - pow((x / BOBBING), 2);
	if (y > cam->max_cam_mvt || y < cam->min_cam_mvt)
		i = -i;
	else
		cam->half_scr = y;
	x += i;
}
