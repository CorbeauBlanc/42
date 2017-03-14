/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:56:36 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/14 13:03:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map	*goto_tile(t_vector *crd, t_map *tile)
{
	while (tile && (crd->x > tile->max.x || crd->x < tile->min.x ||
			crd->y > tile->max.y || crd->y < tile->min.y))
	{
		if (crd->x > tile->max.x)
			tile = tile->right;
		else if ((crd->x < tile->min.x))
			tile = tile->left;
		if (tile && crd->y > tile->max.y)
			tile = tile->down;
		else if (tile && crd->y < tile->min.y)
			tile = tile->up;
	}
	return (tile);
}

int		is_empty(t_map *tile)
{
	return (tile && tile->type == FLOOR);
}
