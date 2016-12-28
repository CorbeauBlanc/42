/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:45:33 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/28 17:46:58 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_buff_line(char *buff, char **tmp, char **line)
{
	int nb;

	if ((nb = ft_memccnt(buff, '\n', BUFF_SIZE)) > 1)
	{
		*tmp = ft_strchr(buff, '\n');
		*line = ft_strcdup((*tmp) + 1, '\n');
		**tmp = '0';
		return (1);
	}
	else if (nb == 1)
	{
		*tmp = ft_strdup(ft_strchr(buff, '\n') + 1);
		if (ft_strlen(buff) < BUFF_SIZE && **tmp)
		{
			ft_memset(buff, '\0', BUFF_SIZE);
			*line = *tmp;
			return (1);
		}
	}
	else
		*tmp = ft_strnew(0);
	return (0);
}

static char	*ft_strjoin2(char *s1, const char *s2, size_t nbytes)
{
	char	*str;
	char	*s3;

	s3 = ft_strnew(nbytes);
	ft_strncpy(s3, s2, nbytes);
	str = ft_strjoin(s1, s3);
	free(s1);
	free(s3);
	return (str);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buffer = NULL;
	char		*tmp;
	int			nb;

	if (!buffer)
		buffer = ft_strnew(BUFF_SIZE);
	if (get_buff_line(buffer, &tmp, line))
		return (1);
	ft_memset(buffer, '\0', BUFF_SIZE);
	while ((nb = read(fd, buffer, BUFF_SIZE)) &&
			ft_memccnt(buffer, '\n', BUFF_SIZE) == 0)
	{
		tmp = ft_strjoin2(tmp, buffer, nb);
	}
	if (nb < 0)
		return (-1);
	*line = ft_strjoin(tmp, (nb ? ft_strcdup(buffer, '\n') : NULL));
	free(tmp);
	return (*buffer != '\0');
}
