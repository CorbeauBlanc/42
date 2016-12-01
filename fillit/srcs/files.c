/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:01:27 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/01 15:57:21 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*get_next_line(int fd)
{
	char		c;
	char		*str;
	size_t		len;

	len = 0;
	if (!(str = malloc(1)))
		return (NULL);
	*str = '\0';
	while (read(fd, &c, 1) && c != '\n')
	{
		if (!(ft_strrealloc((const char**)&str, (++len) + 1)))
			return (NULL_free(str));
		str[len - 1] = c;
	}
	if (!(ft_strrealloc((const char**)&str, (++len) + 1)))
		return (NULL_free(str));
	str[len - 1] = c;
	return (str);
}

t_piece			*create_pieces_list(char *file_path)
{
	int			fd;
	int			stop;
	char		**piece;
	t_piece		*head;
	t_piece		**tmp;

	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (NULL);
	piece = NULL;
	stop = 0;
	tmp = &head;
	while (!stop)
	{
		if (!(piece = get_next_piece(fd)))
			return (NULL_free_list(tmp));
		if (!(head = insert_piece(&head, new_piece(piece))))
			return (NULL_free_list(tmp));
		free_tab(&piece);
		stop = (*((*piece) = get_next_line(fd)) != '\n');
		free_tab(&piece);
	}
	return (*tmp);
}
