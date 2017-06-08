/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:33 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 18:07:39 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "structures.h"
# ifndef __APPLE__
#  include <SDL.h>
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
** key_functions_*.c
*/
void	rotate_down(t_camera *cam, t_map *map);
void	rotate_left(t_camera *cam, t_map *map);
void	rotate_right(t_camera *cam, t_map *map);
void	rotate_up(t_camera *cam, t_map *map);
void	translate_down(t_camera *cam, t_map *map);
void	translate_left(t_camera *cam, t_map *map);
void	translate_right(t_camera *cam, t_map *map);
void	translate_up(t_camera *cam, t_map *map);
void	zoom_in(t_camera *cam, t_map *map);
void	zoom_out(t_camera *cam, t_map *map);

#endif
