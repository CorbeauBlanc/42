/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:43:24 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/22 17:24:34 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrealloc(const char **src, size_t new_size)
{
	char	*tmp;

	if (!(tmp = ft_strnew(new_size)))
		return (1);
	if (*src)
	{
		tmp = ft_strncpy(tmp, *src, ft_strlen(*src));
		free((void*)*src);
	}
	*src = tmp;
	return (0);
}
