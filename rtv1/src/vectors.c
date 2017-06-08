/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:54:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 17:50:31 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
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
	double	tmp;

	tmp = vect->z;
	mult_vector(dest, cam->view, vect);
	dest->x = (WIDTH / 2) + (cam->f * dest->x) / dest->z;
	dest->y = (HEIGHT / 2) + (cam->f * dest->y) / dest->z;
	dest->w = tmp;
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
