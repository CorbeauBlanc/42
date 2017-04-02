/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:41:33 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/31 19:20:12 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mob	*create_mob(SDL_Texture *front, int x, int y)
{
	t_mob	*mob;

	if (!(mob = malloc(sizeof(t_mob))))
		exit_error(NULL);
	mob->height = WALL_SIZE / 2;
	mob->width = WALL_SIZE / 2;
	mob->x = x;
	mob->y = y;
	mob->spt_front = front;
	return (mob);
}

void	delete_mob(t_mob *mob)
{
	SDL_DestroyTexture(mob->spt_front);
	free(mob);
}
