/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/01 15:33:00 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "fdf.h"

void	exit_main(void)
{
	mlx_destroy_window(mlx_get_core()->co, mlx_get_core()->win);
	garbage_collector(CLEAR, NULL, NULL);
	exit(0);
}

void	create_events(t_key_evt **head, t_mlx_core *core)
{
	mlx_do_key_autorepeaton(core->co);
	new_key_evt(head, K_Z, &translate_up);
	new_key_evt(head, K_Q, &translate_left);
	new_key_evt(head, K_S, &translate_down);
	new_key_evt(head, K_D, &translate_right);
	new_key_evt(head, K_I, &zoom_in);
	new_key_evt(head, K_O, &zoom_out);
	new_key_evt(head, K_UP, &rotate_up);
	new_key_evt(head, K_LEFT, &rotate_left);
	new_key_evt(head, K_DOWN, &rotate_down);
	new_key_evt(head, K_RIGHT, &rotate_right);
	garbage_collector(ADD, head, &clear_key_evts);
	mlx_key_hook(core->win, &key_hook, *head);
}

void	init_map(t_map *map, int ac, char **av)
{
	int			s_xy;
	int			s_z;
	t_matrix	*tmp;

	s_xy = ac > 2 ? ft_atoi(av[2]) : SCALE_XY;
	s_z = ac > 3 ? ft_atoi(av[3]) : SCALE_Z;
	tmp = create_identity(4);
	scale(&tmp, s_xy, s_xy, s_z);
	translation(&tmp, -10, -10, 0);
	transform_map(map, tmp);
	delete_matrix(tmp);
}

int		main(int ac, char **av)
{
	t_map		*map;
	t_camera	*cam;
	t_mlx_core	*core;
	t_key_evt	*events;

	if (ac < 2 || !(map = read_file(open(av[1], O_RDONLY))))
		return (1);
	garbage_collector(ADD, map, &delete_map);
	init_map(map, ac, av);
	cam = new_camera(90, 90, 0, 300);
	garbage_collector(ADD, cam, &delete_camera);
	core = mlx_get_core();
	events = init_key_evts(K_ECHAP, &exit_main, cam, map);
	create_events(&events, core);
	projection(map, cam);
	mlx_loop(core->co);
	exit_main();
	return (0);
}
