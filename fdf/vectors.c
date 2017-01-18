/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:54:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/18 19:50:27 by edescoin         ###   ########.fr       */
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

void		transform_vector(t_vector *dest, t_vector *vect, t_camera *cam)
{
	mult_vector(dest, cam->proj, vect);
	dest->x = 250 + (cam->f * dest->x) / dest->z;
	dest->y = 250 + (cam->f * dest->y) / dest->z;
	dest->z = 0;
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

void		mult_vector(t_vector *dest, t_matrix *mtx, t_vector *vec)
{
	int	x;
	int	y;
	int	z;

	if (mtx->r >= 3 || mtx->c >= 4)
	{
		x = mtx->mat[0][0] * vec->x + mtx->mat[0][1] * vec->y +
				mtx->mat[0][2] * vec->z + mtx->mat[0][3];
		y = mtx->mat[1][0] * vec->x + mtx->mat[1][1] * vec->y +
				mtx->mat[1][2] * vec->z + mtx->mat[1][3];
		z = mtx->mat[2][0] * vec->x + mtx->mat[2][1] * vec->y +
				mtx->mat[2][2] * vec->z + mtx->mat[2][3];
		dest->x = x;
		dest->y = y;
		dest->z = z;
	}
}
