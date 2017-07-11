/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/11 17:25:13 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_main(void)
{
	garbage_collector(CLEAR, NULL, NULL);
	delete_sdl_core();
	exit(0);
}

int		exit_loop(void)
{
	return (0);
}

void	init_list_evts(t_event **head)
{
	new_event(head, SDL_KEYUP, NULL, &key_exit);
	new_event(head, SDL_QUIT, NULL, &exit_loop);
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_event	*events = NULL;

	get_sdl_core();
	init_list_evts(&events);

	t_scene	test;
	test.collection = NULL;

	test.cam = new_camera(60, &(t_dot){10,10,-5,0}, -20, 20);
	test.light.crd = (t_dot){20, 15, 10, 0};
	scene_add_object((t_object*)new_plane((t_dot){0, -6, 30, 0}, -10, 0), &test);
	scene_add_object((t_object*)new_sphere(0, 5, 20, 3), &test);
	scene_add_object((t_object*)new_sphere(0, 1, 19.5, 2), &test);
	scene_add_object((t_object*)new_cylinder((t_dot){-2, 3, 20, 0}, 20, 10, 3, 10), &test);
	render_scene(&test);

	wait_events(events);
	exit_main();
	return (0);
}

/*
** l'équation simplifiée du cylindre T_T
** t²((cos(theta) * dy - sin(theta) * dx)² + (cos(phi)(sin(theta) * dy + dz) - cos(theta)sin(phi) * dx)²) + t * 2((cos(theta) * dy - sin(theta) * dx) * (cos(theta) * cy - sin(theta) * cx) + (cos(phi)(sin(theta) * dy + dz) - cos(theta)sin(phi) * dx) * (cos(phi)(sin(theta) * cy + cz) - cos(theta)sin(phi) * cx)) + (cos(theta) * cy - sin(theta) * cx)² + (cos(phi)(sin(theta) * cy + cz) - cos(theta)sin(phi) * cx)² - R² = 0
*/
