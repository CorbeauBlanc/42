/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/24 15:49:50 by edescoin         ###   ########.fr       */
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
	SDL_DestroyWindow(SDL_GetCore()->window);
	SDL_DestroyRenderer(SDL_GetCore()->renderer);
	SDL_Quit();
	garbage_collector(CLEAR, NULL, NULL);
	exit(0);
}

int		exit_loop()
{
	return (0);
}

void	init_list_evts(t_event **head, t_player *player)
{
	new_event(head, SDL_QUIT, NULL, &exit_loop);
	new_event(head, SDL_KEYDOWN, new_key_data(SDLK_ESCAPE, &exit_loop, NULL), &key_hook);
	new_event(head, SDL_KEYDOWN, new_key_data(SDLK_LEFT, &rotate_left, player), &key_hook);
	new_event(head, SDL_KEYDOWN, new_key_data(SDLK_RIGHT, &rotate_right, player), &key_hook);
	new_event(head, SDL_KEYDOWN, new_key_data(SDLK_z, &move_up, player), &key_hook);
	new_event(head, SDL_KEYDOWN, new_key_data(SDLK_q, &move_left, player), &key_hook);
	new_event(head, SDL_KEYDOWN, new_key_data(SDLK_s, &move_down, player), &key_hook);
	new_event(head, SDL_KEYDOWN, new_key_data(SDLK_d, &move_right, player), &key_hook);
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_event		*list_evts;
	t_player	*player;
	t_map		*map;

	SDL_GetCore();

	map = read_file(open("test", O_RDONLY));
	player = create_player(create_camera(70, 45), 40, 40, map);

	list_evts = NULL;
	init_list_evts(&list_evts, player);

	scan_environment(player);

	wait_events(list_evts);
	clear_events(&list_evts);
	exit_main();
	return (0);
}
