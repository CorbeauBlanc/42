/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:32:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/12 20:07:44 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*new_sphere(double x, double y, double z, double radius)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		exit_error("rtv1", "malloc");
	*(t_type*)&sphere->obj_type = SPHERE;
	sphere->intersect = NULL;
	sphere->radius = radius;
	set_dot(&sphere->center, x, y, z);
	return (sphere);
}
