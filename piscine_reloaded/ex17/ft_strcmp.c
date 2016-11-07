/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:06:13 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/03 15:27:54 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 && *s2)
		return (*s1 == *s2 ? ft_strcmp(s1 + 1, s2 + 1) : (*s1 - *s2));
	return (*s1 - *s2);
}