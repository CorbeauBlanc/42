/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_angles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:54:16 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/03 19:20:31 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	is_looking_left(t_camera *cam)
{
	return ((cam->angle < 0 && cam->angle >= -45) ||
			(cam->angle >= 0 && cam->angle > 135));
}

int	is_looking_right(t_camera *cam)
{
	return ((cam->angle >= 0 && cam->angle <= 45) ||
			(cam->angle < 0 && cam->angle < -135));
}

int	is_looking_up(t_camera *cam)
{
	return (cam->angle > 45 && cam->angle <= 135);
}

int	is_looking_down(t_camera *cam)
{
	return (cam->angle < -45 && cam->angle >= -135);
}
