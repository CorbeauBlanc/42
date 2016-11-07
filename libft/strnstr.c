/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:19:48 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/07 19:47:29 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (little[0] == '\0')
		return ((char*)big);
	i = -1;
	j = 0;
	len = ft_strlen(little) > len ? len : ft_strlen(little);
	while (big[++i] && j < len)
		if (big[i] != little[j])
			j = 0;
		else if (++j == 1)
			tmp = (char*)&big[i];
	return (j == len ? tmp : NULL);
}
