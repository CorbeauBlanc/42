/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:12:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/11 20:14:10 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_camera	*create_camera(int fov, int angle, double sensibility)
{
	t_camera	*cam;

	if (!(cam = malloc(sizeof(t_camera))))
		return (NULL);
	cam->sensi = sensibility;
	cam->fov = fov;
	cam->f = SDL_GetCore()->width / (2 * tan(ft_to_rad(fov) / 2.0f));
	set_rect_crd(&cam->screen, 0, 0);
	set_rect_dim(&cam->screen, SDL_GetCore()->width, SDL_GetCore()->height);
	cam->half_scr = cam->screen.w / 2;
	cam->angle = angle;
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
