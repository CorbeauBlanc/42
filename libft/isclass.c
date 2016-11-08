/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isclass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:36:06 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/08 16:13:26 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isalnum(c));
}

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 128);
}

int	ft_isprint(int c)
{
	return (c > 31);
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' ||
			c == '\r' || c == '\t' || c == '\v');
}
