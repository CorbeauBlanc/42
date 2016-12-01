/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_smaller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:00:37 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/01 18:52:28 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**prepare_tab(int size_square, t_piece *piece)
{
	int			count;
	char		**tab;

	if ((tab = malloc((size_square + 1) * sizeof(char))) == NULL)
		exit_error_free_list(&piece);
	count = -1;
	while (++count <= size_square)
		tab[count] = NULL;
	count = -1;
	while (++count < size_square)
	{
		if ((tab = malloc((size_square + 1) * sizeof(char))) == NULL)
		{
			free_list(&piece);
			exit_error_free_tab(tab);
		}
		while (++count2 < size_square)
			tab[count][count2] = '.';
		tab[count][count2] = '\0';
	}
	if ((tab = test_square()) == NULL)
		return (NULL);
	else
		return (tab);
}

void			search_smaller(t_piece *piece)
{
	int			count;
	char		**tab;
	int			size_square;

	head = piece;
	tab == NULL;
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
	delete_piece(&piece);
}
