/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:55:57 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/15 21:07:10 by edescoin         ###   ########.fr       */
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
	tab[0] = create_julia();
	tab[NB_FTLS] = NULL;
	return (tab);
}

void		delete_ftl_tab(t_fractal **tab)
{
	t_fractal	**tmp;

	tmp = tab;
	while (*tmp)
	{
		free(*tmp);
		++tmp;
	}
	free(tab);
}

void		draw_fractal(t_image *img, t_fractal *ftl)
{
	int	x;
	int	y;
	int	i;
	t_complex	test;

	test.img_part = 0.01;
	test.real_part = 0.285;
	x = -1;
	while (++x < img->width)
	{
		y = -1;
		while (++y < img->height)
			if ((i = ftl->is_in_fract((x / ftl->zoom) + ftl->x_min,
									(y / ftl->zoom) + ftl->y_min,
									ftl->precision, &test)))
				mlx_pixel_put_img(img, x, y, (/*ftl->precision /*/ i) * 0x00000011);
	}
	display_image(img, 0, 0);
}
