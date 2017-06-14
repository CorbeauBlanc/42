/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:54:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/14 16:33:34 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_dot	*new_dot(double x, double y, double z)
{
	t_dot	*dot;

	dot = (t_dot*)new_vector(x, y, z);
	dot->w = 1;
	return (dot);
}
/*
void	transform_dot(t_dot *dest, t_dot *vect, t_camera *cam)
{
	double	tmp;

	tmp = vect->z;
	mult_dot(dest, cam->view, vect);
	dest->x = (WIDTH / 2) + (cam->f * dest->x) / dest->z;
	dest->y = (HEIGHT / 2) + (cam->f * dest->y) / dest->z;
	dest->w = tmp;
}
*/
void	mult_dot(t_dot *dest, t_matrix *mtx, t_dot *dot)
{
	int	x;
	int	y;
	int	z;

	if (mtx->r >= 3 || mtx->c >= 4)
	{
		x = mtx->mat[0][0] * dot->x + mtx->mat[0][1] * dot->y +
				mtx->mat[0][2] * dot->z + mtx->mat[0][3];
		y = mtx->mat[1][0] * dot->x + mtx->mat[1][1] * dot->y +
				mtx->mat[1][2] * dot->z + mtx->mat[1][3];
		z = mtx->mat[2][0] * dot->x + mtx->mat[2][1] * dot->y +
				mtx->mat[2][2] * dot->z + mtx->mat[2][3];
		dest->x = x;
		dest->y = y;
		dest->z = z;
	}
}

void	set_dot(t_dot *dot, double x, double y, double z)
{
	dot->x = x;
	dot->y = y;
	dot->z = z;
}
