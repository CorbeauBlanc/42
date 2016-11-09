/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:46:44 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/09 14:52:22 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	src_len;

	if (!dst || !src)
		return (NULL);
	src_len = ft_strlen(src);
	i = 0;
	while (i++ < len - 1)
		dst[i] = i > src_len ? '\0' : src[i];
	return (dst);
}
