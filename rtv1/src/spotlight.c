/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spotlight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 17:28:47 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/12 17:38:06 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_spotlight	*new_spotlight(t_dot crd, double power)
{
	t_spotlight	*spot;

	if (!(spot = malloc(sizeof(t_spotlight))))
		exit_error("rtv1", "mallo");
	spot->crd = crd;
	spot->power = power < 0 ? 0 : power;
	return (spot);
}

void		delete_spotlight(t_spotlight *spot)
{
	free(spot);
}
