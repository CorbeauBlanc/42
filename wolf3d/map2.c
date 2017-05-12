/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:14:17 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/10 19:30:14 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	check_player(t_map *map)
{
	if (!get_player()->tile)
	{
		map->r_head->c_head->type = FLOOR;
		insert_player(map, WALL_SIZE / 2, WALL_SIZE / 2);
	}
	SDL_LockMutex(get_mutexes()->environment);
	get_player()->cam->state = RUN;
	SDL_UnlockMutex(get_mutexes()->environment);
}

static char	*get_data(const char *str, char *buff, int fd)
{
	char	*n;
	if (read(fd, &buff, 1024) > 0)
	{
		buff[1024] = '\0';
		if (!(buff = ft_strstr(buff, str)))
			return (NULL);
		buff += ft_strlen(str) + 1;
		while (*buff && (*buff == ':' || ft_isspace(*buff)))
			++buff;
		if ((n = ft_strchr(buff, '\n')))
		 	*n = '\0';
		lseek(fd, 0, SEEK_SET);
		return (buff);
	}
	exit_error(NULL);
	return (NULL);
}

t_map_data	*get_map_data(int fd)
{
	t_map_data	*data;
	char		buff[1024];
	char		*tmp;

	if (!(data = malloc(sizeof(t_map_data))))
		exit_error(NULL);
	if ((tmp = get_data("background", &buff, fd)))
		data->bgd = create_texture(tmp);
	else
		data->bgd = NULL;
	if (!(tmp = get_data("reflections", &buff, fd)) ||
		!ft_strequ(tmp, "true"))
		data->reflection = 0;
	else
		data->reflection = 1;

	if ((!(tmp = get_data("floor", &buff, fd)) || ft_strequ(tmp, "false")) &&
		!data->bgd)
	{
		data->floor.r = 0;
		data->floor.g = 0;
		data->floor.b = 0;
		data->floor.a = 255;
	}
	else if (data->bgd)
		data->floor.a = 0;
	
	data->floor.r = 0;
	data->floor.g = 255;
	data->floor.b = 0;
	data->floor.a = 255;
}
