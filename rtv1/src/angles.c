/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 20:22:20 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/22 18:59:52 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "math.h"

int	is_north(double angle)
{
	return ((angle > 0 && angle < M_PI) || angle < -M_PI);
}

int	is_south(double angle)
{
	return ((angle < 0 && angle > -M_PI) || angle > M_PI);
}

int	is_east(double angle)
{
	return (fabs(angle) < M_PI_2 || fabs(angle) > (M_PI + M_PI_2));
}

int	is_west(double angle)
{
	return (fabs(angle) > M_PI_2 && fabs(angle) < (M_PI + M_PI_2));
}
