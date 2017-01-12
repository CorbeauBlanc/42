/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:39:40 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/12 18:46:45 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "project.h"
#include "get_next_line/get_next_line.h"
#include "get_next_line/libft/libft.h"

void	ft_pause(void)
{
	char	c;
	scanf("%c", &c);
	if (c != '\n')
		exit(EXIT_FAILURE);
}

void	test1()
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "1234567812345678\n", 17);
	close(p[1]);
	dup2(out, fd);
	printf("%d - [%s]\n", get_next_line(p[0], &line), line);
	printf("%d - [%s]\n", get_next_line(p[0], &line), line);
}

void	test2(char *path)
{
	int fd = open(path, O_RDONLY);
	char	*line;

	printf("%d - [%s]\n", get_next_line(fd, &line), line);
	printf("%d - [%s]\n", get_next_line(fd, &line), line);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	test1();
	return (0);
}
