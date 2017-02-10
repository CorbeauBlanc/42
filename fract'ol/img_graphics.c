/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:26:44 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/10 19:39:27 by edescoin         ###   ########.fr       */
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

int			is_in_img(int x, int y, t_image *img)
{
	return (x >= 0 && x <= img->width && y >= 0 && y <= img->height);
}
