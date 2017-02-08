/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:55:57 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/08 20:40:21 by edescoin         ###   ########.fr       */
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
