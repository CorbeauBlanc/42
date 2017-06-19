/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 12:56:49 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/19 15:52:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	render_scene(t_scene *scene)
{
	int	i;
	int	j;
	t_ray	ray;
	t_vector vd;
	t_cell *tmp;
	double	t;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			set_vector(&vd, scene->cam.screen[i][j]->x - scene->cam.crd.x,
						scene->cam.screen[i][j]->y - scene->cam.crd.y,
						scene->cam.screen[i][j]->z - scene->cam.crd.z);
			init_equation(&ray.eq, &vd, (t_vector*)&scene->cam.crd);
			tmp = scene->collection;
			while (tmp)
			{
				if ((t = tmp->obj->intersect(tmp->obj, &ray)) > -1)
					printf("%d", (int)t);
				else
					printf(" ");
				tmp = tmp->next;
			}
		}
		printf("\n");
	}
}
