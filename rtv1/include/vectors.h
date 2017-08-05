/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:57:05 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/05 18:47:32 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H
# include "structures.h"

/*
** dots.c
*/
double		get_dot_dist(t_dot *d1, t_dot *d2);
int			is_dot_between(t_dot *min, t_dot *dot, t_dot *max);
t_dot		*new_dot(double x, double y, double z);
void		set_dot(t_dot *dot, double x, double y, double z);

/*
** vectors.c
*/
double		get_vect_len(const t_vector *vect);
t_vector	*new_vector(double x, double y, double z);
void		set_vector(t_vector *vect, double x, double y, double z);
double		vect_dot_product(const t_vector *v1, const t_vector *v2);

#endif
