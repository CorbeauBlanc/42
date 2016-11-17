/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:29:11 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/16 18:24:07 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	long	j;
	size_t	len;

	len = ft_strlen(dst);
	i = len - 1;
	j = -1;
	while (i++ < size - 1 && src[++j])
		dst[i] = src[j];
	dst[i] = '\0';
	return (len + j);
}
