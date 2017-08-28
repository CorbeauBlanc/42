/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 16:14:58 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/14 16:35:47 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray	*new_ray(const t_dot *d1, const t_dot *d2)
{
	t_ray	*ray;

	if (!(ray = malloc(sizeof(t_ray))))
		exit_error("rtv1", "malloc");
	init_equation(&ray->eq,
				&(t_vector){d2->x - d1->x, d2->y - d1->y, d2->y - d1->z},
				(t_vector*)d1);
	return (ray);
}

void	init_ray(t_ray *ray, const t_dot *d1, const t_dot *d2)
{
	init_equation(&ray->eq,
				&(t_vector){d2->x - d1->x, d2->y - d1->y, d2->y - d1->z},
				(t_vector*)d1);
}
