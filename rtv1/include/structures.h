/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/10 21:26:59 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# define WIDTH 		600
# define HEIGHT 	600
# ifndef __APPLE__
#  include <SDL2/SDL.h>
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
	PLANE,
	CYLINDER
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
}					t_vector;

typedef struct		s_dot
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_dot;

typedef struct		s_param_eq
{
	t_vector		vdir;
	t_vector		vconst;
}					t_param_eq;

typedef struct		s_object
{
	const t_type	obj_type;
	double			(*intersect)();
	const t_vector	*(*get_normal)();
	t_matrix		*rot;
	t_matrix		*rot_inv;
	t_matrix		*trans;
	t_matrix		*trans_inv;
}					t_object;

typedef struct		s_sphere
{
	const t_type	obj_type;
	double			(*intersect)();
	const t_vector	*(*get_normal)();
	t_matrix		*rot;
	t_matrix		*rot_inv;
	t_matrix		*trans;
	t_matrix		*trans_inv;
	t_vector		normal;
	double			radius;
	double			r2;
	t_dot			center;

}					t_sphere;

typedef struct		s_cylinder
{
	const t_type	obj_type;
	double			(*intersect)();
	const t_vector	*(*get_normal)();
	t_matrix		*rot;
	t_matrix		*rot_inv;
	t_matrix		*trans;
	t_matrix		*trans_inv;
	t_vector		normal;
	double			radius;
	double			r2;
	double			rho;
	double			theta;
	double			phi;
	t_dot			center;
}					t_cylinder;

typedef struct		s_plane
{
	const t_type	obj_type;
	double			(*intersect)();
	const t_vector	*(*get_normal)();
	t_matrix		*rot;
	t_matrix		*rot_inv;
	t_matrix		*trans;
	t_matrix		*trans_inv;
	t_vector		normal;
	double			a;
	double			b;
	double			c;
	double			d;
	double			z;
}					t_plane;

typedef struct		s_spotlight
{
	t_dot			crd;
}					t_spotlight;

typedef struct		s_cell
{
	t_object		*obj;
	struct s_cell	*next;
}					t_cell;

typedef struct		s_camera
{
	int				fov;
	t_dot			crd;
	t_dot			screen[WIDTH][HEIGHT];
	double			f;
	double			theta;
	double			phi;
}					t_camera;

typedef struct		s_scene
{
	t_spotlight		light;
	t_camera		*cam;
	t_cell			*collection;
}					t_scene;

typedef struct		s_intersect
{
	double			dist;
	double			ldist;
	t_dot			dot;
	t_object		*obj;
	t_vector		normal;
}					t_intersect;

typedef struct		s_ray
{
	t_param_eq		eq;
	t_param_eq		eq_obj;
	SDL_Color		color;
	t_intersect		i;
}					t_ray;

#endif
