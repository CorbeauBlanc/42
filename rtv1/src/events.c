/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:21:27 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/23 21:25:43 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		new_event(t_event **head, SDL_Scancode key, int (*fct)())
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

void		delete_event(t_event **head)
{
	t_event	*tmp;

	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

void		clear_events(t_event **head)
{
	while (*head)
		delete_event(head);
}

static int	event_management(t_event *evt, t_player *player, int flag)
{
	return (evt->fct(player, flag) ? flag : 0);
}

void		wait_events(t_event *list_evts, t_player *player)
{
	t_event		*tmp;
	int			flag;
	Uint8		*kbd_state;
	SDL_Event	evt;

	flag = 1;
	while (flag && ++flag)
	{
		tmp = list_evts;
		SDL_PollEvent(&evt);
		if (evt.type == SDL_QUIT)
			exit(0);
		kbd_state = (Uint8*)SDL_GetKeyboardState(NULL);
		if (tmp && flag && SDL_TryLockMutex(get_mutexes()->environment) == 0)
		{
			while (tmp && flag)
			{
				if (kbd_state[tmp->key])
					flag = event_management(tmp, player, flag);
				tmp = tmp->next;
			}
			SDL_UnlockMutex(get_mutexes()->environment);
		}
		SDL_Delay(EVT_DELAY);
	}
}
