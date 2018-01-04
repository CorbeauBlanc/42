/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:52:28 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/03 18:08:05 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_sdl_core	*get_sdl_core(void)
{
	static t_sdl_core	*core = NULL;

	if (core)
		return (core);
	if (!(core = malloc(sizeof(t_sdl_core))))
		return (NULL);
	if (SDL_Init(SDL_VIDEO) ||
		!(core->window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
										SDL_WINDOW_SHOWN)) ||
		!(core->renderer = SDL_CreateRenderer(core->window, -1,
											SDL_RENDERER_ACCELERATED)))
	{
		fprintf(stderr, "Erreur SDL2 : %s\n", SDL_GetError());
		return (NULL);
	}
	core->width = WIDTH;
	core->height = HEIGHT;
	core->fullscreen = 0;
	return (core);
}

void		delete_sdl_core(void)
{
	SDL_DestroyWindow(get_sdl_core()->window);
	SDL_DestroyRenderer(get_sdl_core()->renderer);
	SDL_Quit();
	free(get_sdl_core());
}

void		refresh_win(void)
{
	SDL_RenderPresent(get_sdl_core()->renderer);
}

Uint32		get_color(int r, int g, int b)
{
	return (SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(
										get_sdl_core()->window)),
						r, g, b));
}

Uint8		get_filter_value(t_map_data *data, double dist)
{
	int val;

	if ((val = 255 - data->brightness * dist) < 0)
		return (0);
	return (val);
}
