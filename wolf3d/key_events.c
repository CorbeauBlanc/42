/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:40:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/28 20:41:57 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_key_data	*new_key_data(SDL_Keycode key, int (*fct)())
{
	t_key_data	*data;

	if (!(data = malloc(sizeof(t_key_data))))
		exit_error(NULL);
	data->key = key;
	data->fct = fct;
	return (data);
}

int			key_hook(SDL_Event evt, t_event *list_evts)
{
	t_key_data	*evt_data;

	evt_data = (t_key_data*)list_evts->data;
	while (list_evts && evt_data && evt.key.keysym.sym != evt_data->key)
	{
		list_evts = list_evts->next;
		if (list_evts && list_evts->type == evt.type)
			evt_data = (t_key_data*)list_evts->data;
	}
	if (list_evts)
		return (evt_data->fct());
	else
		return (1);
}
