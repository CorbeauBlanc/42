/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:51:08 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/11 21:00:30 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define TITLE			"RTv1"
# define FOV			60
# define BUFF_SIZE		1024
# define MOUSE_XSPEED	1.5
# define MOUSE_YSPEED	1.5
# define MOUSE_ASPEED	0.1
# define MOUSE_ZSPEED	3
# define DEFAULT_LR		7

# ifndef __APPLE__
#  include <SDL2/SDL.h>
#  define SDL_VIDEO		SDL_INIT_VIDEO
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
# include "get_next_line.h"
# include "graphics.h"
# include "matrix.h"
# include "objects.h"
# include "parametric_equations.h"
# include "parser.h"
# include "rays.h"
# include "raytracing.h"
# include "scene.h"
# include "structures.h"
# include "threads.h"
# include "vectors.h"

/*
** main.c
*/
void	exit_main();

/*
** tools.c
*/
int		get_quad_equation_sol(t_dot *res, double a, double b, double c);
void	set_rect_dim(SDL_Rect *rect, int w, int h);
void	set_rect_crd(SDL_Rect *rect, int x, int y);

#endif
