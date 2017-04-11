/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/11 22:13:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>

void	exit_error(char *s)
{
	if (!s)
	{
		perror("wolf3d");
		exit(1);
	}
	ft_putstr_fd(s, 2);
	exit(1);
}

void	exit_main()
{
	garbage_collector(CLEAR, NULL, NULL);
	SDL_DestroyCore();
	delete_mutexes();
	delete_player();
	exit(0);
}

int		exit_loop()
{
	return (0);
}

void	init_list_evts(t_event **head)
{
	new_event(head, SDL_SCANCODE_ESCAPE, &exit_loop);
	new_event(head, SDL_SCANCODE_LEFT, &rotate_left);
	new_event(head, SDL_SCANCODE_RIGHT, &rotate_right);
	new_event(head, SDL_SCANCODE_W, &move_up);
	new_event(head, SDL_SCANCODE_S, &move_down);
	new_event(head, SDL_SCANCODE_A, &move_left);
	new_event(head, SDL_SCANCODE_D, &move_right);
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_event		*list_evts;
	t_map		*map;

	map = read_file(open("test", O_RDONLY));
	set_map_brightness(map, 80);
	insert_player(map, 84, 70);

	list_evts = NULL;
	init_list_evts(&list_evts);

	scan_environment(get_player());

	wait_events(list_evts, get_player());
	clear_events(&list_evts);
	exit_main();
	return (0);
}
