/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:43:59 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/18 19:29:30 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"

t_map	*add_new_cell(t_map *last, t_file_crds *crd, char *nb, t_map **r_head)
{
	t_map	*tmp;

	tmp = insert_cell(last, new_cell(create_vector((++crd->x), crd->y,
													ft_atoi(nb))));
	if (!tmp->vect->z)
		tmp->vect->z = 1;
	if (!last || (last && last->right != tmp))
		*r_head = tmp;
	if (nb[(int)crd->len] == '\n')
	{
		tmp = (*r_head);
		crd->x = -1;
		++crd->y;
	}
	crd->len = 0;
	ft_memset(nb, '*', ft_strlen(nb));
	return (tmp);
}

t_map	*read_file(char *path)
{
	t_file_crds	coords;
	char		*nb;
	t_map		*r_head;
	t_map		*last;

	if (!(coords.fd = open(path, O_RDONLY)))
		return (NULL);
	coords.len = 0;
	nb = ft_strnew(1);
	r_head = NULL;
	last = NULL;
	coords.x = -1;
	coords.y = 0;
	while (read(coords.fd, &nb[coords.len], 1) > 0)
	{
		if (ft_isspace(nb[coords.len]) && coords.len &&
			ft_isdigit(nb[coords.len - 1]))
			last = add_new_cell(last, &coords, nb, &r_head);
		else if (!nb[coords.len + 1])
			nb = ft_strrealloc(nb, ++coords.len + 1);
		else
			++coords.len;
	}
	return (last->head);
}

int		is_in_window(t_vector *vect)
{
	return (vect->x > 0 && vect->x < WIDTH && vect->y > 0 && vect->y < HEIGHT);
}
