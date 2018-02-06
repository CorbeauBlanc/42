/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:37:08 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/03 22:25:59 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	coloration_1(int i, int precision)
{
	return ((precision / abs(i)) * PRIMARY);
}

int	coloration_2(int i, int precision)
{
	return ((precision - abs(i)) * SECONDARY +
			(precision - abs(i)) * PRIMARY +
			(precision - abs(i)) * TERTIARY);
}

int	coloration_3(int i, int precision)
{
	return ((precision % abs(i)) * SECONDARY +
			(precision % abs(i)) * PRIMARY +
			(precision % abs(i)) * TERTIARY);
}

int	coloration_4(int i)
{
	return (i > 0 ? 0 : -i * (-i % 2) * SECONDARY +
						-i * (-i % 5) * PRIMARY +
						-i * (-i % 7) * TERTIARY);
}

int	(*get_color_fct(int i))()
{
	if (i == 1)
		return (&coloration_1);
	else if (i == 2)
		return (&coloration_2);
	else if (i == 3)
		return (&coloration_3);
	else if (i == 4)
		return (&coloration_4);
	else
		return (NULL);
}
