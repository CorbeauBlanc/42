/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 18:36:24 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# define WIN_WIDTH 	1200
# define WIN_HEIGHT 650
# ifndef __APPLE__
#  include <SDL2/SDL.h>
# else
#  include "SDL2/SDL.h"
# endif

typedef struct		s_buffer
{
	char			*str;
	int				fd;
	int				eof;
}					t_buffer;

typedef enum		e_thread_state
{
	RUN,
	PAUSE,
	STOP
}					t_thread_state;

typedef enum		e_type
{
	NONE,
	BOX,
	CONE,
	CYLINDER,
	PLANE,
	SPHERE
}					t_type;

typedef enum		e_sc_data
{
	VOID,
	COLOR,
	COORDS,
	ENVIRONMENT,
	BACKGROUND,
	LIGHT,
	CAMERA,
	OBJECT,
	ROTATION,
	TRANSLATION,
	SCALE
}					t_sc_data;

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

typedef struct		s_evt_data
{
	char			*path;
	struct s_scene	*scene;
	Uint8			mouse_clic;
}					t_evt_data;

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
	t_matrix		*scale;
	t_matrix		*scale_inv;
	t_vector		normal;
	SDL_Color		color;
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
	t_matrix		*scale;
	t_matrix		*scale_inv;
	t_vector		normal;
	SDL_Color		color;
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
	t_matrix		*scale;
	t_matrix		*scale_inv;
	t_vector		normal;
	SDL_Color		color;
	double			radius;
	double			r2;
	double			height;
	t_dot			center;
}					t_cylinder;

typedef struct		s_cone
{
	const t_type	obj_type;
	double			(*intersect)();
	const t_vector	*(*get_normal)();
	t_matrix		*rot;
	t_matrix		*rot_inv;
	t_matrix		*trans;
	t_matrix		*trans_inv;
	t_matrix		*scale;
	t_matrix		*scale_inv;
	t_vector		normal;
	SDL_Color		color;
	double			height;
	double			angle;
	double			radius;
	double			tanalpha2;
	t_dot			center;
}					t_cone;

typedef struct		s_plane
{
	const t_type	obj_type;
	double			(*intersect)();
	const t_vector	*(*get_normal)();
	t_matrix		*rot;
	t_matrix		*rot_inv;
	t_matrix		*trans;
	t_matrix		*trans_inv;
	t_matrix		*scale;
	t_matrix		*scale_inv;
	t_vector		normal;
	SDL_Color		color;
	t_dot			pos;
	double			a;
	double			b;
	double			c;
	double			d;
	double			z;
}					t_plane;

typedef struct		s_box
{
	const t_type	obj_type;
	double			(*intersect)();
	const t_vector	*(*get_normal)();
	t_matrix		*rot;
	t_matrix		*rot_inv;
	t_matrix		*trans;
	t_matrix		*trans_inv;
	t_matrix		*scale;
	t_matrix		*scale_inv;
	t_vector		normal;
	SDL_Color		color;
	t_dot			fbl_corner;
	t_dot			btr_corner;
	t_plane			*front;
	t_plane			*back;
	t_plane			*top;
	t_plane			*bottom;
	t_plane			*left;
	t_plane			*right;
}					t_box;

typedef struct		s_box_intersect
{
	t_box			*box;
	double			dist;
	double			t;
}					t_box_intersect;

typedef struct		s_spotlight
{
	t_dot			crd;
	double			power;
}					t_spotlight;

typedef struct		s_cell
{
	t_object		*obj;
	struct s_cell	*next;
}					t_cell;

typedef struct		s_camera
{
	int				fov;
	int				resolution;
	int				low_resolution;
	t_dot			crd;
	t_dot			screen[WIN_WIDTH][WIN_HEIGHT];
	double			f;
	double			theta;
	double			phi;
}					t_camera;

typedef struct		s_scene
{
	t_spotlight		*light;
	t_camera		*cam;
	t_cell			*collection;
	double			brightness;
	SDL_Color		bgcolor;
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
