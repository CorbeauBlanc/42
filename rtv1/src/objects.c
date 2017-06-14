/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:32:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/13 16:49:08 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	*new_object(t_type type, void (*intersect)(), size_t size)
{
	t_object	*obj;

	if (!size)
		size = sizeof(t_object);
	if (!(obj = malloc(size)))
		exit_error("rtv1", "malloc");
	*(t_type*)&obj->obj_type = type;
	obj->intersect = intersect;
	return (obj);
}

t_sphere	*new_sphere(double x, double y, double z, double radius)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)new_object(SPHERE, NULL, sizeof(t_sphere));
	sphere->radius = radius;
	set_dot(&sphere->center, x, y, z);
	return (sphere);
}
