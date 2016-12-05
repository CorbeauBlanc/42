/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:01:07 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/05 13:48:39 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_lst_size(t_piece *piece)
{
	int		count;

	count = 0;
	while (piece != NULL)
	{
		++count;
		piece = piece->next;
	}
	return (count);
}

int			ft_better_lst_size(t_piece *piece)
{
	return (piece ? 1 + ft_better_lst_size(piece->next) : 0);
}
