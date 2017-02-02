/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:21:27 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/02 14:00:26 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void		new_key_evt(t_key_evt **head, int key, void (*fct)())
{
	t_key_evt	*evt;

	if ((evt = malloc(sizeof(t_key_evt))))
	{
		evt->key = key;
		evt->fct = fct;
		evt->cam = (*head)->cam;
		evt->map = (*head)->map;
		evt->next = *head;
		*head = evt;
	}
}

void		delete_key_evt(t_key_evt **head)
{
	t_key_evt	*tmp;

	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

void		clear_key_evts(t_key_evt **head)
{
	while (*head)
		delete_key_evt(head);
}

t_key_evt	*init_key_evts(int key, void (*fct)(), t_camera *cam, t_map *map)
{
	t_key_evt	*evt;

	if (!(evt = malloc(sizeof(t_key_evt))))
		return (NULL);
	evt->key = key;
	evt->fct = fct;
	evt->cam = cam;
	evt->map = map;
	evt->next = NULL;
	return (evt);
}

int			key_hook(int key, void *param)
{
	t_key_evt *key_evts;

	key_evts = (t_key_evt*)param;
	while (key_evts && key_evts->key != key)
		key_evts = key_evts->next;
	if (key_evts)
	{
		put_string(220, 20, "Computing...");
		key_evts->fct(key_evts->cam, key_evts->map);
		projection(key_evts->map, key_evts->cam);
	}
	else
		return (0);
	return (1);
}
