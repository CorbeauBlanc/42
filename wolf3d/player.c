/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:33:13 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/25 17:11:09 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

t_player	*create_player(t_camera *cam)
{
	t_player	*player;

	if (!(player = malloc(sizeof(t_player))))
		exit_error("wolf3d : ", "malloc");
	player->cam = cam;
	player->tile = NULL;
	player->last_mvt_nb = 0;
	return (player);
}

t_player	*get_player()
{
	static t_player	*player = NULL;

	if (!player)
		player = create_player(create_camera(60, 0, 60, 1.5));
	return (player);
}

void		delete_player()
{
	SDL_LockMutex(get_mutexes()->environment);
	get_player()->cam->state = STOP;
	SDL_UnlockMutex(get_mutexes()->environment);
	SDL_WaitThread(get_player()->cam->refresh_cam, NULL);
	delete_camera(get_player()->cam);
	free(get_player());
}

static int	cam_thread(void *arg)
{
	t_player		*player;
	t_thread_state	state;
	int				ms;

	(void)arg;
	player = get_player();
	SDL_LockMutex(get_mutexes()->environment);
	state = get_player()->cam->state;
	ms = 1000 / player->cam->fps;
	SDL_UnlockMutex(get_mutexes()->environment);
	while (state != STOP)
	{
		SDL_LockMutex(get_mutexes()->environment);
		if (state == RUN)
			scan_environment(player);
		state = player->cam->state;
		SDL_UnlockMutex(get_mutexes()->environment);
		SDL_Delay(ms);
	}
	return (1);
}

void		insert_player(t_map *map, double x, double y)
{
	t_player	*player;

	player = get_player();
	if (map)
	{
		player->pos.x = x;
		player->pos.y = y;
		if (!(player->tile = goto_tile(&player->pos, map)))
			exit_custom_error("wolf3d : ", "error : player out of map");
		player->cam->state = PAUSE;
		player->cam->refresh_cam = SDL_CreateThread(&cam_thread, "Cam thread",
													NULL);
	}
}
