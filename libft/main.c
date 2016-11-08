/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:39:40 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/08 18:57:55 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_pause(void)
{
	char	c;
	scanf("%c", &c);
	if (c != '\n')
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	char	*dst;
	char	*tmp;

	if (!(dst = (char*)malloc(100)))
		exit(EXIT_FAILURE);

	printf("--- ft_strcpy ---\n\n	123 : %s\n\n",
			ft_strcpy(dst, "123"));
	ft_pause();

	printf("--- ft_strcat ---\n\n	123 + 456 : %s\n\n",
			ft_strcat(dst, "456"));
	ft_pause();

	printf("--- ft_strdup ---\n\n	123 : %s\n\n",
			ft_strdup(dst));
	ft_pause();

	printf("--- ft_strlen ---\n\n	123 : [%lu]\n\n",
			ft_strlen(dst));
	ft_pause();

	printf("--- ft_strncpy ---\n\n	123456 [9] : %s\n\n",
			ft_strncpy(dst, "123456", 9));
	ft_pause();

	printf("--- ft_strncat ---\n\n	123456 + 789 : %s\n\n",
			ft_strncat(dst, "789", 3));
	ft_pause();

	printf("--- ft_strlcat ---\n\n	123456 + 789 : [%lu] %s\n\n",
			ft_strlcat(dst, "789", 100), dst);
	ft_pause();

	printf("--- ft_strchr ---\n\n	5 > 123456789 : %s\n\n",
			ft_strchr(dst, '5'));
	ft_pause();

	printf("--- ft_strrchr ---\n\n	5 > 123456789-5*** : %s\n\n",
			ft_strrchr(ft_strcat(dst, "-5***"), '5'));
	ft_pause();

	printf("--- ft_strstr ---\n\n	456 > 123456789 : %s\n\n",
			ft_strstr(dst, "456"));
	ft_pause();

	printf("--- ft_strnstr ---\n\n	456798 [3] > 456-123456789 : %s\n\n",
			ft_strnstr(ft_strcat("456-", dst), "456789", 3));
	ft_pause();

	printf("--- ft_strcmp ---\n\n	123456789 <> 123456789 : %d\n\n",
			ft_strcmp(dst, "123456789"));
	ft_pause();

	printf("--- ft_strncmp ---\n\n	123456789 <3> 123****** : %d\n\n",
			ft_strncmp(dst, "123******", 3));
	ft_pause();

	printf("--- ft_isalpha ---\n\n	a : %d\n\n", ft_isalpha('a'));
	ft_pause();

	printf("--- ft_isprint ---\n\n	\\0 : %d\n\n", ft_isprint('\0'));
	ft_pause();

	printf("--- ft_isascii ---\n\n	@ : %d\n\n", ft_isascii('@'));
	ft_pause();

	printf("--- ft_isdigit ---\n\n	a : %d\n\n", ft_isalpha('5'));
	ft_pause();

	printf("--- ft_atoi ---\n\n	\\f\\n\\r\\t\\v -2147483648abc : %d\n\n",
			ft_atoi("\f\n\r\t\v -2147483648abc"));
	ft_pause();

	printf("--- ft_memset ---\n\n	* [9]> 123456789 : %s\n\n",
			ft_memset(dst, '*', 9));
	ft_pause();

	printf("--- ft_memcpy ---\n\n	123456789 [9]> ********* : %s\n\n",
			ft_memcpy(dst, "123456789", 9));
	ft_pause();

	printf("--- ft_memccpy ---\n\n	abcdefghi [d][9]> 123456789 : %s\n\n",
			ft_memccpy(dst, "abcdefghi", 'd', 9));
	ft_pause();

	tmp = &dst[3];
	printf("--- ft_memmove ---\n\n	456789 [6]> abc456789 : %s\n\n",
			ft_memmove(dst, tmp, 6));
	ft_pause();

	printf("--- ft_memchr ---\n\n	7 [9]> 456789789 : %s\n\n",
			ft_memchr(dst, '7', 9));
	ft_pause();

	printf("--- ft_memcmp ---\n\n	456789789 <[9]> 456789789 : %d\n\n",
			ft_memcmp(dst, "456789789", 9));
	ft_pause();
		return (0);
}
