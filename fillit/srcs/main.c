/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:59:38 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/08 14:10:55 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_piece	*list;
	int		fd;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit file");
		return (1);
	}
	if (check_file(get_file_content(av[1])) == FALSE)
		exit_error();
	fd = open(av[1], O_RDONLY);
	if (!(list = create_pieces_list(fd)))
	{
		close(fd);
		exit_error();
	}
	close(fd);
	move_piece(list);
	search_smaller(list);
	free_list(list);
	return (0);
}
