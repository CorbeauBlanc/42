/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:19:48 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/22 15:41:35 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fd_str(const char *s1, const char *s2)
{
	if (*s1 == *s2)
	{
		if (*(s1 + 1) && *(s2 + 1))
			return (fd_str(s1 + 1, s2 + 1) ? (char*)s1 : NULL);
		return ((char*)s1);
	}
	return (NULL);
}

char		*ft_strstr(const char *big, const char *little)
{
	if (!(*little))
		return ((char*)big);
	if (*big)
		return (fd_str(big, little) ? (char*)big : ft_strstr(big + 1, little));
	return (NULL);
}
