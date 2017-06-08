/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:04:37 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 17:50:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			init_thread(t_thread *thread, int (*fct)(void*), void *arg,
						t_thread_state state)
{
	thread->mutex = SDL_CreateMutex();
	thread->state = state;
	thread->ptr = SDL_CreateThread(fct, "Custom Thread", arg);
}

t_thread_state	get_thread_state(t_thread *thread)
{
	t_thread_state	state;

	SDL_LockMutex(thread->mutex);
	state = thread->state;
	SDL_UnlockMutex(thread->mutex);
	return (state);
}

void			set_thread_state(t_thread *thread, t_thread_state state)
{
	SDL_LockMutex(thread->mutex);
	thread->state = state;
	SDL_UnlockMutex(thread->mutex);
}

void			close_thread(t_thread *thread)
{
	set_thread_state(thread, STOP);
	SDL_WaitThread(thread->ptr, NULL);
	SDL_DestroyMutex(thread->mutex);
}
