/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:59:38 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/07 16:18:56 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_piece	*list;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit file");
		return (FALSE);
	}
	if ((list = create_pieces_list(av[1])) == NULL)
		exit_error();
	list = move_piece(list);
	return (TRUE);
}
