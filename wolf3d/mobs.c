/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:41:33 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/04 17:14:22 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mob	*create_mob(t_texture *front, SDL_Rect *dim)
{
	t_mob	*mob;

	if (!(mob = malloc(sizeof(t_mob))))
		exit_error(NULL);
	mob->height = dim->h;
	mob->width = dim->w;
	mob->x = dim->x;
	mob->y = dim->y;
	mob->spt_front = front;
	mob->spt_front->mapping_fact = mob->spt_front->w / mob->width;
	mob->data.next = NULL;
	return (mob);
}

void	delete_mob(t_mob *mob)
{
	delete_texture(mob->spt_front);
	free(mob);
}

void	insert_mob(t_map *cell, char *nbs)
{
	SDL_Rect dim;

	if (*nbs == 'M' || *nbs == 'm')
	{
		set_rect_crd(&dim, cell->min.x + (WALL_SIZE - WALL_SIZE / 2) / 2,
					cell->min.y + (WALL_SIZE - WALL_SIZE / 2) / 2);
		set_rect_dim(&dim, WALL_SIZE / 2, WALL_SIZE / 2);
		cell->mob = create_mob(create_texture("textures/floor.bmp"), &dim);
	}
}
