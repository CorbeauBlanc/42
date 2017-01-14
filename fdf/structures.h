/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/14 16:58:36 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vector;

typedef struct		s_matrix
{
	double			**mat;
	int				r;
	int				c;
}					t_matrix;

typedef struct		s_mlx_core
{
	void			*co;
	void			*win;
}					t_mlx_core;

typedef struct		s_map
{
	t_vector		*vector;
	struct s_map	*head;
	struct s_map	*left;
	struct s_map	*right;
	struct s_map	*up;
	struct s_map	*down;
}					t_map;

typedef struct		s_file_crds
{
	int				x;
	int				y;
	int				len;
	int				fd;
}					t_file_crds;

#endif
