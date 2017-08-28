/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:47:13 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 18:35:16 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "structures.h"

/*
** box.c
*/
t_box		*new_box(t_dot fbl_corner, double x_width, double y_width,
					double z_width);

/*
** cone.c
*/
t_cone		*new_cone(t_dot pos, double angle, double radius, double height);

/*
** cylinder.c
*/
t_cylinder	*new_cylinder(t_dot pos, double radius, double height);

/*
** objects*.c
*/
void		delete_object(t_object *obj);
t_object	*new_object(t_type type, double (*intersect)(),
						const t_vector *(*get_normal)(),
						size_t size);
void		rotate_object(t_object *obj, double x_angle, double y_angle,
						double z_angle);
void		scale_object(t_object *obj, double x, double y, double z);
void		set_object_color(t_object *obj, int r, int g, int b);
void		translate_object(t_object *obj, double x, double y, double z);

/*
** plane.c
*/
int			is_in_plane(t_dot *d, t_plane *p);
t_plane		*new_plane(t_dot pos, double x_angle, double z_angle);

/*
** sphere.c
*/
t_sphere	*new_sphere(t_dot center, double radius);

#endif
