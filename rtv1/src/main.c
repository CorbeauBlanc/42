/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/05 13:54:18 by edescoin         ###   ########.fr       */
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

	t_scene	*test;
	t_cylinder	*c;
	t_cone		*c2;

/*
	test = new_scene(new_spotlight((t_dot){20, 15, 10, 0}, 1),
					//new_camera(FOV, &(t_dot){0,0,0,0}, 0, 0),
					new_camera(60, &(t_dot){10,30,-20,0}, -20, 30),
					5, (SDL_Color){0,0,0,0});
*/
	test = get_scene("scene.sc");
	delete_camera(test->cam);
	test->cam = new_camera(60, &(t_dot){10,30,-20,0}, -20, 30);

	garbage_collector(ADD, test, delete_scene);

	scene_add_object((t_object*)new_plane((t_dot){-50, 10, 30, 0}, -20, -10), test);
	scene_add_object((t_object*)new_sphere(0, 5, 20, 3), test);
	scene_add_object((t_object*)new_sphere(0, 1, 19.5, 2), test);
	c = new_cylinder((t_dot){-5, 5, 15, 0}, 3, 20);
	set_object_color((t_object*)c, 255, 0, 0);
	rotate_object((t_object*)c, 30, 0, 15);
	c2 = new_cone((t_dot){-2, 3, 20, 0}, 20, 5, -1);
	set_object_color((t_object*)c2, 0, 0, 255);
	rotate_object((t_object*)c2, 30, 0, 180);
	scene_add_object((t_object*)c, test);
	scene_add_object((t_object*)c2, test);

	render_scene(test);

	wait_events(events);
	exit_main();
	return (0);
}
