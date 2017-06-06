/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:36 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 17:23:21 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
#include "structures.h"

/*
** graphics.c
*/
Uint32		get_color(int r, int g, int b);
void		refresh_win();
void		delete_sdl_core();
t_sdl_core	*get_sdl_core();

#endif
