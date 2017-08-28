/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:32:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/08 16:47:15 by edescoin         ###   ########.fr       */
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
	obj->scale = create_identity(4);
	obj->scale_inv = create_identity(4);
	obj->color = (SDL_Color){255, 255, 255, 255};
	return (obj);
}

void		delete_object(t_object *obj)
{
	t_box	*tmp;

	if (obj)
	{
		delete_matrix(obj->rot);
		delete_matrix(obj->rot_inv);
		delete_matrix(obj->trans);
		delete_matrix(obj->trans_inv);
		delete_matrix(obj->scale);
		delete_matrix(obj->scale_inv);
		if (obj->obj_type == BOX)
		{
			tmp = (t_box*)obj;
			delete_object((t_object*)tmp->front);
			delete_object((t_object*)tmp->back);
			delete_object((t_object*)tmp->top);
			delete_object((t_object*)tmp->bottom);
			delete_object((t_object*)tmp->left);
			delete_object((t_object*)tmp->right);
		}
		free(obj);
	}
}
