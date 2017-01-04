/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/04 19:41:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_vector
{
	int			x;
	int			y;
	int			z;
}				t_vector;

typedef struct	s_matrix
{
	int			*mat;
	int			m;
	int			n;
}				t_matrix;

typedef struct	s_mlx_core
{
	void		*co;
	void		*win;
}				t_mlx_core;

#endif
