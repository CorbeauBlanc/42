/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/13 16:41:47 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static int	move_player_to_crd(t_player *player, t_vector *crd)
{
	t_map	*tmp;

	if ((tmp = goto_tile(crd, player->tile))->type < WALL && !tmp->mob)
	{
		player->pos = *crd;
		player->tile = tmp;
		return (1);
	}
	return (0);
}

int			move_left(t_player *player)
{
	double		angle;
	t_vector	move;

	angle = ft_to_rad(player->cam->angle + 90);
	set_vect_crd(&move, player->pos.x + cos(angle) * SPEED,
				player->pos.y - sin(angle) * SPEED);
	if (move_player_to_crd(player, &move))
		return (1);
	set_vect_crd(&move, player->pos.x + cos(angle) * SPEED, player->pos.y);
	if (move_player_to_crd(player, &move))
		return (1);
	set_vect_crd(&move, player->pos.x, player->pos.y - sin(angle) * SPEED);
	move_player_to_crd(player, &move);
	return (1);
}

int			move_right(t_player *player)
{
	double		angle;
	t_vector	move;

	angle = ft_to_rad(player->cam->angle - 90);
	set_vect_crd(&move, player->pos.x + cos(angle) * SPEED,
				player->pos.y - sin(angle) * SPEED);
	if (move_player_to_crd(player, &move))
		return (1);
	set_vect_crd(&move, player->pos.x + cos(angle) * SPEED, player->pos.y);
	if (move_player_to_crd(player, &move))
		return (1);
	set_vect_crd(&move, player->pos.x, player->pos.y - sin(angle) * SPEED);
	move_player_to_crd(player, &move);
	return (1);
}

int			move_up(t_player *player)
{
	double		angle;
	t_vector	move;

	angle = ft_to_rad(player->cam->angle);
	set_vect_crd(&move, player->pos.x + cos(angle) * SPEED,
				player->pos.y - sin(angle) * SPEED);
	if (move_player_to_crd(player, &move))
		return (1);
	set_vect_crd(&move, player->pos.x + cos(angle) * SPEED, player->pos.y);
	if (move_player_to_crd(player, &move))
		return (1);
	set_vect_crd(&move, player->pos.x, player->pos.y - sin(angle) * SPEED);
	move_player_to_crd(player, &move);
	return (1);
}

int			move_down(t_player *player)
{
	double		angle;
	t_vector	move;

	angle = ft_to_rad(player->cam->angle);
	set_vect_crd(&move, player->pos.x - cos(angle) * SPEED,
				player->pos.y + sin(angle) * SPEED);
	if (move_player_to_crd(player, &move))
		return (1);
	return (1);
}
