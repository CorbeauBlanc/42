/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 21:02:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/24 19:20:13 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

int			get_map_brightness(t_map_data *data, int fd, char *buff)
{
	char	*tmp;

	if ((tmp = get_data("brightness", buff, fd)))
		set_map_brightness(data, ft_atoi(tmp) % 256);
	else
		set_map_brightness(data, 100);
	return (tmp != NULL);
}

int			get_map_background(t_map_data *data, int fd, char *buff)
{
	char	*tmp;

	if (!(tmp = get_data("background", buff, fd)) || ft_strequ(tmp, "none"))
		data->bgd = NULL;
	else
	{
		data->bgd = create_texture(get_data_path(data->path, tmp));
		if (data->reflection)
			SDL_SetTextureBlendMode(data->bgd->text, SDL_BLENDMODE_BLEND);
		data->bg_fact = data->bgd->w / 360;
	}
	return (tmp != NULL);
}

int			get_map_reflection(t_map_data *data, int fd, char *buff)
{
	char	*tmp;

	if (!(tmp = get_data("reflections", buff, fd)) ||
		!(tmp = ft_strstr(tmp, "true")))
		data->reflection = 0;
	else
	{
		tmp = ft_strchr(tmp, ',');
		data->reflection = tmp ? (ft_atoi(tmp + 1) % 256) : 255;
	}
	return (tmp != NULL);
}

int			get_map_floor(t_map_data *data, int fd, char *buff)
{
	char		*tmp;

	if (!(tmp = get_data("floor", buff, fd)) || ft_strequ(tmp, "none"))
	{
		data->floor.r = 0;
		data->floor.g = 0;
		data->floor.b = 0;
		data->floor.a = data->bgd ? 0 : 255;
	}
	else
	{
		data->floor.r = ft_atoi(tmp);
		tmp = ft_strchr(tmp, ',');
		data->floor.g = tmp ? ft_atoi(++tmp) % 256 : 0;
		tmp = ft_strchr(tmp, ',');
		data->floor.b = tmp ? ft_atoi(++tmp) % 256 : 0;
		data->floor.a = 255;
	}
	return (tmp != NULL);
}

int			get_map_ceiling(t_map_data *data, int fd, char *buff)
{
	char		*tmp;

	if (!(tmp = get_data("ceiling", buff, fd)) || ft_strequ(tmp, "none"))
	{
		data->ceiling.r = 0;
		data->ceiling.g = 0;
		data->ceiling.b = 0;
	}
	else
	{
		data->ceiling.r = ft_atoi(tmp);
		tmp = ft_strchr(tmp, ',');
		data->ceiling.g = tmp ? ft_atoi(++tmp) % 256 : 0;
		tmp = ft_strchr(tmp, ',');
		data->ceiling.b = tmp ? ft_atoi(++tmp) % 256 : 0;
	}
	data->ceiling.a = data->bgd ? 0 : 255;
	return (tmp != NULL);
}
