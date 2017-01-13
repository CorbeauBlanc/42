/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:04:59 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/13 20:06:04 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*return_free(void *ret, void *ptr)
{
	free(ptr);
	return (ret);
}
