/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:26:01 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 17:31:22 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_DATA_H
# define OBJECTS_DATA_H
# include "structures.h"

t_type	data_new_box(t_scene *scene, char *data);
t_type	data_new_cone(t_scene *scene, char *data);
t_type	data_new_cylinder(t_scene *scene, char *data);
t_type	data_new_plane(t_scene *scene, char *data);
t_type	data_new_sphere(t_scene *scene, char *data);
t_type	data_obj_return(t_object *obj, t_scene *scene, t_object **tmp);
void	data_rotate_obj(t_object *tmp, char *data);
void	data_scale_obj(t_object *tmp, char *data);
void	data_transform_obj(t_object *tmp, char *data, t_sc_data *type,
							void (*trans)(t_object *, char *));
void	data_translate_obj(t_object *tmp, char *data);
void	set_object_data(t_object *tmp, char *data, t_sc_data *type);

#endif
