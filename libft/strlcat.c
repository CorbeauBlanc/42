/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:29:11 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/09 14:52:22 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	long	j;
	size_t	len;

	if (!dst || !src)
		return (NULL);
	len = ft_strlen(dst);
	i = len - 1;
	j = -1;
	while (i++ < size - 1 && src[++j])
		dst[i] = src[j];
	dst[i] = '\0';
	return (len + j);
}
