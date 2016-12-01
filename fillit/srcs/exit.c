/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:17:16 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/01 18:43:36 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		exit_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void		*error_free(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

int			error_free_int(char *str)
{
	if (str != NULL)
		free(str);
	return (FALSE);
}

int			error_free_tab(char **tab)
{
	int		count;

	count = -1;
	if (tab != NULL)
	{
		while (tab[++count] != NULL)
			if (tab[count] != NULL)
				free(tab[count]);
		free(tab);
	}
	return (FALSE);
}

void		exit_error_free_list(t_piece **piece)
{
	free_list(piece);
	ft_putendl("error");
	exit(EXIT_FAILURE);
}
