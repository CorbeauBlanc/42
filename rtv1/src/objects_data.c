/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:46:45 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 18:12:45 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "objects_data.h"

void		set_object_data(t_object *tmp, char *data, t_sc_data *type)
{
	if (*type == COLOR)
		*type = data_get_color(&tmp->color, data + 1);
	else if (*type == ROTATION)
		data_transform_obj(tmp, data + 1, type, &data_rotate_obj);
	else if (*type == TRANSLATION)
		data_transform_obj(tmp, data + 1, type, &data_translate_obj);
	else if (*type == SCALE)
		data_transform_obj(tmp, data + 1, type, &data_scale_obj);
	if (!*type)
	{
		if (data == ft_strstr(data, "\tcolor:"))
		{
			set_object_color(tmp, 0, 0, 0);
			*type = COLOR;
		}
		else if (data == ft_strstr(data, "\trotation:"))
			*type = ROTATION;
		else if (data == ft_strstr(data, "\ttranslation:"))
			*type = TRANSLATION;
		else if (data == ft_strstr(data, "\tscale:"))
			*type = SCALE;
	}
}

t_type		data_obj_return(t_object *obj, t_scene *scene, t_object **tmp)
{
	t_matrix	*tmp_mat;

	obj->rot = (*tmp)->rot;
	(*tmp)->rot = NULL;
	obj->rot_inv = (*tmp)->rot_inv;
	(*tmp)->rot_inv = NULL;
	tmp_mat = obj->trans;
	obj->trans = mult_matrix(obj->trans, (*tmp)->trans);
	delete_matrix(tmp_mat);
	tmp_mat = obj->trans_inv;
	obj->trans_inv = mult_matrix(obj->trans_inv, (*tmp)->trans_inv);
	delete_matrix(tmp_mat);
	obj->scale = (*tmp)->scale;
	(*tmp)->scale = NULL;
	obj->scale_inv = (*tmp)->scale_inv;
	(*tmp)->scale_inv = NULL;
	set_object_color(obj, (*tmp)->color.r, (*tmp)->color.g, (*tmp)->color.b);
	delete_object((*tmp));
	*tmp = NULL;
	scene_add_object(obj, scene);
	return (NONE);
}

static void	nottypenorm(t_type *type, char *data)
{
	if (data == ft_strstr(data, "cone:"))
		*type = CONE;
	else if (data == ft_strstr(data, "box:"))
		*type = BOX;
	else if (data == ft_strstr(data, "cylinder:"))
		*type = CYLINDER;
	else if (data == ft_strstr(data, "plane:"))
		*type = PLANE;
	else if (data == ft_strstr(data, "sphere:"))
		*type = SPHERE;
}

t_sc_data	add_object_data(t_scene *scene, char *data)
{
	static t_type	type = NONE;

	if (type == BOX)
		type = data_new_box(scene, data);
	else if (type == CONE)
		type = data_new_cone(scene, data);
	else if (type == CYLINDER)
		type = data_new_cylinder(scene, data);
	else if (type == PLANE)
		type = data_new_plane(scene, data);
	else if (type == SPHERE)
		type = data_new_sphere(scene, data);
	if (!type)
		nottypenorm(&type, data);
	return (OBJECT);
}
