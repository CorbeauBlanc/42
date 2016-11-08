/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:00:22 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/08 16:35:19 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	long	i;
	long	j;
	char	*dst;

	if (!(dst = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dst[++j] = s1[i];
	i = -1;
	while (s2[++i])
		dst[++j] = s2[i];
	dst[j + 1] = '\0';
	return (dst);
}
