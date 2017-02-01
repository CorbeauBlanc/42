/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:27:54 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/02 00:00:03 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

char	*add_new_cells(t_map **last, t_vector *crd, char *nbs)
{
	char	*tmp;

	while (*nbs && *(nbs + 1))
	{
		while (*nbs && *nbs != '\n' && ft_isspace(*nbs))
			++nbs;
		if (*nbs == '\n')
		{
			*last = (*last)->r_head;
			++crd->y;
			crd->x = -1;
			++nbs;
		}
		if ((tmp = ft_strspc(nbs)))
		{
			*last = insert_cell(*last, new_cell(create_vector((++crd->x),
															crd->y,
															ft_atoi(nbs))));
			nbs = tmp;
		}
		else if (*nbs)
			return (nbs);
	}
	return (NULL);
}

void	set_min_max(t_map *map, double min, double max)
{
	while (map)
	{
		map->highest = max;
		map->lowest = min;
		if (map->right)
			map = map->right;
		else
			map = map->r_head->down;
	}
}

t_map	*read_file(int fd)
{
	t_vector	crds;
	char		*nbs;
	char		*tmp;
	int			len;
	t_map		*last;

	if (fd < 0)
		return (NULL);
	nbs = ft_strnew(BUFF_SIZE);
	last = NULL;
	crds.x = -1;
	crds.y = 0;
	len = 0;
	while (read(fd, nbs + len, BUFF_SIZE - len) > 0)
	{
		tmp = add_new_cells(&last, &crds, nbs);
		len = ft_strlen(tmp);
		ft_strncpy(nbs, tmp, len);
		ft_memset(nbs + len, '\0', BUFF_SIZE - len);
	}
	free(nbs);
	set_min_max(last->r_head->c_head, last->lowest, last->highest);
	return (last->r_head->c_head);
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
			free(map->left->vect);
			free(map->left);
		}
		free(map->vect);
		free(map);
		map = r_head;
	}
}
