/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_smaller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:00:37 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/01 19:42:30 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**test_square(char **tab, t_piece *piece)
{
	(void)tab;
	(void)piece;
	return (NULL);
}

static char		**fill_tab(char **tab, int size_square, t_piece *piece)
{
	int			count;
	int			count2;

	count = -1;
	while (++count <= size_square)
		tab[count] = NULL;
	count = -1;
	while (++count < size_square)
	{
		if ((tab[count] = malloc((size_square + 1) * sizeof(char))) == NULL)
		{
			error_free_tab(tab);
			exit_error_free_list(&piece);
		}
		count2 = -1;
		while (++count2 < size_square)
			tab[count][count2] = '.';
		tab[count][count2] = '\0';
	}
	return (tab);
}

static char		**prepare_tab(int size_square, t_piece *piece)
{
	char		**tab;

	if ((tab = malloc((size_square + 1) * sizeof(char *))) == NULL)
		exit_error_free_list(&piece);
	tab = fill_tab(tab, size_square, piece);
	if ((tab = test_square(tab, piece)) == NULL)
	{
		error_free_tab(tab);
		return (NULL);
	}
	else
		return (tab);
}

void			search_smaller(t_piece *piece)
{
	int			count;
	char		**tab;
	int			size_square;

	tab = NULL;
	size_square = ft_sqrt_sup(4 * ft_lst_size(piece));
	while (tab == NULL)
	{
		tab = prepare_tab(size_square, piece);
		++size_square;
	}
	count = -1;
	while (tab[++count] != NULL)
	{
		ft_putendl(tab[count]);
		free(tab[count]);
	}
	free(tab);
	free_list(&piece);
}
