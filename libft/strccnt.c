/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strccnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:30:54 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/09 16:33:31 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strccnt(const char *s, int c)
{
	if (s && *s)
		return ((*s == c) + strccnt(s + 1, c));
	return (0);
}