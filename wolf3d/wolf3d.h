/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:52 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/01 17:07:55 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define TITLE			"Wolf3D"
# define HEIGHT 		700
# define WIDTH 			700
# define WALL_SIZE		16
# define BUFF_SIZE		1024

# include <SDL2/SDL.h>
//# include "SDL.h"

# ifndef __APPLE__
#  define SDL_VIDEO		SDL_VIDEO_DRIVER_X11
# else
#  define SDL_VIDEO		SDL_VIDEO_DRIVER_COCOA
# endif

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "structures.h"

/*
** camera.c
*/
void		delete_camera(t_camera *cam);
t_camera	*new_camera(int fov);
void		set_camera_crd(t_camera *cam, double h_ang, double v_ang, double d);
void		set_camera_fov(t_camera	*cam, int fov);

/*
** graphics.c
*/
typedef struct		s_SDL_Core
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}					t_SDL_Core;
t_SDL_Core			*SDL_GetCore();
void				put_string(int x, int y, char *str);

/*
** images.c
*/
void				clear_image(t_image *img);
t_image				*create_image(int width, int height, int depth);
void				delete_image(t_image *img);
void				display_image(t_image *img, int x, int y);

/*
** img_graphics.c
*/
void				mlx_draw_line_img(t_image *img, t_vector *pt1, t_vector *pt2);
void				mlx_pixel_put_img(t_image *img, int x, int y, int color);

/*
** events.c
*/
typedef struct		s_event
{
	SDL_EventType	type;
	void			*data;
	int				(*fct)();
	struct s_event	*next;
}					t_event;
void				clear_events(t_event **head);
void				delete_event(t_event **head);
void				new_event(t_event **head, SDL_EventType type, void *data, int (*fct)());
void				wait_events(t_event *list_evts);

/*
** key_events.c
*/
typedef struct		s_key_data
{
	SDL_Keycode		key;
	int				(*fct)();
}					t_key_data;
t_key_data			*new_key_data(SDL_Keycode key, int (*fct)());
int					key_hook(SDL_Event evt, t_event *list_evts);

/*
** key_functions_*.c
*/
void				rotate_down(void *arg);
void				rotate_left(void *arg);
void				rotate_right(void *arg);
void				rotate_up(void *arg);
void				translate_down(void *arg);
void				translate_left(void *arg);
void				translate_right(void *arg);
void				translate_up(void *arg);

/*
** main.c
*/
void				exit_error(char *s);
void				exit_main();

/*
** map.c
*/
void		delete_map(t_map *map);
t_map		*read_file(int fd);

/*
** transformations.c
*/
void				translation();
void				rotation();

/*
** vectors.c
*/
t_vector	*create_vector(double x, double y, double z);
t_map		*insert_cell(t_map *head, t_map *cell);
t_map		*new_cell(t_vector *vect, t_tile type);

#endif
