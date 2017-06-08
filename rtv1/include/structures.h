/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/07 23:02:10 by edescoin         ###   ########.fr       */
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

typedef enum		e_type
{
	CONE,
	SPHERE,
	PRYRAMID
}					t_type;

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
	SDL_EventType	type;
	void			*data;
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

typedef struct		s_object
{
	const t_type	obj_type;
	void			(*intersect)();
}					t_object;

typedef struct		s_sphere
{
	const t_type	obj_type;
	void			(*intersect)();
	t_vector		center;
	double			radius;
}					t_sphere;

typedef struct	s_obj_cell
{
	t_object	*obj;
	struct s_obj_cell	*next;
}				t_obj_cell;

typedef struct	s_map
{
	t_obj_cell	*collection;
}				t_map;

typedef struct		s_camera
{
	int				fov;
	double			f;
	double			theta;
	double			phi;
	double			r;
	SDL_Rect		screen;
	SDL_Thread		*refresh_cam;
	t_thread_state	state;
}					t_camera;

typedef struct		s_ray
{

}					t_ray;

#endif
