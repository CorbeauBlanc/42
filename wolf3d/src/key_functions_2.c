/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/03 18:11:24 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	rotate_left(t_player *player)
{
	if (player->cam->angle + player->cam->sensi > 180)
		player->cam->angle = ((player->cam->angle + player->cam->sensi) - 180) -
							180;
	else
		player->cam->angle += player->cam->sensi;
	return (1);
}

int	rotate_right(t_player *player)
{
	if (player->cam->angle - player->cam->sensi < -180)
		player->cam->angle = ((player->cam->angle - player->cam->sensi) + 180) +
							180;
	else
		player->cam->angle -= player->cam->sensi;
	return (1);
}

int	toggle_fullscreen(t_player *player)
{
	t_sdl_core		*core;
	static Uint32	ticks = 0;

	if (SDL_GetTicks() < ticks + 2000)
		return (1);
	else
		ticks = SDL_GetTicks();
	core = get_sdl_core();
	SDL_LockMutex(get_mutexes()->environment);
	core->fullscreen = !core->fullscreen;
	SDL_ShowCursor(!core->fullscreen);
	if (core->fullscreen)
		SDL_SetWindowFullscreen(core->window, SDL_WINDOW_FULLSCREEN);
	else
		SDL_SetWindowFullscreen(core->window, 0);
	SDL_GetWindowSize(core->window, &core->width, &core->height);
	player->cam->half_scr = core->height / 2;
	set_rect_dim(&player->cam->screen, core->width, core->height);
	set_camera_bobbing(player->cam, BOBBING);
	set_camera_fov(player->cam, player->cam->fov);
	SDL_UnlockMutex(get_mutexes()->environment);
	return (1);
}
