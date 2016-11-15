/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:26:19 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/15 17:50:03 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	l;
	int		len;
	char	*str;

	l = (long)n;
	len = (n < 0) + intlen(n);
	if (!(str = ft_strnew(++len)))
		return (NULL);
	if (l < 0)
	{
		str[0] = '-';
		l = -l;
	}
	n = (l < 0 ? 1 : 0);
	while (--len > n)
	{
		str[len] = '0' + (l % 10);
		l /= 10;
	}
	return (str);
}
