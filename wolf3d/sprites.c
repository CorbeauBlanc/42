/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:29:31 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/23 21:26:47 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_sprite	*create_sprite(char *path, int h, int map_width, int delay)
{
	t_sprite	*sprite;

	if (!(sprite = malloc(sizeof(t_sprite))))
		exit_error("wolf3d : ", "malloc");
	sprite->pic = create_texture(path);
	sprite->m_width = map_width > WALL_SIZE ? WALL_SIZE : map_width;
	sprite->mapping_fact = sprite->pic->w / map_width;
	sprite->current.x = 0;
	sprite->current.y = 0;
	sprite->current.w = sprite->pic->w;
	sprite->current.h = h;
	sprite->ms = delay;
	return (sprite);
}

void		delete_sprite(t_sprite *sprite)
{
	delete_texture(sprite->pic);
	free(sprite);
}
