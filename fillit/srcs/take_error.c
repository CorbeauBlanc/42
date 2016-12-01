/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:03:02 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/01 13:09:59 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_cubes(char *str, int count)
{
	int			len;
	int			flag;

	len = ft_strlen(str);
	flag = 0;
	if (count > 0)
		if (str[count - 1] == '#')
			++flag;
	if (count < len)
		if (str[count + 1] == '#')
			++flag;
	if (count >= 5)
		if (str[count - 5] == '#')
			++flag;
	if (count <= (len - 7))
		if (str[count + 5] == '#')
			++flag;
	if (flag == 0)
		return (-1);
	return (0);
}

void			check_tetriminos(char **tab)
{
	int			count_ter;
	int			count;
	int			count2;

	count_ter = -1;
	while (tab[++count_ter] != NULL)
	{
		count = -1;
		count2 = 0;
		while (tab[count_ter][++count] != '\0')
			if (tab[count_ter][count] == '#')
				++count2;
		if (count2 != 4)
			exit_error_free_tab(tab);
		count = -1;
		while (tab[count_ter][++count] != '\0')
			if (tab[count_ter][count] == '#')
				if (check_cubes(tab[count_ter], count) == -1)
					exit_error_free_tab(tab);
	}
}

static int		check_size_tetrimino(char *str, int count)
{
	int			count_width;
	int			count_height;

	count_height = 0;
	if (count == 0)
		count -= 1;
	while (str[count] != '\n'
		&& (str[count + 1] != '\n' || str[count + 1] != '\0'))
	{
		count_width = 0;
		if (count > -1)
			count -= 1;
		while (str[++count] != '\n')
			++count_width;
		if (count_width != 4)
			exit_error_free(str);
		++count_height;
		if (count < ((int)ft_strlen(str) - 1))
			count += 1;
	}
	if (count_height != 4)
		exit_error_free(str);
	return (count);
}

void			check_file(char *str)
{
	int			count;

	count = -1;
	while (str[++count] != '\0')
		if (str[count] != '#' && str[count] != '.' && str[count] != '\n')
			exit_error_free(str);
	count = 0;
	while (str[count] != '\0')
	{
		count = check_size_tetrimino(str, count) + 1;
		if (str[count] != '.' && str[count] != '#' && str[count] != '\0')
			exit_error_free(str);
		if (str[count] == '\0' && str[count - 2] == '\n')
			exit_error_free(str);
		if (count > 546)
			exit_error_free(str);
	}
}
