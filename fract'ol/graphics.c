/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:52:28 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/08 21:22:13 by edescoin         ###   ########.fr       */
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

void				put_string(int x, int y, char *str)
{
	t_mlx_core *core;

	core = mlx_get_core(0,0);
	mlx_string_put(core->co, core->win, x, y, 0xFFFFFF, str);
}
