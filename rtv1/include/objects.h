/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:47:13 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/11 19:27:17 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "structures.h"

/*
** cone.c
*/
t_cone		*new_cone(t_dot pos, double angle, double radius, double height);

/*
** cylinder.c
*/
t_cylinder	*new_cylinder(t_dot pos, double radius, double height);

/*
** objects.c
*/
void		delete_object(t_object *obj);
t_object	*new_object(t_type type, double (*intersect)(),
						const t_vector *(*get_normal)(),
						size_t size);
void		rotate_object(t_object *obj, double x_angle, double y_angle, double z_angle);

/*
** plane.c
*/
t_plane		*new_plane(t_dot pos, double x_angle, double z_angle);

/*
** sphere.c
*/
t_sphere	*new_sphere(double x, double y, double z, double radius);
void		delete_sphere(t_sphere *s);

#endif
