/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:12:26 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/21 19:24:33 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*cell;

	if (!(cell = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		cell->content = malloc(content_size);
		ft_memcpy(cell->content, content, content_size);
	}
	else
		cell->content = NULL;
	cell->content_size = (content ? content_size : 0);
	cell->next = NULL;
	return (cell);
}
