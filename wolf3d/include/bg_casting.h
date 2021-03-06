/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_casting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 22:16:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/26 15:11:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BG_CASTING_H
# define BG_CASTING_H
# include "structures.h"

void	cast_background(t_ray *ray, int i, t_player *player);
void	cast_floor_ceiling(t_player *plr);
int		cast_reflection(t_ray *ray, int i, t_player *player);

#endif
