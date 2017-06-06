/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 17:41:59 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# ifndef __APPLE__
#  include <SDL.h>
# else
#  include "SDL2/SDL.h"
# endif

typedef enum		e_thread_state
{
	RUN,
	PAUSE,
	STOP
}					t_thread_state;

typedef struct		s_sdl_core
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				width;
	int				height;
	int				fullscreen;
}					t_sdl_core;

typedef struct		s_thread
{
	SDL_Thread		*ptr;
	SDL_mutex		*mutex;
	t_thread_state	state;
}					t_thread;

typedef struct		s_event
{
	SDL_Scancode	key;
	int				(*fct)();
	struct s_event	*next;
}					t_event;

typedef struct		s_matrix
{
	double			**mat;
	int				r;
	int				c;
}					t_matrix;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vector;

typedef struct		s_map
{

}					t_map;

typedef struct		s_camera
{
	int				fov;
	double			f;
	double			theta;
	double			phi;
	double			r;
	t_matrix		*view;
	SDL_Rect		screen;
	SDL_Thread		*refresh_cam;
	t_thread_state	state;
}					t_camera;

typedef struct		s_ray
{

}					t_ray;

#endif
