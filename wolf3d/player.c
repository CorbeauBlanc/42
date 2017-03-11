/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:33:13 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/11 16:36:59 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_player	*create_player(t_camera *cam, int x, int y, t_map *map)
{
	t_player	*player;

	if (!(player = malloc(sizeof(t_player))))
		exit_error(NULL);
	player->cam = cam;
	player->position.x = x;
	player->position.y = y;
	if (!(player->tile = goto_tile(&player->position, map)))
	{
		free(player);
		return (NULL);
	}
	return (player);
}

void		delete_player(t_player *player)
{
	delete_camera(player->cam);
	free(player);
}
