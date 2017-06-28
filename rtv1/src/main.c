/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/28 18:01:03 by edescoin         ###   ########.fr       */
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
	t_dot	dot = {0,0,0,0};

	test.cam = new_camera(60, &dot, 0, 0);
	test.light.crd = (t_dot){5, 30, 10, 0};
	scene_add_object((t_object*)new_plane((t_dot){0, -5, 30, 0}, -10, 20), &test);
	scene_add_object((t_object*)new_sphere(0, 5, 20, 3), &test);
	scene_add_object((t_object*)new_sphere(0, 1, 19.5, 2), &test);
	render_scene(&test);

	wait_events(events);
	exit_main();
	return (0);
}
