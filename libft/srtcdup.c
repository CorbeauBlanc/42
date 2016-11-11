/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srtcdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:07:53 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/11 20:09:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strcdup(const char *s, char c)
{
	long	i;
	long	len;
	char	*str;

	if (!s)
		return (NULL);
	len = strclen(s, c);
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
