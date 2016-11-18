/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:21:16 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/17 18:21:32 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (*s1 && *s2 && n - 1)
		return (*s1 == *s2 ? ft_strncmp(s1 + 1, s2 + 1, n - 1) : (*s1 - *s2));
	return (*s1 - *s2);
}