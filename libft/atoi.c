/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:04:52 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/08 16:35:26 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	while (ft_isspace(nptr[i]) && nptr[i])
		i++;
	if (!nptr[i])
		return (0);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		sign = nptr[i] == '+' ? 1 : -1;
		i++;
	}

}
