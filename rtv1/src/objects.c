/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:32:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/01 13:10:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	*new_object(t_type type, double (*intersect)(),
						t_vector *(*get_normal)(t_dot*, struct s_object*),
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
	return (obj);
}
