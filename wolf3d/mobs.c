/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:41:33 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/12 22:59:00 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mob	*create_mob(t_npc_spts *spts, int h, int view)
{
	t_mob	*mob;

	if (!(mob = malloc(sizeof(t_mob))))
		exit_error(NULL);
	mob->view = view;
	mob->height = h;
	mob->spt_north = spts->spt_front;
	mob->spt_south = spts->spt_back;
	mob->spt_west = spts->spt_left;
	mob->spt_east = spts->spt_right;
	mob->visible = 0;
	mob->data.next = NULL;
	mob->spt_mutex = SDL_CreateMutex();
	mob->state = RUN;
	mob->animation = SDL_CreateThread(&mob_main_thread, "Mob animation", mob);
	return (mob);
}

void	delete_mob(t_mob *mob)
{
	mob_set_state(mob, STOP);
	SDL_WaitThread(mob->animation, NULL);
	SDL_DestroyMutex(mob->spt_mutex);
	delete_sprite(mob->spt_north);
	delete_sprite(mob->spt_south);
	delete_sprite(mob->spt_west);
	delete_sprite(mob->spt_east);
	free(mob);
}

void	insert_mob(t_map *cell, char *nbs)
{
	t_npc_spts	spts;

	spts.spt_front = create_sprite("textures/floor2.bmp", 64, WALL_SIZE / 2, 1000);
	spts.spt_back = create_sprite("textures/floor2.bmp", 64, WALL_SIZE / 2, 1000);
	spts.spt_left = create_sprite("textures/test_mob.bmp", 64, WALL_SIZE / 2, 1000);
	spts.spt_right = create_sprite("textures/test_mob.bmp", 64, WALL_SIZE / 2, 1000);
	if (*nbs == 'M' || *nbs == 'm')
	{
		cell->mob = create_mob(&spts, WALL_SIZE / 2, 0);
		cell->mob->x = cell->min.x + (WALL_SIZE - cell->mob->spt_west->m_width) / 2;
		cell->mob->y = cell->min.y + (WALL_SIZE - cell->mob->spt_north->m_width) / 2;
	}
}
