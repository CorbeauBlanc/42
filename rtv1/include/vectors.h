/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:57:05 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/29 16:46:48 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H
# include "structures.h"

/*
** dots.c
*/
double		get_dot_dist(t_dot *d1, t_dot *d2);
void		mult_dot(t_dot *dest, t_matrix *mtx, t_dot *dot);
t_dot		*new_dot(double x, double y, double z);
void		set_dot(t_dot *dot, double x, double y, double z);

/*
** vectors.c
*/
double		get_vect_norm(t_vector *vect);
t_vector	*new_vector(double x, double y, double z);
void		set_vector(t_vector *vect, double x, double y, double z);

#endif
