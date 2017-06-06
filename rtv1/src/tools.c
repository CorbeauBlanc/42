/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:35:27 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 17:50:15 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_rect_dim(SDL_Rect *rect, int w, int h)
{
	rect->h = h;
	rect->w = w;
}

void	set_rect_crd(SDL_Rect *rect, int x, int y)
{
	rect->x = x;
	rect->y = y;
}