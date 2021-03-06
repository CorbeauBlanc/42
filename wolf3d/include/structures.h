/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/03 17:42:56 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# ifndef __APPLE__
#  include <SDL2/SDL.h>
# else
#  include "SDL2/SDL.h"
# endif

/*
**		FLOOR	: 0
**		WOOD	: 1
**		BRICK	: 2
**		BUSH	: 3
**		BOX		: 4
**		BOOK	: 5
**		WALL4	: 6
**		WALL3	: 7
**		WALL2	: 8
**		WALL	: 9
*/
typedef enum		e_tile
{
	FLOOR,
	WOOD,
	BRICK,
	BUSH,
	BOX,
	BOOK,
	WALL4,
	WALL3,
	WALL2,
	WALL
}					t_tile;

typedef enum		e_thread_state
{
	RUN,
	PAUSE,
	STOP
}					t_thread_state;

typedef enum		e_mob_type
{
	SHOOTER,
	SLAYER,
}					t_mob_type;

typedef enum		e_orientation
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}					t_orientation;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vector;

typedef struct		s_camera
{
	double			angle;
	int				fov;
	int				fps;
	double			half_scr;
	double			f;
	double			sensi;
	double			min_cam_mvt;
	double			max_cam_mvt;
	SDL_Rect		screen;
	SDL_Thread		*refresh_cam;
	t_thread_state	state;

}					t_camera;

typedef struct		s_mutexes
{
	SDL_mutex		*environment;
	SDL_mutex		*mob_mvt;
}					t_mutexes;

typedef struct		s_sdl_core
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				width;
	int				height;
	int				fullscreen;
}					t_sdl_core;

typedef struct		s_texture
{
	SDL_Texture		*text;
	int				w;
	int				h;
	double			mapping_fact;
}					t_texture;

typedef struct		s_sprite
{
	t_texture		*pic;
	SDL_Rect		current;
	double			mapping_fact;
	int				m_width;
	int				ms;
}					t_sprite;

typedef struct		s_thread
{
	SDL_Thread		*ptr;
	SDL_mutex		*mutex;
	t_thread_state	state;
}					t_thread;

typedef struct		s_ray_data
{
	t_vector		i;
	double			h;
	int				y;
	struct s_mob	*next;
}					t_ray_data;

typedef struct		s_npc_spts
{
	t_sprite		*spt_front;
	t_sprite		*spt_back;
	t_sprite		*spt_left;
	t_sprite		*spt_right;
}					t_npc_spts;

typedef struct		s_hitbox
{
	double			x;
	double			y;
	double			xmax;
	double			ymax;
	struct s_map	*xminymin;
	struct s_map	*xminymax;
	struct s_map	*xmaxymin;
	struct s_map	*xmaxymax;
}					t_hitbox;

typedef struct		s_map_data
{
	char			*path;
	int				reflection;
	double			brightness;
	double			bg_fact;
	t_texture		*bgd;
	SDL_Texture		*floor_ceiling_txt;
	SDL_Color		floor;
	SDL_Color		ceiling;
}					t_map_data;

typedef struct		s_map
{
	t_vector		min;
	t_vector		max;
	t_tile			type;
	t_texture		*textures[4];
	t_texture		*reflections[4];
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
	int				last_mvt_nb;
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
	t_orientation	side;
	t_map			*h_wall;
	t_map			*v_wall;
	t_vector		h_i;
	t_vector		v_i;
	Uint8			filter;
}					t_ray;

#endif
