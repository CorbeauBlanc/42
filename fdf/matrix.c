/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:14:48 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/16 17:17:21 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*create_matrix(double **mat, int r, int c)
{
	t_matrix	*matrix;
	int			i;
	int			j;

	if (!(matrix = malloc(sizeof(t_matrix))))
		return (NULL);
	matrix->r = r;
	matrix->c = c;
	if (!mat)
	{
		if (!(matrix->mat = (double**)malloc(r * sizeof(double*))))
			return_free(NULL, matrix);
		i = -1;
		while (++i < r)
		{
			if (!(matrix->mat[i] = (double*)malloc(c * sizeof(double))))
				return_free(NULL, matrix);
			j = -1;
			while (++j < c)
				matrix->mat[i][j] = 0;
		}
	}
	else
		matrix->mat = mat;
	return (matrix);
}

t_matrix	*create_identity(int i)
{
	t_matrix	*mtx;

	mtx = create_matrix(NULL, i, i);
	i = -1;
	while (++i < mtx->c)
		mtx->mat[i][i] = 1;
	return (mtx);
}

void		delete_matrix(t_matrix **matrix)
{
	int	r;

	r = -1;
	while (++r < (*matrix)->r)
		free((*matrix)->mat[r]);
	free((*matrix)->mat);
	free(*matrix);
	*matrix = NULL;
}

t_matrix	*mult_matrix(t_matrix *m1, t_matrix *m2)
{
	t_matrix	*mult;
	int			r;
	int			c;
	int			i;

	if (m1->c != m2->r)
		return (NULL);
	mult = create_matrix(NULL, m1->r, m2->c);
	r = -1;
	while (++r < mult->r)
	{
		c = -1;
		while (++c < mult->c)
		{
			i = -1;
			mult->mat[r][c] = 0;
			while (++i < m1->c)
				mult->mat[r][c] += m1->mat[r][i] * m2->mat[i][c];
		}
	}
	return (mult);
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
