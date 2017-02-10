/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:26:44 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/10 19:16:59 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int			get_color(void)
{
	return (0);
}

void		mlx_pixel_put_img(t_image *img, int x, int y, int color)
{
	int bytes;

	if (x < img->width && y < img->height && x >= 0 && y >= 0)
	{
		bytes = img->depth / 8;
		*((int*)(img->data + y * img->size_line + x * bytes)) = color;
	}
}

void		draw_fractal(t_image *img, t_fractal *ftl)
{
	int	x;
	int	y;

	x = -1;
	while (++x < img->width)
	{
		y = -1;
		while (++y < img->height)
			if (ftl->is_in_fract((x / ftl->zoom) + ftl->x_min,
								(y / ftl->zoom) + ftl->y_min))
				mlx_pixel_put_img(img, x, y, 0x00FFFFFF);
	}
	display_image(img, 0, 0);
}
