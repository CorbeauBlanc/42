/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:57:46 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/07 17:55:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	empty_left(t_piece **piece)
{
	int		count;

	count = -1;
	while (++count < 4)
	{
		if ((*piece)->tab[count][0] == '#')
			return (FALSE);
	}
	return (TRUE);
}

static void	fill_left(t_piece **piece)
{
	int		count;
	int		count2;

	while (empty_left(piece) == TRUE)
	{
		count = -1;
		while ((*piece)->tab[++count] != NULL)
		{
			count2 = -1;
			while ((*piece)->tab[count][++count2] != '\0')
				if ((*piece)->tab[count][count2] == '#')
				{
					(*piece)->tab[count][count2 - 1] = '#';
					(*piece)->tab[count][count2] = '.';
				}
		}
	}
}

static int	empty_top(t_piece **piece)
{
	int		count;

	count = -1;
	while (++count < 4)
		if ((*piece)->tab[0][count] == '#')
			return (FALSE);
	return (TRUE);
}

static void	fill_top(t_piece **piece)
{
	int		count;
	int		count2;

	while (empty_top(piece) == TRUE)
	{
		count = -1;
		while ((*piece)->tab[++count] != NULL)
		{
			count2 = -1;
			while ((*piece)->tab[count][++count2] != '\0')
				if ((*piece)->tab[count][count2] == '#')
				{
					(*piece)->tab[count - 1][count2] = '#';
					(*piece)->tab[count][count2] = '.';
				}
		}
	}
}

void		move_piece(t_piece *piece)
{
	while (piece != NULL)
	{
		fill_left(&piece);
		fill_top(&piece);
		piece = piece->next;
	}
}
