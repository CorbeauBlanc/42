/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:52 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/12 14:11:19 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 500
# define WIDTH 500

# include <stdlib.h>
# include <math.h>
# include "structures.h"

double		dabs(double f);

void		mlx_draw_line(t_vector *pt1, t_vector *pt2);
void		mlx_draw_quadrangle(t_vector *pt1, t_vector *pt2,
								t_vector *pt3, t_vector *pt4);
t_mlx_core	*get_mlx_core(void);

t_matrix	*create_matrix(int **mat, int m, int n);
void		delete_matrix(t_matrix **matrix);
t_vector	*create_vector(int x, int y, int z);

#endif
