/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:41:24 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 17:53:00 by edescoin         ###   ########.fr       */
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

void			delete_scene(t_scene *scene)
{
	if (scene)
	{
		while (scene->collection)
			delete_cell(&scene->collection);
		delete_camera(scene->cam);
		delete_spotlight(scene->light);
		free(scene);
	}
}

t_scene			*new_scene(t_spotlight *light, t_camera *cam, double brightness,
							SDL_Color bgcolor)
{
	t_scene	*scene;

	if (!(scene = malloc(sizeof(t_scene))))
		exit_error("rtv1", "malloc");
	if (brightness > 100)
		brightness = 100;
	if (brightness < 0)
		brightness = 0;
	scene->brightness = brightness / 100;
	scene->cam = cam;
	scene->light = light;
	scene->collection = NULL;
	scene->bgcolor = bgcolor;
	return (scene);
}
