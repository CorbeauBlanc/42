/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:52:28 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/03 22:18:37 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

t_mlx_core	*mlx_get_core(int width, int height)
{
	static t_mlx_core	*core = NULL;

	if (!core)
	{
		if (!(core = malloc(sizeof(t_mlx_core))))
			return (NULL);
		if (!(core->co = mlx_init()))
			return (NULL);
		core->win = mlx_new_window(core->co, width, height, "Fractol");
	}
	return (core);
}

void		put_string(int x, int y, char *str)
{
	t_mlx_core *core;

	core = mlx_get_core(0, 0);
	mlx_string_put(core->co, core->win, x, y, 0xFFFFFF, str);
}

void		draw_cross(t_image *img)
{
	int		i;

	if (img->disp_cross)
	{
		i = -1;
		while (++i < 20)
		{
			mlx_pixel_put_img(img, img->o_x - 10 + i, img->o_y - 1, 0xFFFFFF);
			mlx_pixel_put_img(img, img->o_x - 10 + i, img->o_y, 0xFFFFFF);
			mlx_pixel_put_img(img, img->o_x - 1, img->o_y - 10 + i, 0xFFFFFF);
			mlx_pixel_put_img(img, img->o_x, img->o_y - 10 + i, 0xFFFFFF);
		}
	}
}
