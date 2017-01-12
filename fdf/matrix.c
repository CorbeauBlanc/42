/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:14:48 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/12 13:17:58 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*create_matrix(int *mat, int m, int n)
{
	t_matrix	*matrix;

	if (!(matrix = malloc(sizeof(t_matrix))))
		return (NULL);
	matrix->m = m;
	matrix->n = n;
	if (!mat)
	{
		if (!(matrix->mat = (int*)malloc(m * sizeof(int*))) ||
			!(*(matrix->mat) = (int)malloc(n * sizeof(int))))
		{
			free(matrix);
			return (NULL);
		}
	}
}

t_vector	*create_vector(int x, int y, int z)
{
	t_vector	*vect;

	if (!(vect = malloc(sizeof(t_vector))))
		return (NULL);
	vect->x = x;
	vect->y = y;
	vect->z = z;
	return (vect);
}
