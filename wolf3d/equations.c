/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:04:03 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/27 21:37:12 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_equation(t_equation *eq, t_vector *a, t_vector *b)
{
	eq->ax = (b->y - a->y) / (b->x - a->x);
	eq->b = a->y - eq->ax * a->x;
}

void	set_equation2(t_equation *eq, t_vector *v, double angle)
{
	t_vector	tmp;

	set_vect_crd(&tmp, v->x + cos(angle), v->y + sin(angle));
	set_equation(eq, v, &tmp);
}

void	get_int_pt(t_equation *eq1, t_equation *eq2, t_vector *i)
{
	i->x = (eq2->b - eq1->b) / (eq1->ax - eq2->ax);
	i->y = eq1->ax * i->x + eq1->b;
}
