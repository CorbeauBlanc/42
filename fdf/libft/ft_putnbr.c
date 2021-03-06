/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:51:13 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/22 18:43:22 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	long	l;

	l = (long)n;
	if (n < 0)
	{
		ft_putchar('-');
		l = -l;
	}
	if (n > 9 || n < -9)
		ft_putnbr((int)(l / 10));
	ft_putchar('0' + (l % 10));
}
