/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:53:30 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/07 18:36:30 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*new_piece(char **tab, char c)
{
	t_piece	*cell;

	if (!(cell = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	cell->tab = tab;
	cell->c = c;
	cell->next = NULL;
	cell->prev = NULL;
	cell->head = cell;
	return (cell);
}

void	insert_piece(t_piece **head, t_piece *cell)
{
	if (!head || !cell)
	{
		delete_piece(&cell);
		exit_error_free_list(head);
	}
	if (!*head)
		*head = cell;
	else
	{
		if ((*head)->next)
			(*head)->next->prev = cell;
		cell->next = (*head)->next;
		cell->prev = *head;
		(*head)->next = cell;
		cell->head = (*head)->head;
	}
}

void	free_tab(char ***tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while ((*tab)[++i])
			free((*tab)[i]);
		free(*tab);
	}
}

void	delete_piece(t_piece **cell)
{
	t_piece	*tmp;

	if (cell && (tmp = *cell))
	{
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		free_tab(&tmp->tab);
		ft_memdel((void*)(*cell));
		*cell = NULL;
	}
}

void	*free_list(t_piece **head)
{
	if (head && *head)
		free_list(&(*head)->next);
	delete_piece(head);
	return (NULL);
}
