/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:47:13 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/28 14:56:00 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "structures.h"

/*
** objects.c
*/
t_object	*new_object(t_type type, double (*intersect)(), size_t size);

/*
** sphere.c
*/
t_sphere	*new_sphere(double x, double y, double z, double radius);

/*
** plane.c
*/
t_plane		*new_plane(t_dot pos, double x_angle, double z_angle);

#endif
