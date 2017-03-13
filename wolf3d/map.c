/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:27:54 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/13 19:05:26 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map		*goto_tile(t_vector *crd, t_map *tile)
{
	while (tile && (crd->x > tile->max.x || crd->x < tile->min.x ||
			crd->y > tile->max.y || crd->y < tile->min.y))
	{
		if (crd->x > tile->max.x)
			tile = tile->right;
		else if ((crd->x < tile->min.x))
			tile = tile->left;
		if (tile && crd->y > tile->max.y)
			tile = tile->down;
		else if (tile && crd->y < tile->min.y)
			tile = tile->up;
	}
	return (tile);
}

t_tile	get_type(int i)
{
	t_tile	types[2];

	types[0] = FLOOR;
	types[1] = WALL;
	return (types[(i < 2 && i > -1) ? i : 0]);
}

void	add_new_cells(t_map **last, t_vector *crd, char *nbs)
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
			*last = insert_cell(*last, new_cell(crd, get_type(*nbs - '0')));
			crd->x += WALL_SIZE;
			++nbs;
		}
	}
}

t_map	*read_file(int fd)
{
	t_vector	crds;
	char		*nbs;
	t_map		*last;

	if (fd < 0)
		return (NULL);
	nbs = ft_strnew(BUFF_SIZE);
	last = NULL;
	crds.x = 0;
	crds.y = 0;
	while (read(fd, nbs, BUFF_SIZE) > 0)
	{
		add_new_cells(&last, &crds, nbs);
		ft_bzero(nbs, BUFF_SIZE);
	}
	free(nbs);
	return (last ? last->r_head->c_head : NULL);
}

void	delete_map(t_map *map)
{
	t_map	*r_head;

	while (map)
	{
		r_head = map->down;
		while (map->right)
		{
			map = map->right;
			free(map->left);
		}
		free(map);
		map = r_head;
	}
}
