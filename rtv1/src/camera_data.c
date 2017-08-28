/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 13:59:22 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 19:31:20 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sc_data	add_camera_data(t_scene *scene, char *data)
{
	static t_sc_data	type = VOID;

	if (*data != '\t')
		return (VOID);
	if (type == COORDS)
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
	return (CAMERA);
}
