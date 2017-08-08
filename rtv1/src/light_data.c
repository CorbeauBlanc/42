/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:33:26 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/08 20:06:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		data_get_val(char *data)
{
	double	val;
	double	val_floor;
	char	*tmp;

	val = ft_atoi(ft_strchr(data, ':') + 1);
	if ((tmp = ft_strchr(data, '.')))
		val_floor = ft_atoi(tmp + 1);
	else
		val_floor = 0;
	return (val + val_floor / (10 * ft_intlen(val_floor)));
}

t_sc_data	data_get_crd(t_dot *crd, char *data)
{
	if (*data != '\t')
		return (VOID);
	if (data == ft_strstr(data, "\tx:"))
		crd->x = data_get_val(data);
	else if (data == ft_strstr(data, "\ty:"))
		crd->y = data_get_val(data);
	else if (data == ft_strstr(data, "\tz:"))
		crd->z = data_get_val(data);
	return (COORDS);
}

t_sc_data	add_light_data(t_scene *scene, char *data)
{
	static t_sc_data	type = VOID;

	if (*data != '\t')
		return (VOID);
	if (type == COORDS)
		type = data_get_crd(&scene->light->crd, data + 1);
	if (!type)
	{
		if (data == ft_strstr(data, "\tcoordinates:"))
			type = COORDS;
		else if (data == ft_strstr(data, "\tpower:"))
			scene->light->power = data_get_val(data);
	}
	return (LIGHT);
}
