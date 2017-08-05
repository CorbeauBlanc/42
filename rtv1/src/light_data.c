/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:33:26 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/05 13:46:25 by edescoin         ###   ########.fr       */
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

t_sc_data	get_light_crd(t_scene *scene, char *data)
{
	if (*data != '\t')
		return (VOID);
	if (data == ft_strstr(data, "\tx:"))
		scene->light->crd.x = data_get_val(data);
	else if (data == ft_strstr(data, "\ty:"))
		scene->light->crd.y = data_get_val(data);
	else if (data == ft_strstr(data, "\tz:"))
		scene->light->crd.z = data_get_val(data);
	return (COORDS);
}

void		get_light_powa(t_scene *scene, char *data)
{
	scene->light->power = data_get_val(data);
}

t_sc_data	add_light_data(t_scene *scene, char *data)
{
	static t_sc_data	type = VOID;

	if (*data != '\t')
		return (VOID);
	if (type == COORDS)
		type = get_light_crd(scene, data + 1);
	if (!type)
	{
		if (data == ft_strstr(data, "\tcoordinates:"))
			type = COORDS;
		else if (data == ft_strstr(data, "\tpower:"))
			get_light_powa(scene, data);
	}
	return (LIGHT);
}
