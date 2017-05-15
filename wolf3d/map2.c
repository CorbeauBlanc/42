/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:14:17 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/16 00:15:46 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

t_map_data	*get_map_data(int fd)
{
	t_map_data	*data;
	char		buff[1024];
	int			nb_data;
	int			cur_pos;

	if (!(data = malloc(sizeof(t_map_data))))
		exit_error(NULL);
	data->bgd = NULL;
	nb_data = 1;
	nb_data += get_map_brightness(data, fd, buff);
	nb_data += get_map_reflection(data, fd, buff);
	nb_data += get_map_background(data, fd, buff);
	nb_data += get_map_floor(data, fd, buff);
	cur_pos = 0;
	while (--nb_data)
		cur_pos += ft_strclen(&buff[cur_pos], '\n') + 1;
	lseek(fd, cur_pos, SEEK_SET);
	return (data);
}
