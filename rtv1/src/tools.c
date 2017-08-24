/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:35:27 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/24 14:45:14 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

int		get_quad_equation_sol(t_dot *res, double a, double b, double c)
{
	double	delta;

	if (!a)
	{
		if (b && c)
			set_dot(res, -c / b, -c / b, 0);
		if (!b && c)
			return (0);
		else if (!b && !c)
			set_dot(res, 0, 0, 0);
		return (1);
	}
	delta = pow(b, 2) - 4 * a * c;
	if (delta > 0)
	{
		set_dot(res, (-b - sqrt(delta)) / (2 * a), (-b + sqrt(delta)) / (2 * a),
				0);
		return (1);
	}
	else if (delta == 0)
		set_dot(res, -b / (2 * a), -b / (2 * a), 0);
	return (0);
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
