/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/09 17:06:36 by edescoin         ###   ########.fr       */
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

void	init_list_evts(t_event **head, char *path)
{
	new_event(head, SDL_KEYUP, path, &key_management);
	new_event(head, SDL_QUIT, NULL, &force_exit);
}

int		main(int ac, char **av)
{
	t_event	*events;

	events = NULL;
	if (ac != 2)
		exit_custom_error("usage: ", "rtv1 <scene>\n");
	init_list_evts(&events, av[1]);
	render_scene(garbage_collector(ADD, get_scene(av[1]), delete_scene));
	wait_events(events);
	exit_main();
	return (0);
}
