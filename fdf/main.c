/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/17 14:24:07 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <fcntl.h>
#include <math.h>

double	dabs(double f)
{
	return (f < 0 ? -f : f);
}

double		to_rad(int deg)
{
	return (deg * (M_PI / 180.0));
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_camera	*cam;
	t_mlx_core	*core;
	t_matrix	*tmp;

	if (ac != 2 || !(map = read_file(av[1])))
		return (1);
	tmp = create_identity(4);
	scale(&tmp, 10, 10, 1);
	transform_map(map, tmp);
	translation(&tmp, 200, 200, 1);
	transform_map(map, tmp);
	y_rotation(&tmp, 1);
	transform_map(map, tmp);
	delete_matrix(&tmp);
	core = get_mlx_core();
	cam = new_camera(90);

	projection(cam, map);
	mlx_loop(core->co);
	return (0);
}
