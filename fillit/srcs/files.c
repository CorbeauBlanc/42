/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:01:27 by edescoin          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/12/01 18:26:51 by edescoin         ###   ########.fr       */
=======
/*   Updated: 2016/12/01 16:43:47 by kda-silv         ###   ########.fr       */
>>>>>>> master
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
<<<<<<< HEAD
		if (!(str = ft_strrealloc(str, (++len) + 1)))
			return (NULL_free(str));
		str[len - 1] = c;
	}
	return (nb ? str : NULL_free(str));
}

char			*get_file_content(char *path)
{
	char	*str;
	char	*line;
	int		fd;
	int		len;

	if ((fd = open(path, O_RDONLY)) < 0)
		exit_error();
	str = NULL;
	len = 0;
	while ((line = get_next_line(fd)))
	{
		if (!(str = ft_strrealloc(str, (len += ft_strlen(line)) + 2)))
			return (NULL_free(str));
		ft_strlcat(str, line, len + 1);
		str[len] = '\n';
	}
=======
		if (!(ft_strrealloc((const char**)&str, (++len) + 1)))
			return (error_free(str));
		str[len - 1] = c;
	}
	if (!(ft_strrealloc((const char**)&str, (++len) + 1)))
		return (error_free(str));
	str[len - 1] = c;
	return (str);
>>>>>>> master
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
			return (error_free_list(tmp));
		if (!(head = insert_piece(&head, new_piece(piece))))
			return (error_free_list(tmp));
		free_tab(&piece);
		stop = (*(get_next_line(fd)) != '\n');
	}

	return (*tmp);
}
