/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:37:08 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/16 18:43:51 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	coloration_1(int i, int precision)
{
	return ((precision / abs(i)) * 0x00000011);
}

int	coloration_2(int i, int precision)
{
	return ((precision % abs(i)) * 0x00000011);
}

int	coloration_3(int i)
{
	return (i > 0 ? 0 : -i * 0x00000011);
}

int	(*get_color_fct(int i))()
{
	if (i == 1)
		return (&coloration_1);
	else if (i == 2)
		return (&coloration_2);
	else if (i == 3)
		return (&coloration_3);
	else
		return (NULL);
}
