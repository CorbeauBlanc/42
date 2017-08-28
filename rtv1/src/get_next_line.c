/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:45:33 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/09 17:23:39 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	get_buff_line(t_buffer *buff, char **tmp, char **line)
{
	int nb;

	if ((nb = ft_memccnt(buff->str, '\n', BUFF_SIZE)) > 1)
	{
		*tmp = ft_strchr(buff->str, '\n');
		*line = ft_strcdup((*tmp) + 1, '\n');
		**tmp = '0';
		return (1);
	}
	else if (nb == 1)
	{
		*tmp = ft_strdup(ft_strchr(buff->str, '\n') + 1);
		if (buff->eof && **tmp)
		{
			ft_memset(buff->str, '\0', BUFF_SIZE);
			*line = *tmp;
			free(*tmp);
			return (1);
		}
	}
	else
		*tmp = ft_strnew(0);
	return (0);
}

static void	ft_strjoin2(char **dest, char *s1, const char *s2, size_t nbytes)
{
	char	*s3;

	s3 = ft_strnew(nbytes);
	ft_strncpy(s3, s2, nbytes);
	if (*dest)
		free(*dest);
	*dest = NULL;
	*dest = ft_strjoin(s1, s3);
	free(s1);
	free(s3);
}

static char	*ft_strjoin3(char *s, t_buffer *buff)
{
	char	*tmp;
	char	*ret;

	if (!buff->eof)
	{
		tmp = ft_strcdup(buff->str, '\n');
		ret = ft_strjoin(s, tmp);
		free(tmp);
		free(s);
		return (ret);
	}
	else
	{
		ret = ft_strdup(s);
		free(s);
		return (ret);
	}
}

int			init_buffer(t_buffer **buff, int fd)
{
	if (!(*buff))
	{
		if (!(*buff = (t_buffer*)malloc(sizeof(t_buffer))))
			return (0);
		if (!((*buff)->str = ft_strnew(BUFF_SIZE)))
			return (0);
		(*buff)->fd = fd;
		(*buff)->eof = 0;
	}
	else if (fd != (*buff)->fd)
	{
		ft_memset((*buff)->str, '\0', BUFF_SIZE);
		(*buff)->fd = fd;
		(*buff)->eof = 0;
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_buffer	*buff = NULL;
	char			*tmp;
	int				nb;

	if (!init_buffer(&buff, fd))
		return (-1);
	if (get_buff_line(buff, &tmp, line))
		return (1);
	ft_memset(buff->str, '\0', BUFF_SIZE);
	while ((nb = read(fd, buff->str, BUFF_SIZE)) > 0 &&
			ft_memccnt(buff->str, '\n', BUFF_SIZE) == 0)
	{
		ft_strjoin2(&tmp, ft_strdup(tmp), buff->str, nb);
		ft_memset(buff->str, '\0', BUFF_SIZE);
	}
	if (nb < 0)
		return (-1);
	buff->eof = (nb == 0);
	*line = ft_strjoin3(tmp, buff);
	return (**line != '\0' || nb);
}
