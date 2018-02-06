/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:33:36 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/23 21:26:14 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_orientation	get_vert_side(double angle)
{
	return (is_west(angle) ? EAST : WEST);
}

t_orientation	get_horiz_side(double angle)
{
	return (is_north(angle) ? SOUTH : NORTH);
}
