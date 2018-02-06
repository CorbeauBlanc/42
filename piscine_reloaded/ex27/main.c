/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:06:18 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/04 16:13:59 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

void	disp_file(int fd)
{
	char	buf;
	int		nb;

	while ((nb = read(fd, &buf, 1)))
		write(1, &buf, 1);
}

int		main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		if (ac < 2)
			write(2, "File name missing.\n", 19);
		else
			write(2, "Too many arguments.\n", 20);
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)))
		disp_file(fd);
	else
		return (1);
	close(fd);
	return (0);
}
