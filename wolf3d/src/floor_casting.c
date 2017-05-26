/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 21:44:35 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/23 21:51:47 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>


static void	draw_floor_ceiling_strip(int i, SDL_Surface *tmp, SDL_Color *col)
{
	SDL_Rect	dim;
	Uint8		filter;
	t_player	*plr;

	plr = get_player();
	set_rect_crd(&dim, 0, i);
	set_rect_dim(&dim, SDL_GetCore()->width, 1);
	filter = get_filter_value(plr->tile->data, ((WALL_SIZE / 2) * plr->cam->f) /
												fabs((i - plr->cam->half_scr)));
	SDL_FillRect(tmp, &dim, get_color(col->r * (filter / 255.0),
									col->g * (filter / 255.0),
									col->b * (filter / 255.0)));
}

void	cast_floor_ceiling(t_player *plr)
{
	SDL_Surface	*tmp;
	int			i;

	tmp = SDL_CreateRGBSurface(0, SDL_GetCore()->width, SDL_GetCore()->height,
								32, 0, 0, 0, 0);
	i = plr->cam->half_scr;
	while (++i <= SDL_GetCore()->height)
		draw_floor_ceiling_strip(i - 1, tmp, &plr->tile->data->floor);
	i = plr->cam->half_scr;
	if (!(plr->tile->data->bgd))
		while (--i)
			draw_floor_ceiling_strip(i, tmp, &plr->tile->data->ceiling);
	SDL_DestroyTexture(plr->tile->data->floor_ceiling_txt);
	plr->tile->data->floor_ceiling_txt = SDL_CreateTextureFromSurface(
											SDL_GetCore()->renderer, tmp);
	SDL_RenderCopy(SDL_GetCore()->renderer, plr->tile->data->floor_ceiling_txt,
					NULL, NULL);
	SDL_FreeSurface(tmp);
}
