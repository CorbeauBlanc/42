/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:52:28 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/03 19:40:48 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include <mlx.h>

void	draw_line(t_vector *pt1, t_vector *pt2, t_mlx_core *core)
{
	double	m;
	double	e;
	int	x;
	int	y;

	m = (pt2->y - pt1->y) / (pt2->x - pt1->x);
	e = 0;
	x = pt1->x;
	y = pt1->y;
	while (++x <= pt2->x)
	{
		mlx_pixel_put(core->connection, core->window, x, y, 0x00FFFFFF);
		if (e + m < 0.5)
			e += m;
		else
		{
			e = e + m - 1;
			++y;
		}
	}
}
