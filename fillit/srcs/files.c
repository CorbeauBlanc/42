/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:01:27 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/08 13:49:02 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*get_next_line(int fd)
{
	char		c;
	char		*str;
	size_t		len;
	int			nb;

	len = 0;
	if (!(str = ft_strnew(0)))
		return (NULL);
	while ((nb = read(fd, &c, 1)) > 0 && c != '\n')
	{
		if (!(str = ft_strrealloc(str, (++len) + 1)))
			return (error_free(str));
		str[len - 1] = c;
	}
	return (nb ? str : error_free(str));
}

char			*get_file_content(char *path)
{
	char	*str;
	char	*line;
	int		fd;
	int		len;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (NULL);
	str = NULL;
	len = 0;
	while ((line = get_next_line(fd)))
	{
		if (!(str = ft_strrealloc(str, (len += ft_strlen(line) + 1) + 2)))
			return (error_free(str));
		ft_strlcat(str, line, len + 1);
		str[len - 1] = '\n';
	}
	close(fd);
	return (str);
}

t_piece			*create_pieces_list(int fd)
{
	int		stop;
	char	**piece;
	char	c;
	t_piece	*tmp;

	if (fd == -1)
		return (NULL);
	piece = NULL;
	tmp = NULL;
	stop = 0;
	c = '@';
	while (!stop)
	{
		if (!(piece = get_next_piece(fd)))
		{
			if (tmp == NULL)
				return (NULL);
			return (free_list(tmp->head));
		}
		insert_piece(&tmp, new_piece(piece, ++c));
		if (tmp && tmp->next)
			tmp = tmp->next;
		stop = (get_next_line(fd) == NULL);
	}
	return (tmp->head);
}
