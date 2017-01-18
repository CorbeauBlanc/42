/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/18 21:48:01 by edescoin         ###   ########.fr       */
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
	return (deg * (M_PI / 180.0f));
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
	scale(&tmp, 20, 20, 20);
	translation(&tmp, -160, -340, 0);
	transform_map(map, tmp);
	delete_matrix(&tmp);

	cam = new_camera(90, 70, 90, 300);

	core = get_mlx_core();
	projection(cam, map);
	mlx_loop(core->co);
	return (0);
}
