/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_types_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:46:45 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 19:53:45 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "objects_data.h"

t_type	data_new_cone(t_scene *scene, char *data)
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

t_type	data_new_box(t_scene *scene, char *data)
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

t_type	data_new_plane(t_scene *scene, char *data)
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

t_type	data_new_cylinder(t_scene *scene, char *data)
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

t_type	data_new_sphere(t_scene *scene, char *data)
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
