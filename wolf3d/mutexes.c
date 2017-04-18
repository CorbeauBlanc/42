/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:35:45 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/18 21:43:00 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mutexes	*get_mutexes()
{
	static t_mutexes	*mut = NULL;

	if (!mut)
	{
		if (!(mut = malloc(sizeof(t_mutexes))))
			exit_error(NULL);
		mut->environment = SDL_CreateMutex();
		mut->mob_mvt = SDL_CreateMutex();
	}
	return (mut);
}

void		delete_mutexes()
{
	SDL_DestroyMutex(get_mutexes()->environment);
	SDL_DestroyMutex(get_mutexes()->mob_mvt);
	free(get_mutexes());
}
