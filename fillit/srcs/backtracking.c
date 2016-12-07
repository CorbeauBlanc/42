/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:15:42 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/07 17:36:20 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_square(char **tab, t_piece *piece)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	if (!piece)
		return (1);
	while (tab[++x])
	{
		y = -1;
		while (tab[x][++y])
		{
			if (check_posibility(tab, piece, x, y) == TRUE);
			{
				put_piece(tab, x, y, piece);
				if (!(get_square(tab, piece->next)))
					delete_piece_tab(tab, piece);
				else
					return (0);
			}
		}
	}
	return (tab[x] != NULL);
}

static int	check_posibility(char **tab, t_piece *piece, int pos_x, int pos_y)
{
	int		count1;
	int		count2;
	int		size_tab;

	size_tab = ft_strlen(tab[0]);
	count1 = -1;
	while (++count1 < 4)
	{
		count2 = -1;
		while (++count2 < 4)
			if (piece->tab[count1][count2] != '.')
			{
				if ((count1 + pos_x) >= size_tab
					|| (count2 + pos_y) >= size_tab)
					return (FALSE);
				if (tab[count1 + pos_x][count2 + pos_y] != '.')
					return (FALSE);
			}
	}
	return (TRUE);
}

static void	put_piece(char **tab, int x, int y, t_piece *current)
{
	int	i;
	int	j;
	int	stop;

	stop = 0;
	i = -1;
	while ((++i) < 4)
	{
		j = -1;
		while ((++j) < 4)
			if (current->tab[i][j] == '#')
				tab[i + x][j + y] = current->c;
	}
}

static void	delete_piece_tab(char **tab, t_piece *piece)
{
	int		count1;
	int		count2;

	count1 = -1;
	while (tab[++count1] != NULL)
	{
		count2 = -1;
		while (tab[count1][++count2] != '\0')
			if (tab[count1][count2] == piece->c)
				tab[count1][count2] = '.';
	}
}
