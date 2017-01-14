/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:19:18 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/14 11:48:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_matrix	*translation(double x, double y, double z)
{
	t_matrix	*mtx;

	mtx = create_identity(4);
	mtx->mat[0][3] = x;
	mtx->mat[1][3] = y;
	mtx->mat[2][3] = z;
	return (mtx);
}

t_matrix	*scale(double x, double y, double z)
{
	t_matrix	*mtx;

	mtx = create_identity(4);
	mtx->mat[0][0] = x;
	mtx->mat[1][1] = y;
	mtx->mat[2][2] = z;
	return (mtx);
}

t_matrix	*x_rotation(double theta)
{
	t_matrix	*mtx;

	theta = M_PI * (theta / 180);
	mtx = create_identity(4);
	mtx->mat[1][1] = cos(theta);
	mtx->mat[1][2] = -sin(theta);
	mtx->mat[2][1] = sin(theta);
	mtx->mat[2][1] = cos(theta);
	return (mtx);
}

t_matrix	*y_rotation(double theta)
{
	t_matrix	*mtx;

	theta = M_PI * (theta / 180);
	mtx = create_identity(4);
	mtx->mat[0][0] = cos(theta);
	mtx->mat[0][2] = sin(theta);
	mtx->mat[2][0] = -sin(theta);
	mtx->mat[2][2] = cos(theta);
	return (mtx);
}

t_matrix	*z_rotation(double theta)
{
	t_matrix	*mtx;

	theta = M_PI * (theta / 180);
	mtx = create_identity(4);
	mtx->mat[0][0] = cos(theta);
	mtx->mat[0][1] = -sin(theta);
	mtx->mat[1][0] = sin(theta);
	mtx->mat[1][1] = cos(theta);
	return (mtx);
}
