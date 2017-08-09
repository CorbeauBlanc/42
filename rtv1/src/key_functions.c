/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/09 17:05:17 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	key_management(SDL_Event *current, t_event *evt)
{
	if (current->key.keysym.sym == SDLK_ESCAPE)
		return (0);
	else if (current->key.keysym.sym == SDLK_F5)
	{
		garbage_collector(CLEAR, NULL, NULL);
		render_scene(garbage_collector(ADD, get_scene(evt->data),
										delete_scene));
	}
	return (1);
}
