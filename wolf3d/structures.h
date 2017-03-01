/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/01 16:36:15 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum			e_tile
{
						FLOOR,
						WALL
}						t_tile;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
	double				w;
}						t_vector;

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

typedef struct			s_camera
{
	int					fov;
	double				f;
	double				angle;
	t_image				*screen;
}						t_camera;

typedef struct			s_map
{
	t_vector			min;
	t_vector			max;
	t_tile				type;
	struct s_map		*r_head;
	struct s_map		*c_head;
	struct s_map		*left;
	struct s_map		*right;
	struct s_map		*up;
	struct s_map		*down;
}						t_map;

typedef struct			s_player
{
	t_camera			*cam;
	t_vector			position;
	t_map				*tile;
}						t_player;

#endif
