/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:52 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/07 19:05:00 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 		1000
# define WIDTH 			1000

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
# include "libft.h"
# include "structures.h"

/*
** graphics.c
*/
t_mlx_core	*mlx_get_core(void);
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
void		mlx_draw_line_img(t_image *img, t_vector *pt1, t_vector *pt2,
							t_map *map);
void		mlx_pixel_put_img(t_image *img, int x, int y, int color);

/*
** key_events.c
*/
void		clear_key_evts(t_key_evt **head);
void		delete_key_evt(t_key_evt **head);
t_key_evt	*init_key_evts(int key, void (*fct)(), t_camera *cam, t_map *map);
int			key_hook(int key, void *param);
void		new_key_evt(t_key_evt **head, int key, void (*fct)());

/*
** key_functions_*.c
*/
void		rotate_down(t_camera *cam, t_map *map);
void		rotate_left(t_camera *cam, t_map *map);
void		rotate_right(t_camera *cam, t_map *map);
void		rotate_up(t_camera *cam, t_map *map);
void		translate_down(t_camera *cam, t_map *map);
void		translate_left(t_camera *cam, t_map *map);
void		translate_right(t_camera *cam, t_map *map);
void		translate_up(t_camera *cam, t_map *map);
void		zoom_in(t_camera *cam, t_map *map);
void		zoom_out(t_camera *cam, t_map *map);

/*
** main.c
*/
void		exit_main();

/*
** vectors.c
*/
t_vector	*create_vector(double x, double y, double z);

#endif
