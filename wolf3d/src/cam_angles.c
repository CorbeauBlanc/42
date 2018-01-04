/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_angles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:54:16 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/22 19:00:04 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	is_looking_left(double angle)
{
	return ((angle < 0 && angle >= -45) ||
			(angle >= 0 && angle > 135));
}

int	is_looking_right(double angle)
{
	return ((angle >= 0 && angle <= 45) ||
			(angle < 0 && angle < -135));
}

int	is_looking_up(double angle)
{
	return (angle > 45 && angle <= 135);
}

int	is_looking_down(double angle)
{
	return (angle < -45 && angle >= -135);
}
