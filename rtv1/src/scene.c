/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:41:24 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/19 15:06:16 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_cell	*new_cell(t_cell **head, t_object *obj)
{
	t_cell	*tmp;

	if (!(tmp = malloc(sizeof(t_cell))))
		exit_error("rtv1", "malloc");
	tmp->next = NULL;
	tmp->obj = obj;
	if (!head)
		return (tmp);
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}

static void		delete_cell(t_cell **cell)
{
	t_cell	*tmp;

	tmp = *cell;
	*cell = (*cell)->next;
	free(tmp->obj);
	free(tmp);
}

void			scene_add_object(t_object *obj, t_scene *scene)
{
	if (!scene->collection)
		scene->collection = new_cell(NULL, obj);
	else
		new_cell(&scene->collection, obj);
}

void			clear_scene(t_scene *scene)
{
	while (scene->collection)
		delete_cell(&scene->collection);
}
