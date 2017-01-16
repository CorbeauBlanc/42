/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:52 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/16 20:48:51 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 1000
# define WIDTH 1000

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "structures.h"

/*
** 3D_graphics.c
*/
t_camera	*new_camera(int fov);
void		projection(t_camera *cam, t_map *map);
void		set_camera_fov(t_camera	*cam, int fov);
void		transform_map(t_map *map, t_matrix *mat);

/*
** graphics.c
*/
t_mlx_core	*get_mlx_core(void);
void		mlx_draw_line(t_vector *pt1, t_vector *pt2);
void		mlx_draw_quadrangle(t_vector *pt1, t_vector *pt2,
								t_vector *pt3, t_vector *pt4);

/*
** main.c
*/
double		dabs(double f);
double		to_deg(double rad);
double		to_rad(int deg);

/*
** matrix.c
*/
t_matrix	*create_matrix(double **mat, int r, int c);
t_matrix	*create_identity(int i);
void		delete_matrix(t_matrix **matrix);
t_matrix	*mult_matrix(t_matrix *m1, t_matrix *m2);
void		mult_vector(t_vector *dest, t_matrix *mtx, t_vector *vec);

/*
** tools.c
*/
t_map		*read_file(char *path);
int			is_in_window(t_vector *vect);

/*
** transformations.c
*/
t_matrix	*translation(double x, double y, double z);
t_matrix	*x_rotation(double theta);
t_matrix	*y_rotation(double theta);
t_matrix	*z_rotation(double theta);
t_matrix	*scale(double x, double y, double z);

/*
** vectors.c
*/
t_vector	*create_vector(double x, double y, double z);
t_map		*insert_cell(t_map *head, t_map *cell);
t_map		*new_cell(t_vector *vect);
void		transform_vector(t_vector *dest, t_vector *vect, double d);

#endif
