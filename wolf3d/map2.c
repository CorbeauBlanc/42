/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:14:17 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/16 19:22:46 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	check_player(t_map *map)
{
	if (!get_player()->tile)
	{
		map->r_head->c_head->type = FLOOR;
		insert_player(map, WALL_SIZE / 2, WALL_SIZE / 2);
	}
	SDL_LockMutex(get_mutexes()->environment);
	get_player()->cam->state = RUN;
	SDL_UnlockMutex(get_mutexes()->environment);
}
