/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:59:38 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/07 18:37:43 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_piece	*list;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit file");
		return (1);
	}
	if ((list = create_pieces_list(av[1])) == NULL)
		exit_error();
	move_piece(list);
	search_smaller(list);
	free_list(&(list->next));
	ft_memdel((void**)&list);
	return (0);
}
