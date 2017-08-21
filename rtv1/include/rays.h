/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 16:26:57 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 18:34:56 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H
# include "structures.h"

t_ray	*new_ray(const t_dot *d1, const t_dot *d2);
void	init_ray(t_ray *ray, const t_dot *d1, const t_dot *d2);

#endif
