/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:45 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/13 15:55:43 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H
# include "structures.h"
# ifndef __APPLE__
#  include <SDL2/SDL.h>
# else
#  include "SDL2/SDL.h"
# endif

/*
** threads.c
*/
void			init_thread(t_thread *thread, int(*fct)(void*), void *arg,
						t_thread_state state);
void			close_thread(t_thread *thread);
t_thread_state	get_thread_state(t_thread *thread);
void			set_thread_state(t_thread *thread, t_thread_state state);

#endif
