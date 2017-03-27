/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:55:48 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/27 23:10:45 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Texture	*create_texture(char *path)
{
	SDL_Texture	*texture;
	SDL_Surface	*tmp;
	void		*pixels;
	int			pitch;

	if (!(tmp = SDL_LoadBMP(path)))
		exit_error((char*)SDL_GetError());
	if (!(texture = SDL_CreateTexture(SDL_GetCore()->renderer,
					SDL_GetWindowPixelFormat(SDL_GetCore()->window),
					SDL_TEXTUREACCESS_STREAMING, WALL_SIZE, WALL_SIZE)))
		exit_error((char*)SDL_GetError());
	SDL_LockTexture(texture, NULL, &pixels, &pitch);
	ft_memcpy(pixels, tmp->pixels, tmp->pitch * tmp->h);
	SDL_UnlockTexture(texture);
	SDL_FreeSurface(tmp);
	return (texture);
}
