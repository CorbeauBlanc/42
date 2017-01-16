/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/16 20:58:42 by edescoin         ###   ########.fr       */
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

double		to_deg(double rad)
{
	return (rad * (180.0 / M_PI));
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_camera	*cam;
	t_mlx_core	*core;
	t_matrix	*tmp;

	if (ac != 2 || !(map = read_file(av[1])))
		return (1);
	transform_map(map, (tmp = scale(50, 50, 1)));
	free(tmp);
	core = get_mlx_core();
	cam = new_camera(90);

	projection(cam, map);
	mlx_loop(core->co);
	return (0);
}
