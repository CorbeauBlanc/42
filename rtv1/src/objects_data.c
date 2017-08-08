/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:46:45 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/08 20:16:56 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		data_rotate_obj(t_object *tmp, char *data)
{
	if (data == ft_strstr(data, "x:"))
		rotate_object(tmp, data_get_val(data), 0, 0);
	else if (data == ft_strstr(data, "y:"))
		rotate_object(tmp, 0, data_get_val(data), 0);
	else if (data == ft_strstr(data, "z:"))
		rotate_object(tmp, 0, 0, data_get_val(data));
}

static void		data_translate_obj(t_object *tmp, char *data)
{
	if (data == ft_strstr(data, "x:"))
		translate_object(tmp, data_get_val(data), 0, 0);
	else if (data == ft_strstr(data, "y:"))
		translate_object(tmp, 0, data_get_val(data), 0);
	else if (data == ft_strstr(data, "z:"))
		translate_object(tmp, 0, 0, data_get_val(data));
}

static void		data_scale_obj(t_object *tmp, char *data)
{
	if (data == ft_strstr(data, "x:"))
		scale_object(tmp, data_get_val(data), 1, 1);
	else if (data == ft_strstr(data, "y:"))
		scale_object(tmp, 1, data_get_val(data), 1);
	else if (data == ft_strstr(data, "z:"))
		scale_object(tmp, 1, 1, data_get_val(data));
}

static void	data_transform_obj(t_object *tmp, char *data, t_sc_data *type,
								void (*trans)(t_object *, char *))
{
	if (*data != '\t')
		*type = VOID;
	else
		trans(tmp, data + 1);
}

static void	set_object_data(t_object *tmp, char *data, t_sc_data *type)
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

static t_type	data_obj_return(t_object *obj, t_scene *scene, t_object **tmp)
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

static t_type	data_new_cone(t_scene *scene, char *data)
{
	static t_cone		*tmp = NULL;
	static t_sc_data	type = VOID;

	if (!tmp)
		tmp = new_cone((t_dot){0, 0, 0, 0}, 0, 0, -1);
	if (*data != '\t')
		return (data_obj_return((t_object*)new_cone(tmp->center, tmp->angle,
													tmp->radius, tmp->height),
								scene, (t_object**)&tmp));
	if (type == COORDS)
		type = data_get_crd(&tmp->center, data + 1);
	set_object_data((t_object*)tmp, data, &type);
	if (!type)
	{
		if (data == ft_strstr(data, "\tcoordinates:"))
			type = COORDS;
		else if (data == ft_strstr(data, "\theight:"))
			tmp->height = data_get_val(data);
		else if (data == ft_strstr(data, "\tangle:"))
			tmp->angle = data_get_val(data);
		else if (data == ft_strstr(data, "\tradius:"))
			tmp->radius = data_get_val(data);
	}
	return (CONE);
}

static t_type	data_new_box(t_scene *scene, char *data)
{
	static t_box		*tmp = NULL;
	static t_sc_data	type = VOID;

	if (!tmp)
		tmp = new_box((t_dot){0, 0, 0, 0}, 0, 0, 0);
	if (*data != '\t')
		return (data_obj_return((t_object*)new_box(tmp->fbl_corner,
					tmp->btr_corner.x, tmp->btr_corner.y, tmp->btr_corner.z),
								scene, (t_object**)&tmp));
	if (type == COORDS)
		type = data_get_crd(&tmp->fbl_corner, data + 1);
	set_object_data((t_object*)tmp, data, &type);
	if (!type)
	{
		if (data == ft_strstr(data, "\tcoordinates:"))
			type = COORDS;
		else if (data == ft_strstr(data, "\twidth:"))
			tmp->btr_corner.x = data_get_val(data);
		else if (data == ft_strstr(data, "\theight:"))
			tmp->btr_corner.y = data_get_val(data);
		else if (data == ft_strstr(data, "\tdepth:"))
			tmp->btr_corner.z = data_get_val(data);
	}
	return (BOX);
}

static t_type	data_new_plane(t_scene *scene, char *data)
{
	static t_plane		*tmp = NULL;
	static t_sc_data	type = VOID;

	if (!tmp)
		tmp = new_plane((t_dot){0, 0, 0, 0}, 0, 0);
	if (*data != '\t')
		return (data_obj_return((t_object*)new_plane(tmp->pos, tmp->a, tmp->b),
								scene, (t_object**)&tmp));
	if (type == COORDS)
		type = data_get_crd(&tmp->pos, data + 1);
	set_object_data((t_object*)tmp, data, &type);
	if (!type)
	{
		if (data == ft_strstr(data, "\tcoordinates:"))
			type = COORDS;
		else if (data == ft_strstr(data, "\tfront angle:"))
			tmp->a = data_get_val(data);
		else if (data == ft_strstr(data, "\tside angle:"))
			tmp->b = data_get_val(data);
	}
	return (PLANE);
}

static t_type	data_new_cylinder(t_scene *scene, char *data)
{
	static t_cylinder	*tmp = NULL;
	static t_sc_data	type = VOID;

	if (!tmp)
		tmp = new_cylinder((t_dot){0, 0, 0, 0}, 0, 0);
	if (*data != '\t')
		return (data_obj_return((t_object*)new_cylinder(tmp->center,
													tmp->radius, tmp->height),
								scene, (t_object**)&tmp));
	if (type == COORDS)
		type = data_get_crd(&tmp->center, data + 1);
	set_object_data((t_object*)tmp, data, &type);
	if (!type)
	{
		if (data == ft_strstr(data, "\tcoordinates:"))
			type = COORDS;
		else if (data == ft_strstr(data, "\theight:"))
			tmp->height = data_get_val(data);
		else if (data == ft_strstr(data, "\tradius:"))
			tmp->radius = data_get_val(data);
	}
	return (CYLINDER);
}

static t_type	data_new_sphere(t_scene *scene, char *data)
{
	static t_sphere		*tmp = NULL;
	static t_sc_data	type = VOID;

	if (!tmp)
		tmp = new_sphere((t_dot){0, 0, 0, 0}, 0);
	if (*data != '\t')
		return (data_obj_return((t_object*)new_sphere(tmp->center, tmp->radius),
								scene, (t_object**)&tmp));
	if (type == COORDS)
		type = data_get_crd(&tmp->center, data + 1);
	set_object_data((t_object*)tmp, data, &type);
	if (!type)
	{
		if (data == ft_strstr(data, "\tcoordinates:"))
			type = COORDS;
		else if (data == ft_strstr(data, "\tradius:"))
			tmp->radius = data_get_val(data);
	}
	return (SPHERE);
}

t_sc_data		add_object_data(t_scene *scene, char *data)
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
	{
		if (data == ft_strstr(data, "cone:"))
			type = CONE;
		else if (data == ft_strstr(data, "box:"))
			type = BOX;
		else if (data == ft_strstr(data, "cylinder:"))
			type = CYLINDER;
		else if (data == ft_strstr(data, "plane:"))
			type = PLANE;
		else if (data == ft_strstr(data, "sphere:"))
			type = SPHERE;
	}
	return (OBJECT);
}
