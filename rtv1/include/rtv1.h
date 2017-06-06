/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:51:08 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 17:44:04 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define TITLE			"Wolf3D"
# define WIDTH 			700
# define HEIGHT 		700
# define FOV			60
# define BUFF_SIZE		1024

# ifndef __APPLE__
#  include <SDL.h>
#  define SDL_VIDEO		SDL_VIDEO_DRIVER_X11
# else
#  include "SDL2/SDL.h"
#  define SDL_VIDEO		SDL_VIDEO_DRIVER_COCOA
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

# include "camera.h"
# include "events.h"
# include "graphics.h"
# include "map.h"
# include "matrix.h"
# include "structures.h"
# include "threads.h"

/*
** main.c
*/
void	exit_main();

/*
** tools.c
*/
void	set_rect_dim(SDL_Rect *rect, int w, int h);
void	set_rect_crd(SDL_Rect *rect, int x, int y);

#endif
