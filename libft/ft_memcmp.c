/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:20:50 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/18 17:00:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	c1 = *(unsigned char*)s1;
	c2 = *(unsigned char*)s2;
	if (n)
		return (c1 == c2 ? ft_memcmp(s1 + 1, s2 + 1, n - 1) : c1 - c2);
	return (0);
}
