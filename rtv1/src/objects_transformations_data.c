/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_transformations_data.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:17:48 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 18:12:35 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "objects_data.h"

void	data_rotate_obj(t_object *tmp, char *data)
{
	if (data == ft_strstr(data, "x:"))
		rotate_object(tmp, data_get_val(data), 0, 0);
	else if (data == ft_strstr(data, "y:"))
		rotate_object(tmp, 0, data_get_val(data), 0);
	else if (data == ft_strstr(data, "z:"))
		rotate_object(tmp, 0, 0, data_get_val(data));
}

void	data_translate_obj(t_object *tmp, char *data)
{
	if (data == ft_strstr(data, "x:"))
		translate_object(tmp, data_get_val(data), 0, 0);
	else if (data == ft_strstr(data, "y:"))
		translate_object(tmp, 0, data_get_val(data), 0);
	else if (data == ft_strstr(data, "z:"))
		translate_object(tmp, 0, 0, data_get_val(data));
}

void	data_scale_obj(t_object *tmp, char *data)
{
	if (data == ft_strstr(data, "x:"))
		scale_object(tmp, data_get_val(data), 1, 1);
	else if (data == ft_strstr(data, "y:"))
		scale_object(tmp, 1, data_get_val(data), 1);
	else if (data == ft_strstr(data, "z:"))
		scale_object(tmp, 1, 1, data_get_val(data));
}

void	data_transform_obj(t_object *tmp, char *data, t_sc_data *type,
								void (*trans)(t_object *, char *))
{
	if (*data != '\t')
		*type = VOID;
	else
		trans(tmp, data + 1);
}
