/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:55:48 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/03 17:20:32 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_texture	*load_texture(t_tile type, t_orientation side, t_map_data *data)
{
	char				*paths[WALL + 1];
	SDL_Rect			dim;
	static t_texture	*textures[WALL + 1][4] = {{NULL}};

	if (type <= FLOOR)
		return (NULL);
	paths[WALL] = "wall.bmp";
	paths[WALL2] = "wall2.bmp";
	paths[WALL3] = "wall3.bmp";
	paths[WALL4] = "wall4.bmp";
	paths[WOOD] = "wood.bmp";
	paths[BRICK] = "brick.bmp";
	paths[BOX] = "box.bmp";
	paths[BUSH] = "bush.bmp";
	paths[BOOK] = "bookshelf.bmp";
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

static void	set_reflect_alpha(SDL_Texture *text, t_map_data *data)
{
	SDL_SetTextureAlphaMod(text, data->reflection);
	SDL_SetTextureBlendMode(text, SDL_BLENDMODE_BLEND);
}

t_texture	*load_reflection(t_tile type, t_orientation side,
								t_map_data *data)
{
	char				*paths[WALL + 1];
	SDL_Rect			dim;
	static t_texture	*reflections[WALL + 1][4] = {{NULL}};

	if (type <= FLOOR)
		return (NULL);
	paths[WALL] = "reflect_wall.bmp";
	paths[WALL2] = "reflect_wall2.bmp";
	paths[WALL3] = "reflect_wall3.bmp";
	paths[WALL4] = "reflect_wall4.bmp";
	paths[WOOD] = "reflect_wood.bmp";
	paths[BRICK] = "reflect_brick.bmp";
	paths[BOX] = "reflect_box.bmp";
	paths[BUSH] = "reflect_bush.bmp";
	paths[BOOK] = "reflect_bookshelf.bmp";
	if (!reflections[type][side])
	{
		set_rect_crd(&dim, TEXT_SIZE * side, 0);
		set_rect_dim(&dim, TEXT_SIZE, TEXT_SIZE);
		reflections[type][side] = create_texture_rect(get_data_path(data->path,
														paths[type]), &dim);
		set_reflect_alpha(reflections[type][side]->text, data);
		garbage_collector(ADD, reflections[type][side], &delete_texture);
	}
	return (reflections[type][side]);
}
