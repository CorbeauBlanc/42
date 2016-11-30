/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:01:27 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/28 16:58:26 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_next_line(int fd)
{
	char	c;
	char	*str;
	size_t	len;

	len = 0;
	if (!(str = malloc(1)))
		return (NULL);
	*str = '\0';
	while (read(fd, &c, 1) && c != '\n')
	{
		if (!(ft_strrealloc((const char**)&str, (++len) + 1)))
			return (NULL);
		str[len - 1] = c;
	}
	if (!(ft_strrealloc((const char**)&str, (++len) + 1)))
		return (NULL);
	str[len - 1] = c;
	return (str);
}

t_piece	*create_pieces_list(char *file_path)
{
	int		fd;
	int		stop;
	char	*piece;
	char	c;
	t_piece	*head;

	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (NULL);
	piece = NULL;
	stop = 0;
	c = '@';
	while (!stop)
	{
		free(piece);
		if (!(piece = get_next_piece(fd)))
			return (NULL);
		if (!(insert_piece(&head, new_piece(???, ++c)))
			return (NULL);
		free(piece);
		stop = (*(piece = get_next_line(fd)) != '\n');
	}
	return (head);
}
