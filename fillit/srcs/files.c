/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:01:27 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/01 19:49:40 by edescoin         ###   ########.fr       */
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
		if (!(str = ft_strrealloc(str, (len += ft_strlen(line)) + 2)))
			return (error_free(str));
		ft_strlcat(str, line, len + 1);
		str[len] = '\n';
	}
	return (str);
}

t_piece			*create_pieces_list(char *file_path)
{
	int			fd;
	int			stop;
	char		**piece;
	t_piece		*head;
	t_piece		**tmp;

	if(check_file(get_file_content(file_path)) == FALSE)
		return (NULL);
	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (NULL);
	piece = NULL;
	stop = 0;
	tmp = &head;
	while (!stop)
	{
		if (!(piece = get_next_piece(fd)))
			return (free_list(tmp));
		if (!(head = insert_piece(&head, new_piece(piece))))
			return (free_list(tmp));
		free_tab(&piece);
		stop = (get_next_line(fd) == NULL);
	}
	return (*tmp);
}
