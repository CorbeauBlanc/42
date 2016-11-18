/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:57:20 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/17 18:12:18 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	if (n && *(unsigned char*)src != (unsigned char)c)
	{
		ft_memccpy(dest + 1, src + 1, c, n - 1);
		*(unsigned char*)dest = *(unsigned char*)src;
	}
	return (dest);
}
