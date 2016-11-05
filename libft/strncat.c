/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:25:08 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/05 17:27:28 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!(dst = (char*)malloc(ft_strlen(s1) + n + 1)))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dst[++j] = s1[i];
	i = -1;
	while (s2[++i] && i < n)
		dst[++j] = s2[i];
	dst[j + 1] = '\0';
	return (dst);
}
