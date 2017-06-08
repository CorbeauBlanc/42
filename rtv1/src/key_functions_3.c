/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 17:48:12 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	zoom_in(t_camera *cam, t_map *map)
{
	(void)map;
	set_camera_crd(cam, cam->phi, cam->theta, cam->r - SCALE_XY);
}

void	zoom_out(t_camera *cam, t_map *map)
{
	(void)map;
	set_camera_crd(cam, cam->phi, cam->theta, cam->r + SCALE_XY);
}
