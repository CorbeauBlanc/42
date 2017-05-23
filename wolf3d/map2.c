/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:14:17 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/23 21:26:11 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		is_empty(t_map *tile)
{
	return (tile && tile->type <= FLOOR);
}

void		check_player(t_map *map)
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

void			set_map_brightness(t_map_data *data, int percent)
{
	double	max;

	if (percent < 0)
		percent = 0;
	else if (percent > 100)
		percent = 100;
	else
		percent = 100 - percent;
	max = 255 / WALL_SIZE;
	data->brightness = max * percent / 100.0;
}

t_map_data	*get_map_data(int fd, char *path)
{
	t_map_data	*data;
	char		buff[1024];
	int			nb_data;
	int			cur_pos;

	if (!(data = malloc(sizeof(t_map_data))))
		exit_error("wolf3d : ", "malloc");
	data->bgd = NULL;
	data->path = path;
	nb_data = 1;
	nb_data += get_map_brightness(data, fd, buff);
	nb_data += get_map_reflection(data, fd, buff);
	nb_data += get_map_background(data, fd, buff);
	nb_data += get_map_floor(data, fd, buff);
	nb_data += get_map_ceiling(data, fd, buff);
	cur_pos = 0;
	while (--nb_data)
		cur_pos += ft_strclen(&buff[cur_pos], '\n') + 1;
	lseek(fd, cur_pos, SEEK_SET);
	return (data);
}

char	*get_data(const char *str, char *buff, int fd)
{
	char	*n;
	int		nb;

	if ((nb = read(fd, buff, 1024)) > 0)
	{
		lseek(fd, 0, SEEK_SET);
		buff[1023] = '\0';
		if (!(buff = ft_strstr(buff, str)))
			return (NULL);
		buff += ft_strlen(str) + 1;
		while (*buff && (*buff == ':' || ft_isspace(*buff)))
			++buff;
		if ((n = ft_strchr(buff, '\n')))
		 	*n = '\0';
		return (buff);
	}
	else if (nb < 0)
		exit_error("wolf3d : ", "read");
	return (NULL);
}
