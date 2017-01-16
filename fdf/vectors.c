/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:54:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/16 20:12:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_vector	*create_vector(double x, double y, double z)
{
	t_vector	*vect;

	if (!(vect = malloc(sizeof(t_vector))))
		return (NULL);
	vect->x = x;
	vect->y = y;
	vect->z = z;
	vect->w = 1;
	return (vect);
}

void		transform_vector(t_vector *dest, t_vector *vect, double d)
{
	dest->x = (vect->x * d) / (vect->z ? vect->z : 1);
	dest->y = (vect->y * d) / (vect->z ? vect->z : 1);
	dest->z = vect->z;
}

t_map		*new_cell(t_vector *vect)
{
	t_map	*cell;
	if (!(cell = malloc(sizeof(t_map))))
		return (NULL);
	cell->vect = vect;
	cell->down = NULL;
	cell->left = NULL;
	cell->right = NULL;
	cell->up = NULL;
	cell->head = NULL;
	return (cell);
}

t_map		*insert_cell(t_map *head, t_map *cell)
{
	if (!head)
		cell->head = cell;
	else
	{
		if (!(head->right))
		{
			head->right = cell;
			cell->left = head;
			if (head->up && head->up->right)
			{
				cell->up = head->up->right;
				head->up->right->down = cell;
			}
		}
		else
		{
			head->down = cell;
			cell->up = head;
		}
		cell->head = head->head;
	}
	return (cell);
}
