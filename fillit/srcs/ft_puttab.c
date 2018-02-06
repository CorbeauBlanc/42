/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:18:11 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/07 12:23:55 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_puttab(char **tab)
{
	int		count;

	count = -1;
	while (tab[++count] != NULL)
		ft_putendl(tab[count]);
}
