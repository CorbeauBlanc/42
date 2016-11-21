/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:17:39 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/21 16:47:34 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	long	j;
	size_t	len;

	len = ft_strlen(dst);
	i = len;
	j = -1;
	while (src[++j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
	}
	if (size == 0 || len > size)
		return (size + ft_strlen(src));
	dst[i] = '\0';
	return (len + ft_strlen(src));
}
