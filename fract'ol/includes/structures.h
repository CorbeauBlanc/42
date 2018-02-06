/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/03 22:09:10 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct			s_image
{
	int					width;
	int					height;
	void				*ptr;
	char				*data;
	int					depth;
	int					size_line;
	int					endian;
	int					o_x;
	int					o_y;
	int					disp_cross;
}						t_image;

typedef struct			s_mlx_core
{
	void				*co;
	void				*win;
}						t_mlx_core;

typedef struct			s_complex
{
	double				img_part;
	double				real_part;
}						t_complex;

typedef struct			s_fractal
{
	char				*name;
	int					(*is_in_fract)();
	double				x_min;
	double				x_max;
	double				y_min;
	double				y_max;
	double				zoom;
	t_complex			init;
	int					move;
	int					precision;
	int					(*get_color)();
}						t_fractal;

typedef struct			s_mouse_evt
{
	t_fractal			*ftl;
	t_image				*img;
}						t_mouse_evt;

typedef struct			s_key_evt
{
	int					key;
	void				(*fct)();
	void				*param;
	struct s_key_evt	*next;
}						t_key_evt;

#endif
