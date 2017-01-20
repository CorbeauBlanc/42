/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:43:59 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/20 14:00:36 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "fdf.h"

char	*add_new_cells(t_map **last, t_vector *crd, char *nbs)
{
	char	*tmp;

	while (nbs && nbs + 1)
	{
		while (nbs && ft_isspace(*nbs))
			++nbs;
		if ((tmp = ft_strspc(nbs)))
		{
			*last = insert_cell(*last, new_cell(create_vector((++crd->x), crd->y,
															ft_atoi(nbs))));
			nbs = tmp;
			if (*nbs == '\n')
			{
				*last = (*last)->r_head;
				++crd->y;
				crd->x = -1;
			}
		}
		else
			return (nbs);
	}
	return (NULL);
}

t_map	*read_file(char *path)
{
	t_vector	crds;
	char		*nbs;
	char		*tmp;
	int			len;
	int			fd;
	t_map		*last;

	if (!(fd = open(path, O_RDONLY)))
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
	return (last->r_head->c_head);
}

int		is_in_window(t_vector *vect)
{
	return (vect->x > 0 && vect->x < WIDTH && vect->y > 0 && vect->y < HEIGHT);
}

double	dabs(double f)
{
	return (f < 0 ? -f : f);
}

double		to_rad(int deg)
{
	return (deg * (M_PI / 180.0f));
}
