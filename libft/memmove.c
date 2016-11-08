/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:07:53 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/08 18:56:14 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char tmp;

	if (n)
	{
		tmp = *(unsigned char*)src;
		ft_memmove(dest + 1, src + 1, n - 1);
		*(unsigned char*)dest = tmp;
	}
	return (dest);
}
