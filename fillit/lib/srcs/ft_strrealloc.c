/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:43:24 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/24 12:29:49 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrealloc(const char **src, size_t new_size)
{
	char	*tmp;

	if (!(tmp = ft_strnew(new_size)) || !src || !*src)
		return (0);
	if (*src)
	{
		tmp = ft_strncpy(tmp, *src, ft_strlen(*src));
		free((void*)*src);
	}
	*src = tmp;
	return (1);
}
