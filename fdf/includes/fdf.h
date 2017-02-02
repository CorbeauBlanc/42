/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:52 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/02 17:37:52 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 1000
# define WIDTH 1000
# define BUFF_SIZE 1024
# define SCALE_XY 50
# define SCALE_Z 1

# ifndef __APPLE__
#  define K_Z 233
#  define K_Q 97
#  define K_S 117
#  define K_D 105
#  define K_I 100
#  define K_O 108
#  define K_UP 65362
#  define K_LEFT 65361
#  define K_DOWN 65364
#  define K_RIGHT 65363
#  define K_ECHAP 65307
# else
#  define K_Z 13
#  define K_Q 0
#  define K_S 1
#  define K_D 2
#  define K_I 34
#  define K_O 31
#  define K_UP 126
#  define K_LEFT 123
#  define K_DOWN 125
#  define K_RIGHT 124
#  define K_ECHAP 53
# endif

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "structures.h"

/*
** camera.c
*/
void		delete_camera(t_camera *cam);
t_camera	*new_camera(int fov, double h_angle, double v_angle, double dist);
void		set_camera_crd(t_camera *cam, double h_ang, double v_ang, double d);
void		set_camera_fov(t_camera	*cam, int fov);

/*
** gb_collection.c
*/
void		garbage_collector(t_gbc_action action, void *ptr, void (*fct)());

/*
** graphics.c
*/
t_mlx_core	*mlx_get_core(void);
void		mlx_draw_line(t_vector *pt1, t_vector *pt2);
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
t_key_evt	*init_key_evts(int key, void (*fct)(), t_camera *cam, t_map *map);
void		clear_key_evts(t_key_evt **head);
void		delete_key_evt(t_key_evt **head);
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
** map.c
*/
void		delete_map(t_map *map);
t_map		*read_file(int fd);

/*
** map_projection.c
*/
void		projection(t_map *map, t_camera *cam);
void		transform_map(t_map *map, t_matrix *mat);

/*
** matrix.c
*/
void		clear_matrix(t_matrix *mat);
t_matrix	*create_matrix(double **mat, int r, int c);
t_matrix	*create_identity(int i);
void		delete_matrix(t_matrix *matrix);
t_matrix	*mult_matrix(t_matrix *m1, t_matrix *m2);

/*
** tools.c
*/
double		dabs(double f);
int			is_in_window(t_vector *vect);
double		max(double d1, double d2);
double		min(double d1, double d2);
double		to_rad(double deg);

/*
** transformations.c
*/
void		translation(t_matrix **mtx, double x, double y, double z);
void		x_rotation(t_matrix **mtx, double theta);
void		y_rotation(t_matrix **mtx, double theta);
void		z_rotation(t_matrix **mtx, double theta);
void		scale(t_matrix **mtx, double x, double y, double z);

/*
** vectors.c
*/
t_vector	*create_vector(double x, double y, double z);
t_map		*insert_cell(t_map *head, t_map *cell);
void		mult_vector(t_vector *dest, t_matrix *mtx, t_vector *vec);
t_map		*new_cell(t_vector *vect);
void		transform_vector(t_vector *dest, t_vector *vect, t_camera *cam);

#endif
