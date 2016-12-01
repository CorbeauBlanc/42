/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:15:02 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/15 16:13:52 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	long	i;
	size_t	len;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = -1;
	len = ft_strlen(s);
	if ((str = (char*)malloc(len + 1)))
	{
		while (s[++i])
			str[i] = f(s[i]);
		str[len] = '\0';
	}
	return (str);
}
