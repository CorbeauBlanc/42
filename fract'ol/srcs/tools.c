/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:43:59 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/07 17:44:53 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

double	dabs(double f)
{
	return (f < 0 ? -f : f);
}

double	to_rad(double deg)
{
	return (deg * (M_PI / 180.0f));
}

double	ft_max(double d1, double d2)
{
	return (d1 > d2 ? d1 : d2);
}

double	ft_min(double d1, double d2)
{
	return (d1 < d2 ? d1 : d2);
}
