/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:18:46 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/04 16:07:50 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	if (!(tab = (int*)malloc(sizeof(int) * (max - min))))
		return (NULL);
	i = -1;
	while (++i + min < max)
		tab[i] = i + min;
	return (tab);
}
