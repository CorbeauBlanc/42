/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:51:12 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/01 16:50:15 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*tmp;

	if (!size)
		return (NULL);
	if ((tmp = (void*)malloc(size)))
		ft_bzero(tmp, size);
	return (tmp);
}
