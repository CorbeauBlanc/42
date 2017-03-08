/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:12:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/08 17:48:42 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_camera	*create_camera(int fov, int angle)
{
	t_camera	*cam;

	if (!(cam = malloc(sizeof(t_camera))))
		return (NULL);
	cam->fov = fov;
	cam->half_fov = fov / 2;
	cam->f = HEIGHT / (2 * tan(ft_to_rad(fov) / 2.0f));
	cam->screen = create_screen(SDL_GetCore()->width, SDL_GetCore()->height);
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
	cam->f = HEIGHT / (2 * tan(ft_to_rad(cam->fov) / 2.0f));
	cam->half_fov = fov / 2;
}

void		refresh_cam(t_camera *cam)
{
	SDL_UpdateTexture(cam->screen->texture, NULL, cam->screen->pxl_tab,
					cam->screen->pitch);
	SDL_RenderCopy(SDL_GetCore()->renderer, cam->screen->texture, NULL, NULL);
	refresh_win();
}
