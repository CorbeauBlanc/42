/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:01:07 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/01 19:04:05 by kda-silv         ###   ########.fr       */
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
