/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:46:44 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/08 16:35:19 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_strncpy(char *dst, const char *src, size_t len)
{
	long	i;
	long	src_len;

	src_len = ft_strlen(src);
	i = -1;
	while (++i < len)
		dst[i] = i > src_len ? '\0' : src[i];
	return (dst);
}
