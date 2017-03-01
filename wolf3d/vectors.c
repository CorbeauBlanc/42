/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:54:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/01 17:20:56 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

t_map		*new_cell(t_vector *vect, t_tile type)
{
	t_map	*cell;

	if (!(cell = malloc(sizeof(t_map))))
		return (NULL);
	cell->min.x = vect->x;
	cell->min.y = vect->y;
	cell->max.x = vect->x + WALL_SIZE;
	cell->max.y = vect->y + WALL_SIZE;
	cell->type = type;
	cell->down = NULL;
	cell->left = NULL;
	cell->right = NULL;
	cell->up = NULL;
	cell->r_head = NULL;
	cell->c_head = NULL;
	return (cell);
}

t_map		*insert_cell(t_map *head, t_map *cell)
{
	if (head)
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
			cell->up = head;
			head->down = cell;
		}
	}
	cell->c_head = cell->up ? cell->up->c_head : cell;
	cell->r_head = cell->left ? cell->left->r_head : cell;
	return (cell);
}
