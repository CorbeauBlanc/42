/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/08 19:03:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	exit_main(void)
{
	garbage_collector(CLEAR, NULL, NULL);
	delete_sdl_core();
	exit(0);
}

int		force_exit(void)
{
	exit(1);
	return (0);
}

void	init_list_evts(t_event **head)
{
	new_event(head, SDL_KEYUP, NULL, &key_exit);
	new_event(head, SDL_QUIT, NULL, &force_exit);
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
//	t_cone		*c2;

	test = garbage_collector(ADD, get_scene("scene.sc"), delete_scene);

	scene_add_object((t_object*)new_plane((t_dot){-50, 10, 30, 0}, 20, 10), test);
	scene_add_object((t_object*)new_sphere(0, 5, 20, 3), test);
	t_sphere *s = new_sphere(0, 1, 19.5, 2);
	scale_object((t_object*)s, 1.5, 1, 1);
	scene_add_object((t_object*)s, test);
	c = new_cylinder((t_dot){-5, 5, 15, 0}, 3, 20);
	set_object_color((t_object*)c, 255, 0, 0);
	rotate_object((t_object*)c, 30, 0, 15);
/*	c2 = new_cone((t_dot){-2, 3, 20, 0}, 20, 5, -1);
	set_object_color((t_object*)c2, 0, 0, 255);
	rotate_object((t_object*)c2, 30, 0, 180);*/
	scene_add_object((t_object*)c, test);
//	scene_add_object((t_object*)c2, test);
//	scene_add_object((t_object*)new_box((t_dot){5, 5, 10, 0}, 5, 5, 5), test);

	render_scene(test);

	wait_events(events);
	exit_main();
	return (0);
}
