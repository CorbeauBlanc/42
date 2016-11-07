/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:19:48 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/07 18:12:47 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (little[0] == '\0')
		return ((char*)big);
	i = -1;
	j = 0;
	while (big[++i] && j < len)
		if (big[i] != little[j])
			j = -1;
		else if (j == 0)
		{
			if (little[j + 1])
				j++;
			tmp = (char*)&big[i];
		}
	return (j == len - 1 ? tmp : NULL);
}
