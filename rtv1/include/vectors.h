/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:57:05 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/19 15:31:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H
# include "structures.h"

/*
** dots.c
*/
void		mult_dot(t_dot *dest, t_matrix *mtx, t_dot *dot);
t_dot		*new_dot(double x, double y, double z);
void		set_dot(t_dot *dot, double x, double y, double z);

/*
** vectors.c
*/
t_vector	*new_vector(double x, double y, double z);
void		set_vector(t_vector *vect, double x, double y, double z);

#endif
