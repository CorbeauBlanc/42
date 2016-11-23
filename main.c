/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:39:40 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/23 17:19:05 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

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

//	char	*dst = ft_strnew(100);
//	char	**tab;
//	char	*tmp = ft_strnew(100);

	printf("--- ft_strstr ---\n\n%d\n", ft_atoi_base("\t  \n -A  \t ", 16));

	return (0);
}
