/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/21 19:18:42 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

void	exit_main()
{
	mlx_destroy_window(mlx_get_core()->co, mlx_get_core()->win);
	garbage_collector(CLEAR, NULL, NULL);
	exit(0);
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_map		*map;
	t_camera	*cam;
	t_mlx_core	*core;
	t_matrix	*tmp;

	if (ac != 2 || !(map = read_file(av[1])))
		return (1);
	tmp = create_identity(4);
	scale(&tmp, 20, 20, 20);
	translation(&tmp, 3, -13, 0);
	transform_map(map, tmp);
	delete_matrix(tmp);

	cam = new_camera(90, 45, 90, 100);
	garbage_collector(ADD, cam, &delete_camera);

	core = mlx_get_core();

	t_image *test = create_image(1000, 1000, 32);
	garbage_collector(ADD, test, &delete_image);
	projection(test, map, cam);
	t_key_evt *echap = init_key_evts(65307, &exit_main, NULL, NULL);
	mlx_key_hook(core->win, &key_hook, echap);
	mlx_loop(core->co);
	exit_main();
	return (0);
}
