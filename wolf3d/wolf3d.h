/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:52 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/27 21:21:15 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define TITLE			"Wolf3D"
# define HEIGHT 		1000
# define WIDTH 			1000
# define BUFF_SIZE		1024
# define SCALE_XY		50
# define SCALE_Z		1

# ifndef __APPLE__
#  define K_Z			233
#  define K_Q			97
#  define K_S			117
#  define K_D			105
#  define K_I			100
#  define K_O			108
#  define K_UP			65362
#  define K_LEFT		65361
#  define K_DOWN		65364
#  define K_RIGHT		65363
#  define K_ECHAP		65307
# else
#  define K_Z			13
#  define K_Q			0
#  define K_S			1
#  define K_D			2
#  define K_I			34
#  define K_O			31
#  define K_UP			126
#  define K_LEFT		123
#  define K_DOWN		125
#  define K_RIGHT		124
#  define K_ECHAP		53
# endif
# define K_PRESS_MASK	(1L<<0)
# define K_PRESS_EVT	2

# include <stdlib.h>
# include <stdio.h>
//# include <SDL.h>
# include "SDL.h"
# include "libft.h"
# include "structures.h"

/*
** graphics.c
*/
SDL_Window	*SDL_GetMainWindow();
void		put_string(int x, int y, char *str);

/*
** images.c
*/
void		clear_image(t_image *img);
t_image		*create_image(int width, int height, int depth);
void		delete_image(t_image *img);
void		display_image(t_image *img, int x, int y);

/*
** img_graphics.c
*/
void		mlx_draw_line_img(t_image *img, t_vector *pt1, t_vector *pt2);
void		mlx_pixel_put_img(t_image *img, int x, int y, int color);

/*
** key_events.c
*/
void		clear_key_evts(t_key_evt **head);
void		delete_key_evt(t_key_evt **head);
t_key_evt	*init_key_evts(int key, void (*fct)(), void *arg);
int			key_hook(int key, void *param);
void		new_key_evt(t_key_evt **head, int key, void (*fct)());

/*
** key_functions_*.c
*/
void		rotate_down(void *arg);
void		rotate_left(void *arg);
void		rotate_right(void *arg);
void		rotate_up(void *arg);
void		translate_down(void *arg);
void		translate_left(void *arg);
void		translate_right(void *arg);
void		translate_up(void *arg);

/*
** transformations.c
*/
void		translation();
void		rotation();

/*
** vectors.c
*/
t_vector	*create_vector(double x, double y, double z);

#endif
