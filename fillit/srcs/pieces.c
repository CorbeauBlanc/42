/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:33:13 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/01 18:54:47 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_valid_line(char *line)
{
	int	i;

	if (ft_strlen(line) != 5)
		return (0);
	if (line[4] != '\n')
		return (0);
	i = -1;
	while (++i < 4)
		if (line[i] != '.' && line[i] != '#')
			return (0);
	return (1);
}

char		**get_next_piece(int fd)
{
	char	**piece;
	char	*line;
	int		nb;
	int		i;

	if (!(piece = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	i = -1;
	nb = -1;
	while (++nb < 4 && (line = get_next_line(fd)) && *line)
	{
		if (!is_valid_line(line))
		{
			piece[++i] = NULL;
			free_tab(&piece);
			return (error_free(line));
		}
		if (!ft_strequ(line, "....\n"))
			piece[++i] = line;
	}
	if (line && !*line)
		free(line);
	piece[i + 1] = NULL;
	return (check_tetriminos(piece) == TRUE ? piece : error_free_tab(piece));
}
