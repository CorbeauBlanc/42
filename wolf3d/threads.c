/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:04:37 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/18 15:46:46 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_thread(t_thread *thread, int(*fct)(void*), void *arg,
						t_thread_state state)
{
	thread->mutex = SDL_CreateMutex();
	thread->state = state;
	thread->ptr = SDL_CreateThread(fct, "Custom Thread", arg);
}

void		close_thread(t_thread *thread)
{
	SDL_LockMutex(thread->mutex);
	thread->state = STOP;
	SDL_WaitThread(thread->ptr, NULL);
	SDL_UnlockMutex(thread->mutex);
	SDL_DestroyMutex(thread->mutex);
}

t_mutexes	*get_mutexes()
{
	static t_mutexes	*mut = NULL;

	if (!mut)
	{
		if (!(mut = malloc(sizeof(t_mutexes))))
			exit_error(NULL);
		mut->environment = SDL_CreateMutex();
		mut->sprites = SDL_CreateMutex();
	}
	return (mut);
}

void		delete_mutexes()
{
	SDL_DestroyMutex(get_mutexes()->environment);
	SDL_DestroyMutex(get_mutexes()->sprites);
	free(get_mutexes());
}
