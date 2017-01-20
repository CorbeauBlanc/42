/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:43:43 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/20 15:00:25 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

t_image	*create_image(int width, int height, int depth)
{
	t_image	*img;

	if (!(img = malloc(sizeof(t_image))))
		return (NULL);
	img->width = width;
	img->height = height;
	img->depth = depth;
	img->size_line = (depth / 8) * width;
	img->endian = 1;
	img->ptr = mlx_new_image(mlx_get_core()->co, width, height);
	img->data = mlx_get_data_addr(img->ptr, &img->depth,
								&img->size_line, &img->endian);
	return (img);
}

void	delete_image(t_image *img)
{
	mlx_destroy_image(mlx_get_core()->co, img->ptr);
	free(img);
}

void	mlx_pixel_put_img(t_image *img, int x, int y, unsigned int color)
{
	int bytes;

	if (x < img->width && y < img->height && x >= 0 && y >= 0)
	{
		bytes = img->depth / 8;
		*(img->data + y * img->size_line + x * bytes) = color;
	}
}

void	display_img(t_image *img, int x, int y)
{
	t_mlx_core	*core;

	core = mlx_get_core();
	mlx_put_image_to_window(core->co, core->win, img->ptr, x, y);
}
