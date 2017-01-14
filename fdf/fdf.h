/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:52 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/14 13:01:22 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 500
# define WIDTH 500

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "structures.h"

double		dabs(double f);

t_mlx_core	*get_mlx_core(void);
void		mlx_draw_line(t_vector *pt1, t_vector *pt2);
void		mlx_draw_quadrangle(t_vector *pt1, t_vector *pt2,
								t_vector *pt3, t_vector *pt4);

t_matrix	*create_matrix(double **mat, int r, int c);
t_matrix	*create_identity(int i);
void		delete_matrix(t_matrix **matrix);
t_matrix	*mult_matrix(t_matrix *m1, t_matrix *m2);
void		mult_vector(t_vector *dest, t_matrix *mtx, t_vector *vec);

t_vector	*create_vector(double x, double y, double z);
void		insert_cell(t_map **head, t_map *cell);
t_map		*new_cell(t_vector *vect);

t_matrix	*translation(double x, double y, double z);
t_matrix	*x_rotation(double theta);
t_matrix	*y_rotation(double theta);
t_matrix	*z_rotation(double theta);
t_matrix	*scale(double x, double y, double z);

#endif
