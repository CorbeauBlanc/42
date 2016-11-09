/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:22:44 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/09 14:52:22 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char * ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if ((str = (char*)malloc(len + 1)))
	{
		while (i++ < len)
			str[i] = f((unsigned int)i, s[i]);
		str[i] = '\0';
	}
	return (str);
}
