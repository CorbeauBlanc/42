/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:27:54 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/12 13:02:17 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static t_tile	get_type(int i)
{
	t_tile	types[2];

	types[0] = FLOOR;
	types[1] = WALL;
	return (types[(i < 2 && i > -1) ? i : 0]);
}

void		add_new_cells(t_map **last, t_vector *crd, char *nbs, t_map_data *d)
{
	while (*nbs)
	{
		while (*nbs == '\n')
		{
			if (*last && *(nbs - 1) != '\n')
			{
				*last = (*last)->r_head;
				crd->y += WALL_SIZE;
				crd->x = 0;
			}
			++nbs;
		}
		if (*nbs)
		{
			*last = insert_cell(*last, new_cell(crd, get_type(*nbs - '0'), d));
			insert_mob(*last, nbs);
			crd->x += WALL_SIZE;
			++nbs;
		}
	}
}

void		set_map_brightness(t_map *map, int percent)
{
	double	max;

	percent = 100 - percent;
	max = 255 / WALL_SIZE;
	map->data->brightness = max * percent / 100.0;
}

void		delete_map(t_map *map)
{
	t_map	*r_head;
	t_map	*tmp;

	delete_texture(map->data->bgd);
	free(map->data);
	while (map)
	{
		r_head = map->down;
		while (map)
		{
			tmp = map;
			map = map->right;
			delete_cell(tmp);
		}
		map = r_head;
	}
}

t_map		*read_file(int fd)
{
	t_vector	crds;
	char		*nbs;
	t_map		*last;
	t_map_data	*data;

	if (fd < 0)
		return (NULL);
	nbs = ft_strnew(BUFF_SIZE);
	last = NULL;
	crds.x = 0;
	crds.y = 0;
	if (!(data = malloc(sizeof(t_map_data))))
		exit_error(NULL);
	data->bgd = create_texture("background.bmp");
	while (read(fd, nbs, BUFF_SIZE) > 0)
	{
		add_new_cells(&last, &crds, nbs, data);
		ft_bzero(nbs, BUFF_SIZE);
	}
	free(nbs);
	if (!last)
		return (NULL);
	garbage_collector(ADD, last->r_head->c_head, &delete_map);
	return (last->r_head->c_head);
}
