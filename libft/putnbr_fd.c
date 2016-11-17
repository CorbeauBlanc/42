/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:46:06 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/16 13:17:40 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		l = -l;
	}
	if (n > 10 || n < -10)
		ft_putnbr_fd(l / 10, fd);
	ft_putchar_fd('0' + (l % 10), fd);
}
