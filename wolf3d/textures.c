/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:55:48 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/23 21:42:17 by edescoin         ###   ########.fr       */
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
	texture->text = SDL_CreateTextureFromSurface(SDL_GetCore()->renderer, tmp);
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
	SDL_Surface	*surf;
	t_texture	*texture;

	if (!dim)
		return (create_texture(path));
	if (!(tmp = SDL_LoadBMP(path)))
		exit_custom_error("wolf3d : ", (char*)SDL_GetError());
	if (!(texture = malloc(sizeof(t_texture))))
		exit_error("wolf3d : ", "malloc");
	dim->x = dim->x % tmp->w;
	surf = SDL_CreateRGBSurface(0, dim->w, dim->h, 32, 0, 0, 0, 0);
	SDL_BlitSurface(tmp, dim, surf, NULL);
	texture->text = SDL_CreateTextureFromSurface(SDL_GetCore()->renderer, surf);
	if (!texture->text)
		exit_custom_error("wolf3d : ", (char*)SDL_GetError());
	texture->h = dim->h;
	texture->w = dim->w;
	texture->mapping_fact = texture->w / WALL_SIZE;
	SDL_FreeSurface(tmp);
	SDL_FreeSurface(surf);
	return (texture);
}

void		delete_texture(t_texture *texture)
{
	SDL_DestroyTexture(texture->text);
	free(texture);
}

t_texture		*load_texture(t_tile type, t_orientation side, t_map_data *data)
{
	char				*paths[WALL + 1];
	SDL_Rect			dim;
	static t_texture	*textures[WALL + 1][4] = {{NULL}};

	if (type <= FLOOR)
		return (NULL);
	paths[WALL] = "wall.bmp";
	paths[WOOD] = "wood.bmp";
	if (!textures[type][side])
	{
		set_rect_crd(&dim, TEXT_SIZE * side, 0);
		set_rect_dim(&dim, TEXT_SIZE, TEXT_SIZE);
		textures[type][side] = create_texture_rect(get_data_path(data->path,
																paths[type]),
													&dim);
		garbage_collector(ADD, textures[type][side], &delete_texture);
	}
	return (textures[type][side]);
}

t_texture		*load_reflection(t_tile type, t_orientation side,
								t_map_data *data)
{
	char				*paths[WALL + 1];
	SDL_Rect			dim;
	static t_texture	*reflections[WALL + 1][4] = {{NULL}};

	if (type <= FLOOR)
		return (NULL);
	paths[WALL] = "reflection.bmp";
	paths[WOOD] = "reflection.bmp";
	if (!reflections[type][side])
	{
		set_rect_crd(&dim, TEXT_SIZE * side, 0);
		set_rect_dim(&dim, TEXT_SIZE, TEXT_SIZE);
		reflections[type][side] = create_texture_rect(get_data_path(data->path,
																paths[type]),
														&dim);
		SDL_SetTextureAlphaMod(reflections[type][side]->text, data->reflection);
		SDL_SetTextureBlendMode(reflections[type][side]->text,
			SDL_BLENDMODE_BLEND);
		garbage_collector(ADD, reflections[type][side], &delete_texture);
	}
	return (reflections[type][side]);
}
