/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:43:59 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/14 18:31:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

void	add_new_cell(t_map ***tmp, t_file_crds *crd, char **nb, t_map **r_head)
{
	insert_cell(*tmp, new_cell(create_vector(++crd->x, crd->y, ft_atoi(*nb))));
	if (*nb[(int)crd->len] == '\n')
	{
		*tmp = &(*r_head);
		*r_head = (*r_head)->down;
		crd->x = -1;
		++crd->y;
	}
	crd->len = 0;
	ft_memset(*nb, '\0', ft_strlen(*nb));
}

t_map	*read_file(char *path)
{
	t_file_crds	coords;
	char		*nb;
	t_map		*r_head;
	t_map		**tmp;

	if (!(coords.fd = open(path, O_RDONLY)))
		return (NULL);
	coords.len = 0;
	nb = ft_strnew(1);
	r_head = NULL;
	tmp = &r_head;
	coords.x = -1;
	coords.y = 0;
	while (read(coords.fd, &nb[coords.len], 1) > 0)
	{
		if (ft_isspace(nb[coords.len]))
			add_new_cell(&tmp, &coords, &nb, &r_head);
		else
			nb = ft_strrealloc(nb, ++coords.len + 1);
	}
	return (r_head->head);
}
