/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:26:09 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/15 16:26:17 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	src_len;
	size_t	i;
	long	j;
	char	*str;

	src_len = ft_strlen(s);
	len = ft_strlen(s) - strccnt(s, ' ') - strccnt(s, '\n') - strccnt(s, '\t');
	if ((str = ft_strnew(len + 1)))
	{
		i = -1;
		j = -1;
		while (++i < src_len)
			if (!ft_isspace(s[i]))
				str[++j] = s[i];
	}
	return (str);
}
