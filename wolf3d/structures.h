/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/31 19:19:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# ifndef __APPLE__
#  include <SDL2/SDL.h>
# else
#  include "SDL.h"
# endif

typedef enum		e_tile
{
					FLOOR,
					WALL
}					t_tile;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vector;

/*
typedef struct		s_screen
{
	SDL_Texture		*texture;
	Uint32			*pxl_tab;
	int				width;
	int				height;
	int				pitch;
}					t_screen;
*/

typedef struct		s_camera
{
	int				angle;
	int				fov;
	double			half_scr;
	double			f;
	double			sensi;
	SDL_Rect		screen;
}					t_camera;

typedef struct		s_SDL_Core
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				width;
	int				height;
}					t_SDL_Core;

typedef struct		s_ray_data
{
	t_vector		i;
	struct s_mob	*next;
}					t_ray_data;

typedef struct		s_mob
{
	SDL_Texture		*spt_front;
	SDL_Texture		*spt_back;
	SDL_Texture		*spt_left;
	SDL_Texture		*spt_right;
	int				width;
	int				height;
	int				x;
	int				y;
	t_ray_data		data;
}					t_mob;

typedef struct		s_map_data
{
	int				brightness;
	int				bg_w;
	double			bg_fact;
	SDL_Texture		*background;
}					t_map_data;

typedef struct		s_map
{
	t_vector		min;
	t_vector		max;
	t_tile			type;
	SDL_Texture		*texture;
	SDL_Texture		*reflect;
	int				text_size;
	int				refl_size;
	t_mob			*mob;
	t_map_data		*data;
	struct s_map	*r_head;
	struct s_map	*c_head;
	struct s_map	*left;
	struct s_map	*right;
	struct s_map	*up;
	struct s_map	*down;
}					t_map;

typedef struct		s_player
{
	t_camera		*cam;
	t_vector		pos;
	t_map			*tile;
}					t_player;

typedef struct		s_event
{
	SDL_Scancode	key;
	int				(*fct)();
	struct s_event	*next;
}					t_event;

typedef struct		s_ray
{
	double			a;
	double			h;
	double			d;
	t_map			*h_wall;
	t_map			*v_wall;
	t_mob			*h_mob;
	t_mob			*v_mob;
	t_vector		h_i;
	t_vector		v_i;
	Uint8			filter;
}					t_ray;

#endif
