/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:45:33 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/15 13:52:48 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*insert_new_file(t_file **head, int fd)
{
	t_file	*cell;

	if (!head || !(cell = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	cell->fd = fd;
	cell->buffer = ft_strnew(BUFF_SIZE);
	if (!*head)
	{
		cell->next = NULL;
		cell->prev = NULL;
		cell->head = cell;
		*head = cell;
	}
	else
	{
		cell->head = (*head)->head;
		if ((*head)->next)
			(*head)->next->prev = cell;
		cell->next = (*head)->next;
		cell->prev = (*head);
		(*head)->next = cell;
	}
	return (cell);
}

void	delete_cell(t_file **cell)
{
	if (cell)
	{
		if ((*cell)->next)
			(*cell)->next->next = (*cell)->prev;
		if ((*cell)->prev)
			(*cell)->prev->next = (*cell)->next;
		free(*cell);
	}
}

t_file	*get_file(int fd, t_file *head)
{
	return (head && head->fd == fd ? head : get_file(fd, head->next));
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*list;
	char			*tmp;
	int				i;

	list = NULL;
	if (!list || !(list = get_file(fd, list->head)))
		list = insert_new_file(&list, fd);
	if (!(tmp = ft_memchr(list->buffer, '\n', BUFF_SIZE)
	{
		if ((i = read(fd, list->buffer, size_t)) > 0)
			return ((*line = ft_strcdup(list->buffer, '\n')) != NULL);
		else if (i == 0)
		{
			delete_cell(&list);
			return ((*line = ft_strcdup(list->buffer, '\n')) == NULL);
		}
		else
			return (-1);
	}
	else
	{
		*tmp = '0';
		return ((*line = ft_strcdup(tmp + 1, '\n')) != NULL)
	}
}
