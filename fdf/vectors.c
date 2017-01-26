/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:54:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/26 16:42:20 by edescoin         ###   ########.fr       */
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
	mult_vector(dest, cam->view, vect);
	dest->x = (WIDTH / 2) + (cam->f * dest->x) / dest->z;
	dest->y = (HEIGHT / 2) + (cam->f * dest->y) / dest->z;
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
	cell->r_head = NULL;
	cell->c_head = NULL;
	return (cell);
}

t_map		*insert_cell(t_map *head, t_map *cell)
{

	if (head && !(head->right))
	{
		head->right = cell;
		cell->left = head;
		if (head->up && head->up->right)
		{
			cell->up = head->up->right;
			head->up->right->down = cell;
		}
	}
	else if (head)
	{
		cell->up = head;
		head->down = cell;
	}
	cell->c_head = cell->up ? cell->up->c_head : cell;
	cell->r_head = cell->left ? cell->left->r_head : cell;
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