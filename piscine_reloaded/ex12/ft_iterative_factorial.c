/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:52:26 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/04 16:05:46 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fact;

	if (nb < 0 || nb > 13)
		return (0);
	i = -1;
	fact = 1;
	while (++i < nb)
		fact *= (i + 1);
	return (fact);
}
