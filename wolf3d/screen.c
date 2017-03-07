/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:13:40 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/07 21:09:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_screen	*create_screen(int width, int height)
{
	t_screen	*scr;

	if (!(scr = malloc(sizeof(t_screen))) ||
		!(scr->pxl_tab = (Uint32*)malloc(sizeof(Uint32) * width * height)))
		exit_error(NULL);
	scr->height = height;
	scr->width = width;
	scr->texture = SDL_CreateTexture(SDL_GetCore()->renderer,
								SDL_GetWindowPixelFormat(SDL_GetCore()->window),
								SDL_TEXTUREACCESS_STREAMING, width, height);
	ft_memset(scr->pxl_tab, 0, sizeof(Uint32) * width * height);
	SDL_UpdateTexture(scr->texture, NULL, scr->pxl_tab, width * sizeof(Uint32));
	return (scr);
}

void	delete_screen(t_screen *scr)
{
	free(scr->pxl_tab);
	SDL_DestroyTexture(scr->texture);
	free(scr);
}
