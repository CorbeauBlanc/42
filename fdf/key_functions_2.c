/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/25 20:27:34 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_left(t_camera *cam, t_map *map)
{
	(void)map;
	set_camera_crd(cam, cam->phi, cam->theta - 1, cam->r);
}

void	rotate_right(t_camera *cam, t_map *map)
{
	(void)map;
	set_camera_crd(cam, cam->phi, cam->theta + 1, cam->r);
}

void	rotate_up(t_camera *cam, t_map *map)
{
	(void)map;
	set_camera_crd(cam, cam->phi + 1, cam->theta, cam->r);
}

void	rotate_down(t_camera *cam, t_map *map)
{
	(void)map;
	set_camera_crd(cam, cam->phi - 1, cam->theta, cam->r);
}
