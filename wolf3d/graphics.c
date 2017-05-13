/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:52:28 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/14 00:27:33 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_SDL_Core	*SDL_GetCore(void)
{
	static t_SDL_Core	*core = NULL;

	if (core)
		return (core);
	if (!(core = malloc(sizeof(t_SDL_Core))))
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
	return (core);
}

void		SDL_DestroyCore()
{
	SDL_DestroyWindow(SDL_GetCore()->window);
	SDL_DestroyRenderer(SDL_GetCore()->renderer);
	SDL_Quit();
	free(SDL_GetCore());
}

void		refresh_win()
{
	SDL_RenderPresent(SDL_GetCore()->renderer);
}

Uint32		get_color(int r, int g, int b)
{
	return (SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(SDL_GetCore()->window)),
			r, g, b));
}

Uint8		get_filter_value(t_map_data *data, double dist)
{
	int val;

	if ((val = 255 - data->brightness * dist) < 0)
		return (0);
	return (val);
}
