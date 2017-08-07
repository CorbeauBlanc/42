/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:46:45 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/07 22:25:57 by edescoin         ###   ########.fr       */
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

static t_type	data_new_cone(t_scene *scene, char *data)
{
	static t_cone		*tmp = NULL;
	static t_sc_data	type = VOID;

	if (!tmp)
		tmp = new_cone((t_dot){0, 0, 0, 0}, 0, 0, 0);
	if (type == COORDS)
		type = data_get_crd(&tmp->center, data + 1);
	else if (type == COLOR)
		type = data_get_color(&tmp->color, data + 1);

}

t_sc_data		add_object_data(t_scene *scene, char *data)
{
	static t_type	type = NONE;

	if (*data != '\t')
		return (VOID);
	if (type == CONE)
		type = data_get_crd(&scene->cam->crd, data + 1);
	if (!type)
	{
		if (data == ft_strstr(data, "\tcoordinates:"))
			type = COORDS;
		else if (data == ft_strstr(data, "\tfov:"))
			set_camera_fov(scene->cam, ft_atoi(ft_strchr(data, ':') + 1));
		else if (data == ft_strstr(data, "\thorizontal angle:"))
			scene->cam->theta = data_get_val(data);
		else if (data == ft_strstr(data, "\tvertical angle:"))
			scene->cam->phi = data_get_val(data);
	}
	return (OBJECT);
}
