/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memeset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:35:42 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/08 18:04:49 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	if (n)
	{
		ft_memset(s + 1, c, n - 1);
		*(unsigned char*)s = (unsigned char)c;
	}
	return (s);
}
