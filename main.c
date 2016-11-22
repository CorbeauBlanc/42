/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:39:40 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/22 19:00:03 by edescoin         ###   ########.fr       */
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

void	void_fct(void *data, size_t i)
{
	(void)data;
	(void)i;
	printf("TEST\n");
}

void	void_fct2(unsigned int i, char *c)
{
	(void)i;
	*c = ft_tolower(*c);
}

char	void_fct3(char c)
{
	return (c ? ft_toupper(c) : c);
}

char	void_fct4(unsigned int i, char c)
{
	(void)i;
	return (c ? ft_tolower(c) : c);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

//	char	*dst;
//	char	**tab;
//	void	*tmp;
/*
**.
** 	if (!(dst = (char*)malloc(100)))
** 		exit(EXIT_FAILURE);
**.
**.
*/
	printf("--- ft_pow ---\n\n	2 ^ 1 : %d\n\n", ft_pow(2, 1));
	ft_pause();

	return (0);
}
