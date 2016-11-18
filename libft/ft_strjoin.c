/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:22:26 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/09 15:28:02 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	long	i;
	long	j;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
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