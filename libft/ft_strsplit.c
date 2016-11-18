/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:07:53 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/15 17:41:01 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	long	i;
	int		nb;
	char	**tab;

	i = 0;
	nb = (s[0] != c);
	while (s[++i])
		if (s[i] != c && s[i - 1] == c)
			nb++;
	if (!(tab = (char**)malloc(nb * sizeof(char*))))
		return (NULL);
	i = 0;
	tab[0] = (s[0] == c ? NULL : strcdup(s, c));
	nb = -(tab[0] == NULL);
	while (s[++i])
		if (s[i] != c && s[i - 1] == c)
			tab[++nb] = strcdup(&s[i], c);
	return (tab);
}
