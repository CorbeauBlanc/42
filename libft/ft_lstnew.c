/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:12:26 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/17 19:11:42 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*cell;

	if (!(cell = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	cell->content = (void*)content;
	cell->content_size = content_size;
	cell->next = NULL;
	return (cell);
}
