/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/20 13:54:06 by edescoin         ###   ########.fr       */
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
	wait_events(events);
	exit_main();

	/*t_scene	test;
	t_dot	dot = {0,0,0,0};

	test.cam = new_camera(60, &dot, 0, 0);
	scene_add_object((t_object*)new_sphere(0, 0, 100, 10), &test);
	render_scene(&test);*/


	return (0);
}
