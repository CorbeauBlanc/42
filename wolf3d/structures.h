/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/08 18:42:53 by edescoin         ###   ########.fr       */
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

typedef struct		s_key_data
{
	SDL_Keycode		key;
	int				(*fct)();
}					t_key_data;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vector;

typedef struct		s_image
{
	int				width;
	int				height;
	void			*ptr;
	char			*data;
	int				depth;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_screen
{
	SDL_Texture		*texture;
	Uint32			*pxl_tab;
	int				width;
	int				height;
	int				pitch;
}					t_screen;

typedef struct		s_camera
{
	int				fov;
	double			half_scr;
	double			f;
	int				angle;
	t_screen		*screen;
}					t_camera;

typedef struct		s_SDL_Core
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	int				width;
	int				height;
}					t_SDL_Core;

typedef struct		s_event
{
	SDL_EventType	type;
	void			*data;
	int				(*fct)();
	struct s_event	*next;
}					t_event;

typedef struct		s_map
{
	t_vector		min;
	t_vector		max;
	t_tile			type;
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
	t_vector		position;
	t_map			*tile;
}					t_player;

#endif
