/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 17:15:57 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

int	button_management(SDL_Event *current, t_event *evt)
{
	t_evt_data	*data;

	data = evt->data;
	if (evt->type == SDL_MOUSEBUTTONUP &&
		data->mouse_clic == current->button.button)
		data->mouse_clic = 0;
	else if (evt->type == SDL_MOUSEBUTTONDOWN && !data->mouse_clic)
	{
		data->mouse_clic = current->button.button;
		data->scene->cam->resolution = data->scene->cam->low_resolution;
	}
	return (1);
}

int	motion_management(SDL_Event *current, t_event *evt)
{
	t_evt_data	*data;

	data = evt->data;
	if (data->mouse_clic == SDL_BUTTON_LEFT)
	{
		data->scene->cam->phi -= current->motion.yrel * MOUSE_ASPEED;
		data->scene->cam->theta -= current->motion.xrel * MOUSE_ASPEED;
		init_cam_screen(data->scene->cam);
		render_scene(data->scene);
	}
	else if (data->mouse_clic == SDL_BUTTON_RIGHT)
	{
		data->scene->cam->crd.y += current->motion.yrel * MOUSE_YSPEED;
		data->scene->cam->crd.x -= cos(ft_to_rad(data->scene->cam->theta)) *
									current->motion.xrel * MOUSE_XSPEED;
		data->scene->cam->crd.z -= sin(ft_to_rad(data->scene->cam->theta)) *
									current->motion.yrel * MOUSE_XSPEED;
		init_cam_screen(data->scene->cam);
		render_scene(data->scene);
	}
	return (1);
}
