/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/11 17:08:33 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	key_management(SDL_Event *current, t_event *evt)
{
	t_evt_data	*data;

	data = evt->data;
	if (current->key.keysym.sym == SDLK_ESCAPE)
		return (0);
	else if (current->key.keysym.sym == SDLK_r)
	{
		garbage_collector(CLEAR, NULL, NULL);
		data->scene = garbage_collector(ADD, get_scene(data->path),
										delete_scene);
		data->mouse_clic = 0;
		render_scene(data->scene);
	}
	else if (current->key.keysym.sym == SDLK_F5)
	{
		data->scene->cam->resolution = 1;
		init_cam_screen(data->scene->cam);
		render_scene(data->scene);
	}
	else if (current->key.keysym.sym == SDLK_UP ||
			current->key.keysym.sym == SDLK_DOWN)
	{
		if (current->key.keysym.sym == SDLK_UP &&
			data->scene->cam->low_resolution > 1)
			data->scene->cam->low_resolution--;
		else if (current->key.keysym.sym == SDLK_DOWN)
			data->scene->cam->low_resolution++;
		data->scene->cam->resolution = data->scene->cam->low_resolution;
		init_cam_screen(data->scene->cam);
		render_scene(data->scene);
	}
	return (1);
}
