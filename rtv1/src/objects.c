/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:32:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/11 18:02:33 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	*new_object(t_type type, double (*intersect)(),
						const t_vector *(*get_normal)(t_dot*, struct s_object*),
						size_t size)
{
	t_object	*obj;

	if (!size)
		size = sizeof(t_object);
	if (!(obj = malloc(size)))
		exit_error("rtv1", "malloc");
	*(t_type*)&obj->obj_type = type;
	obj->intersect = intersect;
	obj->get_normal = get_normal;
	obj->rot = create_identity(4);
	obj->rot_inv = create_identity(4);
	obj->trans = create_identity(4);
	obj->trans_inv = create_identity(4);
	return (obj);
}

void		delete_object(t_object *obj)
{
	delete_matrix(obj->rot);
	delete_matrix(obj->rot_inv);
	delete_matrix(obj->trans);
	delete_matrix(obj->trans_inv);
	free(obj);
}

void		rotate_object(t_object *obj, double x_angle, double y_angle, double z_angle)
{
	x_rotation(&obj->rot, x_angle);
	y_rotation(&obj->rot, y_angle);
	z_rotation(&obj->rot, z_angle);
	get_inv_3x3mat(obj->rot_inv, obj->rot);
}
