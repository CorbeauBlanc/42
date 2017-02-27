/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:52:28 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/27 20:43:12 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Window	*SDL_GetMainWindow(void)
{
	static SDL_Window	*win = NULL;

	if (!win)
	{
		if (SDL_Init(SDL_VIDEO_DRIVER_COCOA))
		{
			fprintf(stderr, "Échec de l'initialisation de la SDL : %s\n",
					SDL_GetError());
			return (NULL);
		}
		win = SDL_CreateWindow(TITLE,
							SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (!win)
			fprintf(stderr,
				"Échec de la création de la fenêtre principale : %s\n",
				SDL_GetError());
	}
	return (win);
}
