/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:45:33 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/15 17:32:59 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_buff_line(char *buff, char **tmp, char **line)
{
	int nb;

	if ((nb = ft_memccnt(buff, '\n', BUFF_SIZE)) > 1)
	{
		*tmp = ft_strchr(buff, '\n');
		*line = ft_strcdup((*tmp) + 1, '\n');
		**tmp = '0';
		return (1);
	}
	else if (nb == 1) {
		*tmp = ft_strdup(ft_strchr(buff, '\n') + 1); }
	else
		*tmp = ft_strnew(0);
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buffer = NULL;
	char		*tmp1;
	char		*tmp2;
	int			nb;

	if (!buffer)
		buffer = ft_strnew(BUFF_SIZE);
	if (get_buff_line(buffer, &tmp1, line))
		return (1);
	ft_memset(buffer, '\0', BUFF_SIZE);
	while ((nb = read(fd, buffer, BUFF_SIZE)) > 0 &&
			ft_memccnt(buffer, '\n', BUFF_SIZE) == 0)
	{
		tmp2 = tmp1;
		tmp1 = ft_strjoin(tmp1, buffer);
		free(tmp2);
	}
	if (nb < 0)
		return (-1);
	tmp2 = ft_strcdup(buffer, '\n');
	*line = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	return ((nb != 0));
}
