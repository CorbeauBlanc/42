/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:17:16 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/01 14:44:55 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		exit_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void		exit_error_free(char *str)
{
	if (str != NULL)
		free(str);
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void		exit_error_free_tab(char **tab)
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
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void		*NULL_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

void		*NULL_free_list(t_piece **head)
{
	free_list(head);
	return (NULL);
}
