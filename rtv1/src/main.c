/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 19:26:03 by edescoin         ###   ########.fr       */
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
	garbage_collector(CLEAR, NULL, NULL);
	exit(1);
	return (0);
}

void	init_list_evts(t_event **head, t_evt_data *data)
{
	new_event(head, SDL_KEYUP, data, &key_management);
	new_event(head, SDL_MOUSEMOTION, data, &motion_management);
	new_event(head, SDL_MOUSEBUTTONDOWN, data, &button_management);
	new_event(head, SDL_MOUSEBUTTONUP, data, &button_management);
	new_event(head, SDL_MOUSEWHEEL, data, &wheel_management);
	new_event(head, SDL_QUIT, NULL, &force_exit);
}

int		main(int ac, char **av)
{
	t_event		*events;
	t_evt_data	data;

	events = NULL;
	if (ac != 2)
		exit_custom_error("usage: ", "rtv1 <scene>\n");
	data = (t_evt_data){av[1], garbage_collector(ADD, get_scene(av[1]),
			delete_scene), 0};
	init_list_evts(&events, &data);
	render_scene(data.scene);
	wait_events(events);
	exit_main();
	return (0);
}
