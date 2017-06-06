/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:42 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 17:22:47 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include "structures.h"

/*
** matrix.c
*/
void		clear_matrix(t_matrix *mat);
t_matrix	*create_identity(int i);
t_matrix	*create_matrix(double **mat, int r, int c);
void		delete_matrix(t_matrix *matrix);
t_matrix	*mult_matrix(t_matrix *m1, t_matrix *m2);

/*
** transformations.c
*/
void		translation(t_matrix **mtx, double x, double y, double z);
void		x_rotation(t_matrix **mtx, double theta);
void		y_rotation(t_matrix **mtx, double theta);
void		z_rotation(t_matrix **mtx, double theta);
void		scale(t_matrix **mtx, double x, double y, double z);

/*
** vectors.c
*/
t_vector	*create_vector(double x, double y, double z);
void		mult_vector(t_vector *dest, t_matrix *mtx, t_vector *vec);
void		transform_vector(t_vector *dest, t_vector *vect, t_camera *cam);

#endif