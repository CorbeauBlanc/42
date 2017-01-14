/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:54:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/14 16:48:25 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_map		*new_cell(t_vector *vect)
{
	t_map	*cell;
	if (!(cell = malloc(sizeof(t_map))))
		return (NULL);
	cell->vector = vect;
	cell->down = NULL;
	cell->left = NULL;
	cell->right = NULL;
	cell->up = NULL;
	return (cell);
}

void		insert_cell(t_map **head, t_map *cell)
{
	if (!head)
	{
		*head = cell;
		cell->head = cell;
	}
	else
	{
		if (!(*head)->right)
		{
			(*head)->right = cell;
			cell->left = (*head);
			if ((*head)->up && (*head)->up->right)
			{
				cell->up = (*head)->up->right;
				(*head)->up->right->down = cell;
			}
		}
		else
		{
			(*head)->down = cell;
			cell->up = (*head);
			(*head) = cell;
		}
		cell->head = (*head)->head;
	}
}
