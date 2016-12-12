/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:03:02 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/08 13:56:56 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_cubes(char **tab, int count_line, int count, int hash)
{
	int			flag;

	flag = 0;
	if (count > 0)
		if (tab[count_line][count - 1] == '#')
			++flag;
	if (count < 3)
		if (tab[count_line][count + 1] == '#')
			++flag;
	if (count_line > 0)
		if (tab[count_line - 1][count] == '#')
			++flag;
	if (count_line < 3)
		if (tab[count_line + 1][count] == '#')
			++flag;
	if (flag == 0 || (hash == 2 && flag == 1) || (hash == 3 && flag == 1))
		return (FALSE);
	return (TRUE);
}

int				check_tetriminos(char **tab)
{
	int			count_line;
	int			count;
	int			flag;

	count_line = -1;
	flag = 0;
	while (tab[++count_line] != NULL)
	{
		count = -1;
		while (tab[count_line][++count] != '\0')
			if (tab[count_line][count] == '#')
			{
				++flag;
				if (check_cubes(tab, count_line, count, flag) == FALSE)
					return (FALSE);
			}
	}
	return (TRUE);
}

static int		check_hashtag(char *str, int count)
{
	int			tmp;
	int			flag;

	flag = 0;
	tmp = count;
	while (++tmp != count + 19)
	{
		if (str[tmp] == '#')
			++flag;
	}
	if (flag != 4)
		return (FALSE);
	return (TRUE);
}

static int		check_size_tetrimino(char *str, int count)
{
	int			count_width;
	int			count_height;

	count_height = 0;
	if (count == 0)
		count -= 1;
	if (check_hashtag(str, count) == FALSE)
		return (error_free_int(str));
	while (str[count] != '\n'
		&& (str[count + 1] != '\n' || str[count + 1] != '\0'))
	{
		count_width = 0;
		if (count > -1)
			count -= 1;
		while (str[++count] != '\n')
			++count_width;
		if (count_width != 4)
			return (error_free_int(str));
		++count_height;
		if (count < ((int)ft_strlen(str) - 1))
			count += 1;
	}
	if (count_height != 4)
		return (error_free_int(str));
	return (count);
}

int				check_file(char *str)
{
	int			count;

	if (!str)
		return (FALSE);
	count = -1;
	while (str[++count] != '\0')
		if (str[count] != '#' && str[count] != '.' && str[count] != '\n')
			return (error_free_int(str));
	count = 0;
	while (str[count] != '\0')
	{
		if ((count = check_size_tetrimino(str, count) + 1) == (FALSE + 1))
			return (FALSE);
		if (str[count] != '.' && str[count] != '#' && str[count] != '\0')
			return (error_free_int(str));
		if (str[count] == '\0' && str[count - 2] == '\n')
			return (error_free_int(str));
		if (count > 546)
			return (error_free_int(str));
	}
	return (TRUE);
}
