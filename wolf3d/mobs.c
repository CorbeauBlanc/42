/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:41:33 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/18 22:16:07 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	mob_set_visible(t_mob *mob, int val)
{
	SDL_LockMutex(mob->animation.mutex);
	mob->visible = val;
	SDL_UnlockMutex(mob->animation.mutex);
}

t_mob	*create_mob(t_npc_spts *spts, int h, int view)
{
	t_mob	*mob;

	if (!(mob = malloc(sizeof(t_mob))))
		exit_error(NULL);
	mob->view = view;
	mob->height = h;
	mob->sprites = *spts;
	mob->view = view;
	mob->visible = 0;
	mob->watching = 0;
	mob->htb.xminymin = NULL;
	mob->htb.xminymax = NULL;
	mob->htb.xmaxymin = NULL;
	mob->htb.xmaxymax = NULL;
	set_mob_sprites(mob);
	mob->data.next = NULL;
	mob->data.h = -1;
	mob->data.y = -1;
	init_thread(&mob->animation, &mob_animation_thread, mob, RUN);
	init_thread(&mob->movement, &mob_movement_thread, mob, RUN);
	return (mob);
}

void	delete_mob(t_mob *mob)
{
	close_thread(&mob->movement);
	close_thread(&mob->animation);
	delete_sprite(mob->spt_north);
	delete_sprite(mob->spt_south);
	delete_sprite(mob->spt_west);
	delete_sprite(mob->spt_east);
	set_htb_tiles(&mob->htb, NULL);
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
		set_all_mob_tiles(create_mob(&spts, WALL_SIZE / 2, 180), cell);
		set_mob_htb(cell->mob,
			cell->min.x + (WALL_SIZE - cell->mob->spt_west->m_width) / 2,
			cell->min.y + (WALL_SIZE - cell->mob->spt_north->m_width) / 2);
	}
}
