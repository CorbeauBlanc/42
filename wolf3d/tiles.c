/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:56:36 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/22 19:14:11 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map	*new_cell(t_vector *vect, t_tile type, t_map_data *data)
{
	t_map			*cell;

	if (!(cell = malloc(sizeof(t_map))))
		return (NULL);
	set_vect_crd(&cell->min, vect->x, vect->y);
	set_vect_crd(&cell->max, vect->x + WALL_SIZE, vect->y + WALL_SIZE);
	cell->textures[NORTH] = load_texture(type, NORTH, data);
	cell->textures[SOUTH] = load_texture(type, SOUTH, data);
	cell->textures[WEST] = load_texture(type, WEST, data);
	cell->textures[EAST] = load_texture(type, EAST, data);
	cell->reflections[NORTH] = load_reflection(type, NORTH, data);
	cell->reflections[SOUTH] = load_reflection(type, SOUTH, data);
	cell->reflections[WEST] = load_reflection(type, WEST, data);
	cell->reflections[EAST] = load_reflection(type, EAST, data);
	cell->mob = NULL;
	cell->data = data;
	cell->type = type;
	cell->down = NULL;
	cell->left = NULL;
	cell->right = NULL;
	cell->up = NULL;
	cell->r_head = NULL;
	cell->c_head = NULL;
	return (cell);
}

void	delete_cell(t_map *cell)
{
	if (cell->mob)
		delete_mob(cell->mob);
	free(cell);
}

t_map	*insert_cell(t_map *head, t_map *cell)
{
	if (head)
	{
		if (!(head->right))
		{
			head->right = cell;
			cell->left = head;
			if (head->up && head->up->right)
			{
				cell->up = head->up->right;
				head->up->right->down = cell;
			}
		}
		else
		{
			cell->up = head;
			head->down = cell;
		}
	}
	cell->c_head = cell->up ? cell->up->c_head : cell;
	cell->r_head = cell->left ? cell->left->r_head : cell;
	return (cell);
}

t_map	*goto_tile(t_vector *crd, t_map *tile)
{
	while (tile && (crd->x > tile->max.x || crd->x < tile->min.x ||
			crd->y > tile->max.y || crd->y < tile->min.y))
	{
		if (crd->x > tile->max.x)
			tile = tile->right;
		else if (crd->x < tile->min.x)
			tile = tile->left;
		if (tile && crd->y > tile->max.y)
			tile = tile->down;
		else if (tile && crd->y < tile->min.y)
			tile = tile->up;
	}
	return (tile);
}

t_map	*goto_tile2(double x, double y, t_map *tile)
{
	while (tile && (x > tile->max.x || x < tile->min.x ||
			y > tile->max.y || y < tile->min.y))
	{
		if (x > tile->max.x)
			tile = tile->right;
		else if (x < tile->min.x)
			tile = tile->left;
		if (tile && y > tile->max.y)
			tile = tile->down;
		else if (tile && y < tile->min.y)
			tile = tile->up;
	}
	return (tile);
}
