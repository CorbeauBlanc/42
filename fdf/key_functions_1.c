/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/02 13:24:03 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_left(t_camera *cam, t_map *map)
{
	t_matrix	*tmp;

	(void)cam;
	tmp = create_identity(4);
	translation(&tmp, cam->r / SCALE_XY, 0, 0);
	transform_map(map, tmp);
	delete_matrix(tmp);
}

void	translate_right(t_camera *cam, t_map *map)
{
	t_matrix	*tmp;

	(void)cam;
	tmp = create_identity(4);
	translation(&tmp, -cam->r / SCALE_XY, 0, 0);
	transform_map(map, tmp);
	delete_matrix(tmp);
}

void	translate_up(t_camera *cam, t_map *map)
{
	t_matrix	*tmp;

	(void)cam;
	tmp = create_identity(4);
	translation(&tmp, 0, cam->r / SCALE_XY, 0);
	transform_map(map, tmp);
	delete_matrix(tmp);
}

void	translate_down(t_camera *cam, t_map *map)
{
	t_matrix	*tmp;

	(void)cam;
	tmp = create_identity(4);
	translation(&tmp, 0, -cam->r / SCALE_XY, 0);
	transform_map(map, tmp);
	delete_matrix(tmp);
}
