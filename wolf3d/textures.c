/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:55:48 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/30 18:07:23 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Texture	*create_texture(char *path)
{
	SDL_Texture	*texture;
	SDL_Surface	*tmp;

	if (!(tmp = SDL_LoadBMP(path)))
		exit_error((char*)SDL_GetError());
	texture = SDL_CreateTextureFromSurface(SDL_GetCore()->renderer, tmp);
	if (!texture)
		exit_error((char*)SDL_GetError());
	SDL_FreeSurface(tmp);
	return (texture);
}

SDL_Texture		*load_texture(t_tile type, int *s)
{
	char				*paths[NB_TEXTURES];
	static SDL_Texture	*textures[NB_TEXTURES] = {NULL};

	paths[FLOOR] = "textures/floor.bmp";
	paths[WALL] = "textures/wall.bmp";
	if (!textures[type])
		textures[type] = create_texture(paths[type]);
	SDL_QueryTexture(textures[type], NULL, NULL, NULL, s);
	return (textures[type]);
}

SDL_Texture		*load_reflection(t_tile type, int *s)
{
	char				*paths[NB_TEXTURES];
	static SDL_Texture	*reflections[NB_TEXTURES] = {NULL};

	paths[FLOOR] = "textures/floor.bmp";
	paths[WALL] = "textures/reflection.bmp";
	if (!reflections[type])
		reflections[type] = create_texture(paths[type]);
	SDL_QueryTexture(reflections[type], NULL, NULL, NULL, s);
	return (reflections[type]);
}

SDL_Texture		*load_background(char *path, int *w)
{
	SDL_Texture	*background;

	background = create_texture(path);
	SDL_QueryTexture(background, NULL, NULL, w, NULL);
	return (background);
}
