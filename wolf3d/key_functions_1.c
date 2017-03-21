/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/17 19:18:06 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void	move_left(t_player *player)
{
	double	angle;

	angle = ft_to_rad(player->cam->angle);
	player->pos.x -= cos(-M_PI_2 + angle) * SPEED;
	player->pos.y -= cos(-M_PI_2 + angle) * SPEED;
	goto_tile(&player->pos, player->tile);
}

void	move_right(t_player *player)
{
	double	angle;

	angle = ft_to_rad(player->cam->angle);
	player->pos.x += cos(-M_PI_2 + angle) * SPEED;
	player->pos.y += cos(-M_PI_2 + angle) * SPEED;
	goto_tile(&player->pos, player->tile);
}

void	move_up(t_player *player)
{
	double	angle;

	angle = ft_to_rad(player->cam->angle);
	player->pos.x += cos(angle) * SPEED;
	player->pos.y -= cos(angle) * SPEED;
	goto_tile(&player->pos, player->tile);
}

void	move_down(t_player *player)
{
	double	angle;

	angle = ft_to_rad(player->cam->angle);
	player->pos.x -= cos(angle) * SPEED;
	player->pos.y += cos(angle) * SPEED;
	goto_tile(&player->pos, player->tile);
}
