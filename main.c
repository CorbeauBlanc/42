/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:39:40 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/28 15:46:16 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "get_next_line/libft/libft.h"

void	ft_pause(void)
{
	char	c;
	scanf("%c", &c);
	if (c != '\n')
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	int fd = open("test", O_RDONLY);
	char *line = "";
	while (get_next_line(fd, &line) > 0)
		printf("[%s]\n", line);
	return (0);
}
