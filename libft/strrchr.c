/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:36:05 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/07 18:12:49 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	if (*s != '\0')
	{
		if ((tmp = ft_strchr(s + 1, c)))
			return (tmp);
		else
			return (*s == c ? (char*)s : NULL);
	}
	return (c == '\0' ? (char*)s : NULL);
}
