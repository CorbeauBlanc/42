/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/27 21:47:52 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>

void	exit_error(char *s)
{
	if (!s)
	{
		perror("wolf3d");
		exit(1);
	}
	ft_putstr_fd(s, 2);
	exit(1);
}

void	exit_main()
{
	SDL_DestroyWindow(SDL_GetMainWindow());
	SDL_Quit();
	garbage_collector(CLEAR, NULL, NULL);
	exit(0);
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	SDL_GetMainWindow();
	SDL_Event e;
int quit = 0;
while (!quit){
    while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT){
            quit = 1;
        }
        if (e.type == SDL_KEYDOWN){
            quit = 1;
        }
        if (e.type == SDL_MOUSEBUTTONDOWN){
            quit = 1;
        }
    }
}
	exit_main();
	return (0);
}
