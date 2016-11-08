/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:55:59 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/08 18:12:53 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (n)
	{
		ft_memcpy(dest + 1, src + 1, n - 1);
		*(unsigned char*)dest = *(unsigned char*)src;
	}
	return (dest);
}

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	if (n && *(unsigned char*)src != (unsigned char)c)
	{
		ft_memcpy(dest + 1, src + 1, n - 1);
		*(unsigned char*)dest = *(unsigned char*)src;
	}
	return (dest);
}
