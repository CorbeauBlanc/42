/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:55:57 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/10 19:51:19 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*new_fractal(char *name, int (*fct)(), double zoom)
{
	t_fractal	*ftl;
	if (!(ftl = malloc(sizeof(t_fractal))))
		return (NULL);
	ftl->name = name;
	ftl->is_in_fract = fct;
	ftl->zoom = zoom;
	return (ftl);
}

t_fractal	*get_fractal(char *name, t_fractal *ftl_tab)
{
	while (ftl_tab && !ft_strequ(ftl_tab->name, name))
			++ftl_tab;
	return (ftl_tab);
}

t_fractal	**init_ftl_tab()
{
	t_fractal	**tab;

	if (!(tab = malloc(NB_FTLS * sizeof(t_fractal*) + 1)))
		return (NULL);
	tab[0] = create_mandelbrot();
	tab[NB_FTLS] = NULL;
	return (tab);
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
