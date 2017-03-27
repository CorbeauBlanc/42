/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:13:40 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/27 23:39:38 by edescoin         ###   ########.fr       */
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
								SDL_TEXTUREACCESS_STATIC, width, height);
	ft_memset(scr->pxl_tab, 0, sizeof(Uint32) * width * height);
	scr->pitch = width * sizeof(Uint32);
	SDL_UpdateTexture(scr->texture, NULL, scr->pxl_tab, scr->pitch);
	return (scr);
}

void		delete_screen(t_screen *scr)
{
	free(scr->pxl_tab);
	SDL_DestroyTexture(scr->texture);
	free(scr);
}

void		put_pxl_screen(t_screen *scr, int x, int y, Uint32 color)
{
	if (x < scr->width && y < scr->height && x >= 0 && y >= 0)
		scr->pxl_tab[y * scr->width + x] = color;
}

void		clear_screen(t_screen *scr)
{
	ft_memset(scr->pxl_tab, 0, sizeof(Uint32) * scr->width * scr->height);
}
