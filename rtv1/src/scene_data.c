/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 13:28:50 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/02 17:52:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		data_get_color(SDL_Color *col, char *data)
{
	if (data == ft_strstr(data, "r:"))
		col->r = ft_atoi(ft_strchr(data, ':') + 1);
	else if (data == ft_strstr(data, "g:"))
		col->g = ft_atoi(ft_strchr(data, ':') + 1);
	else if (data == ft_strstr(data, "b:"))
		col->b = ft_atoi(ft_strchr(data, ':') + 1);
}

t_sc_data	get_scene_bg(t_scene *scene, char *data)
{
	if (*data != '\t')
		return (0);
	data_get_color(&scene->bgcolor, data + 1);
	return (BACKGROUND);
}

void		get_scene_bts(t_scene *scene, char *data)
{
	int	bts;

	bts = ft_atoi(ft_strchr(data, ':') + 1);
	if (bts < 0)
		bts = 0;
	scene->brightness = bts / 100;
}

t_sc_data	add_env_data(t_scene *scene, char *data)
{
	static t_sc_data	type = VOID;

	if (*data != '\t')
		return (0);
	if (type == BACKGROUND)
		type = get_scene_bg(scene, data + 1);
	if (!type)
	{
		if (data == ft_strstr(data, "\tbackground:"))
			type = BACKGROUND;
		if (data == ft_strstr(data, "\tbrightness:"))
			get_scene_bts(scene, data);
	}
	return (ENVIRONMENT);
}
