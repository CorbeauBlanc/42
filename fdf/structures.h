/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/21 15:06:56 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum			e_gbc_action
{
						ADD,
						REMOVE,
						CLEAR
}						t_gbc_action;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
	double				w;
}						t_vector;

typedef struct			s_tile
{
	t_vector			p1;
	t_vector			p2;
	t_vector			p3;
	t_vector			p4;
}						t_tile;

typedef struct			s_matrix
{
	double				**mat;
	int					r;
	int					c;
}						t_matrix;

typedef struct			s_mlx_core
{
	void				*co;
	void				*win;
}						t_mlx_core;

typedef struct			s_map
{
	t_vector			*vect;
	struct s_map		*r_head;
	struct s_map		*c_head;
	struct s_map		*left;
	struct s_map		*right;
	struct s_map		*up;
	struct s_map		*down;
}						t_map;

typedef struct			s_camera
{
	int					fov;
	double				f;
	double				theta;
	double				phi;
	double				r;
	t_matrix			*view;
}						t_camera;

typedef struct			s_image
{
	int					width;
	int					height;
	void				*ptr;
	char				*data;
	int					depth;
	int					size_line;
	int					endian;
}						t_image;

typedef struct			s_key_evt
{
	int					key;
	void				(*fct)();
	t_camera			*cam;
	t_map				*map;
	struct s_key_evt	*next;
}						t_key_evt;

typedef struct			s_garbage
{
	void				*ptr;
	void				(*delete)();
	struct s_garbage	*next;
	struct s_garbage	*prev;
}						t_garbage;

#endif
