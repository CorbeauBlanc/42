/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:55:48 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/03 17:29:18 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_texture	*create_texture(char *path)
{
	SDL_Surface	*tmp;
	t_texture	*texture;

	if (!(tmp = SDL_LoadBMP(path)))
		exit_custom_error("wolf3d : ", (char*)SDL_GetError());
	if (!(texture = malloc(sizeof(t_texture))))
		exit_error("wolf3d : ", "malloc");
	texture->text = SDL_CreateTextureFromSurface(get_sdl_core()->renderer, tmp);
	if (!texture->text)
		exit_custom_error("wolf3d : ", (char*)SDL_GetError());
	texture->h = tmp->h;
	texture->w = tmp->w;
	texture->mapping_fact = texture->w / WALL_SIZE;
	SDL_FreeSurface(tmp);
	return (texture);
}

t_texture	*create_texture_rect(char *path, SDL_Rect *dim)
{
	SDL_Surface	*tmp;
	SDL_Surface	*srf;
	t_texture	*texture;

	if (!dim)
		return (create_texture(path));
	if (!(tmp = SDL_LoadBMP(path)))
		exit_custom_error("wolf3d : ", (char*)SDL_GetError());
	if (!(texture = malloc(sizeof(t_texture))))
		exit_error("wolf3d : ", "malloc");
	dim->x = dim->x % tmp->w;
	srf = SDL_CreateRGBSurface(0, dim->w, dim->h, 32, 0, 0, 0, 0);
	SDL_BlitSurface(tmp, dim, srf, NULL);
	texture->text = SDL_CreateTextureFromSurface(get_sdl_core()->renderer, srf);
	if (!texture->text)
		exit_custom_error("wolf3d : ", (char*)SDL_GetError());
	texture->h = dim->h;
	texture->w = dim->w;
	texture->mapping_fact = texture->w / WALL_SIZE;
	SDL_FreeSurface(tmp);
	SDL_FreeSurface(srf);
	return (texture);
}

void		delete_texture(t_texture *texture)
{
	SDL_DestroyTexture(texture->text);
	free(texture);
}
