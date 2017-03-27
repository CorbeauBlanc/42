/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:43:44 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/27 19:58:23 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "structures.h"

void	draw_vert_line(t_screen *scr, int x, double h, t_ray *ray);
t_ray	*horiz_intersec(t_ray *ray, t_player *player);
t_ray	*vert_intersec(t_ray *ray, t_player *player);

#endif
