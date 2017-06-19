/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:35:27 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/19 12:13:40 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

void	get_quad_equation_sol(t_dot *res, double a, double b, double c)
{
	double	delta;

	delta = pow(b, 2) - 4 * a * c;
	if (delta >= 0)
	{
		res->x = (-b - sqrt(delta)) / (2 * a);
		res->y = (-b + sqrt(delta)) / (2 * a);
		res->w = 1;
	}
	else
		res->w = 0;
}
void	set_rect_dim(SDL_Rect *rect, int w, int h)
{
	rect->h = h;
	rect->w = w;
}

void	set_rect_crd(SDL_Rect *rect, int x, int y)
{
	rect->x = x;
	rect->y = y;
}
