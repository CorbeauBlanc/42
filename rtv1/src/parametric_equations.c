/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parametric_equations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:07:13 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/14 16:35:39 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_param_eq	*new_equation(const t_vector *vdir, const t_vector *vconst)
{
	t_param_eq	*eq;

	if (!(eq = malloc(sizeof(t_param_eq))))
		exit_error("rtv1", "malloc");
	eq->vconst = *vconst;
	eq->vdir = *vdir;
	return (eq);
}

void		init_equation(t_param_eq *eq, const t_vector *vdir,
							const t_vector *vconst)
{
	eq->vconst = *vconst;
	eq->vdir = *vdir;
}

t_dot		*equation_get_dot(t_dot *res, t_param_eq *eq, double t)
{
	if (!res)
		res = new_dot(0, 0, 0);
	res->x = eq->vdir.x * t + eq->vconst.x;
	res->y = eq->vdir.y * t + eq->vconst.y;
	res->z = eq->vdir.z * t + eq->vconst.z;
	return (res);
}
