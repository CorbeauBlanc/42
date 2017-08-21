/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:33 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/11 17:43:35 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "structures.h"
# ifndef __APPLE__
#  include <SDL2/SDL.h>
# else
#  include "SDL2/SDL.h"
# endif

/*
** events.c
*/
void	clear_events(t_event **head);
void	delete_event(t_event **head);
void	new_event(t_event **head, SDL_EventType type, void *data, int (*fct)());
void	wait_events(t_event *list_evts);

/*
** key_functions.c
*/
int		key_management(SDL_Event *current, t_event *evt);

/*
** mouse_functions.c
*/
int		button_management(SDL_Event *current, t_event *evt);
int		motion_management(SDL_Event *current, t_event *evt);
int		wheel_management(SDL_Event *current, t_event *evt);

#endif
