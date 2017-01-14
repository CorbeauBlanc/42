/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:43:59 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/14 16:48:54 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

void	add_new_cell(t_map ***tmp, t_vector *crd, char **nb, t_map **r_head)
{
	insert_cell(*tmp, new_cell(create_vector(++crd->x, crd->y, ft_atoi(*nb))));
	if (*nb[(int)crd->w] == '\n')
	{
		*tmp = &(*r_head);
		*r_head = (*r_head)->down;
		crd->x = -1;
		++crd->y;
	}
	crd->w = 0;
	free(*nb);
	*nb = ft_strnew(1);
}

t_map	*read_file(char *path)
{
	int			fd;
	t_vector	coord;
	char		*nb;
	t_map		*r_head;
	t_map		**tmp;

	if (!(fd = open(path, O_RDONLY)))
		return (NULL);
	coord.w = 0;
	nb = ft_strnew(1);
	r_head = NULL;
	tmp = &r_head;
	coord.x = -1;
	coord.y = 0;
	while (read(fd, &nb[(int)coord.w], 1) > 0)
	{
		if (ft_isspace(nb[(int)coord.w]))
			add_new_cell(&tmp, &coord, &nb, &r_head);
		else
			nb = ft_strrealloc(nb, ++coord.w + 1);
	}
	return (r_head->head);
}
