/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:21:27 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/27 23:34:26 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	new_event(t_event **head, SDL_Scancode key, int (*fct)())
{
	t_event	*event;

	if ((event = malloc(sizeof(t_event))))
	{
		event->key = key;
		event->fct = fct;
		event->next = *head;
		*head = event;
	}
}

void	delete_event(t_event **head)
{
	t_event	*tmp;

	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

void	clear_events(t_event **head)
{
	while (*head)
		delete_event(head);
}

void	wait_events(t_event *list_evts, t_player *player)
{
	t_event		*tmp;
	int			flag;
	int			scan;
	Uint8		*kbd_state;

	flag = 1;
	while (flag)
	{
		tmp = list_evts;
		SDL_PumpEvents();
		kbd_state = (Uint8*)SDL_GetKeyboardState(NULL);
		scan = 0;
		while (tmp && flag)
		{
			if (kbd_state[tmp->key] && (scan = 1))
				flag = tmp->fct(player);
			tmp = tmp->next;
		}
		if (scan && flag)
			scan_environment(player);
		SDL_Delay(2);
	}
}
