/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:55:48 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/11 19:41:31 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_texture	*create_texture(char *path)
{
	SDL_Surface	*tmp;
	t_texture	*texture;

	if (!(tmp = SDL_LoadBMP(path)))
		exit_error((char*)SDL_GetError());
	if (!(texture = malloc(sizeof(t_texture))))
		exit_error(NULL);
	texture->text = SDL_CreateTextureFromSurface(SDL_GetCore()->renderer, tmp);
	if (!texture->text)
		exit_error((char*)SDL_GetError());
	texture->h = tmp->h;
	texture->w = tmp->w;
	texture->mapping_fact = texture->w / WALL_SIZE;
	SDL_FreeSurface(tmp);
	return (texture);
}

void		delete_texture(t_texture *texture)
{
	SDL_DestroyTexture(texture->text);
	free(texture);
}

t_texture		*load_texture(t_tile type)
{
	char				*paths[NB_TEXTURES];
	static t_texture	*textures[NB_TEXTURES] = {NULL};

	paths[FLOOR] = "textures/floor.bmp";
	paths[WALL] = "textures/wall.bmp";
	if (!textures[type])
	{
		textures[type] = create_texture(paths[type]);
		garbage_collector(ADD, textures[type], &delete_texture);
	}
	return (textures[type]);
}

t_texture		*load_reflection(t_tile type)
{
	char				*paths[NB_TEXTURES];
	static t_texture	*reflections[NB_TEXTURES] = {NULL};

	paths[FLOOR] = "textures/floor.bmp";
	paths[WALL] = "textures/reflection.bmp";
	if (!reflections[type])
	{
		reflections[type] = create_texture(paths[type]);
		garbage_collector(ADD, reflections[type], &delete_texture);
	}
	return (reflections[type]);
}
