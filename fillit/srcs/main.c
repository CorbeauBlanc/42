/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:59:38 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/05 13:47:09 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_piece	*list;

	(void)ac;
	list = create_pieces_list(av[1]);
	printf("TEST - %d\n", ft_better_lst_size(list));

	(void)list;

	return (0);
}
