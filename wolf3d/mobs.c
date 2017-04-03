/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:41:33 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/03 17:05:45 by edescoin         ###   ########.fr       */
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
	return (mob);
}

void	delete_mob(t_mob *mob)
{
	delete_texture(mob->spt_front);
	free(mob);
}
