/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:03:53 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/31 18:21:02 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOB_CASTING_H
# define MOB_CASTING_H
# include "structures.h"

void	check_h_mob(t_ray *ray);
void	check_v_mob(t_ray *ray);
void	draw_mob(SDL_Rect *scr, int i, t_ray *ray, t_mob *mob);

#endif
