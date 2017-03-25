/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/25 21:36:58 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

int	move_left(t_player *player)
{
	double		angle;
	t_map		*tmp;
	t_vector	move;

	angle = ft_to_rad(player->cam->angle + 90);
	move = player->pos;
	move.x += cos(angle) * SPEED;
	move.y -= sin(angle) * SPEED;
	if ((tmp = goto_tile(&move, player->tile))->type < WALL)
	{
		player->pos = move;
		player->tile = tmp;
	}
	return (1);
}

int	move_right(t_player *player)
{
	double		angle;
	t_map		*tmp;
	t_vector	move;

	angle = ft_to_rad(player->cam->angle - 90);
	move = player->pos;
	move.x += cos(angle) * SPEED;
	move.y -= sin(angle) * SPEED;
	if ((tmp = goto_tile(&move, player->tile))->type < WALL)
	{
		player->pos = move;
		player->tile = tmp;
	}
	return (1);
}

int	move_up(t_player *player)
{
	double		angle;
	t_map		*tmp;
	t_vector	move;

	angle = ft_to_rad(player->cam->angle);
	move = player->pos;
	move.x += cos(angle) * SPEED;
	move.y -= sin(angle) * SPEED;
	if ((tmp = goto_tile(&move, player->tile))->type < WALL)
	{
		player->pos = move;
		player->tile = tmp;
	}
	return (1);
}

int	move_down(t_player *player)
{
	double		angle;
	t_map		*tmp;
	t_vector	move;

	angle = ft_to_rad(player->cam->angle);
	move = player->pos;
	move.x -= cos(angle) * SPEED;
	move.y += sin(angle) * SPEED;
	if ((tmp = goto_tile(&move, player->tile))->type < WALL)
	{
		player->pos = move;
		player->tile = tmp;
	}
	return (1);
}
