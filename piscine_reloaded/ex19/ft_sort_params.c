/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:42:17 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/04 16:53:06 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	if (*str)
	{
		ft_putchar(*str);
		ft_putstr(str + 1);
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	if (*s1 && *s2)
		return (*s1 == *s2 ? ft_strcmp(s1 + 1, s2 + 1) : (*s1 - *s2));
	return (*s1 - *s2);
}

void	bubble_sort(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (++i < ac - 1)
	{
		j = 0;
		while (++j < ac - 1)
		{
			if (ft_strcmp(av[j], av[j + 1]) > 0)
			{
				tmp = av[j];
				av[j] = av[j + 1];
				av[j + 1] = tmp;
			}
		}
	}
}

int		main(int ac, char **av)
{
	int i;

	bubble_sort(ac, av);
	i = 0;
	while (++i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
	}
	return (0);
}
