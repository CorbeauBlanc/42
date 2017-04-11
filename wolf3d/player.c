/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:33:13 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/11 17:08:51 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

t_player	*create_player(t_camera *cam)
{
	t_player	*player;

	if (!(player = malloc(sizeof(t_player))))
		exit_error(NULL);
	player->cam = cam;
	return (player);
}

t_player	*get_player()
{
	static t_player	*player = NULL;

	if (!player)
		player = create_player(create_camera(70, -50, 2.0));
	return (player);
}

void		delete_player()
{
	delete_camera(get_player()->cam);
	free(get_player());
}

void		insert_player(t_map *map, double x, double y)
{
	t_player	*player;

	player = get_player();
	if (map)
	{
		player->pos.x = x;
		player->pos.y = y;
		if (!(player->tile = goto_tile(&player->pos, map)))
			exit_error("error : player out of map");
		map->data->bg_fact = player->cam->screen.w / player->cam->fov;
	}
}
