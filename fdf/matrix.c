/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:14:48 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/12 14:11:34 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*create_matrix(int **mat, int r, int c)
{
	t_matrix	*matrix;

	if (!(matrix = malloc(sizeof(t_matrix))))
		return (NULL);
	matrix->r = r;
	matrix->c = c;
	if (!mat)
	{
		if (!(matrix->mat = (int**)malloc(r * sizeof(int*))) ||
			!(*(matrix->mat) = (int*)malloc(c * sizeof(int))))
		{
			free(matrix);
			return (NULL);
		}
	}
	else
		matrix->mat = mat;
	return (matrix);
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
				mult->mat[r][c] += m1->mat[r][i] + m2->mat[i][c];
		}
	}
	return (mult);
}
