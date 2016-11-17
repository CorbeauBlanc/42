/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:39:40 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/17 18:42:27 by edescoin         ###   ########.fr       */
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

void	void_fct(char *c)
{
	*c = ft_toupper(*c);
}

void	void_fct2(unsigned int i, char *c)
{
	(void)i;
	*c = ft_tolower(*c);
}

char	void_fct3(char c)
{
	return (c ? ft_toupper(c) : c);
}

char	void_fct4(unsigned int i, char c)
{
	(void)i;
	return (c ? ft_tolower(c) : c);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	char	*dst;
//	char	**tab;
//	void	*tmp;

	if (!(dst = (char*)malloc(10)))
		exit(EXIT_FAILURE);
/*
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


	printf("--- ft_strncpy ---\n\n	123456 [3] : %s\n\n",
			ft_strncpy(dst, "123456", 3));
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
*/
	printf("--- ft_atoi ---\n\n	\\f\\n\\r\\t\\v 0001020304abc : %d\n\n",
			ft_atoi("\f\n\r\t\v 0001020304abc"));
	ft_pause();
/*
	printf("--- ft_atoi ---\n\n	-2147483648 : %d\n\n",
			ft_atoi("-2147483648"));
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
*/
	ft_strcpy(dst, "456789789");
	printf("--- ft_memchr ---\n\n	7 [9]> 456789789 : %s\n\n",
			ft_memchr(dst, '7', 9));
	ft_pause();
/*/

	printf("--- ft_memcmp ---\n\n	456789789 <[9]> 456789789 : %d\n\n",
			ft_memcmp(dst, "456789789", 9));
	ft_pause();

	printf("--- ft_memalloc ---\n\n	[%x] < 100 : %s\n\n", (unsigned int)&tmp,
			(tmp = ft_memalloc(10)) ? "Check" : "Fail");
	ft_pause();

	ft_memdel(&tmp);
	printf("--- ft_memdel ---\n\n	[%x] : %s\n\n", (unsigned int)&tmp,
			!(tmp) ? "Check" : "Fail");
	ft_pause();

	dst = ft_strnew(3);
	printf("--- ft_strnew ---\n\n	3 : %s%s%s\n\n",
			dst[0] == '\0' ? "\\0" : "X", dst[1] == '\0' ? "\\0" : "X",
			dst[2] == '\0' ? "\\0" : "X");
	ft_pause();

	ft_strclr(dst);
	printf("--- ft_strclr ---\n\n	[%x] : %s%s%s\n\n", (unsigned int)&dst,
			dst[0] == '\0' ? "\\0" : "X", dst[1] == '\0' ? "\\0" : "X",
			dst[2] == '\0' ? "\\0" : "X");
	ft_pause();

	dst[0] = 'a';
	dst[1] = 'a';
	ft_striter(dst, &void_fct);
	printf("--- ft_striter ---\n\n	aa < toupper : %s\n\n", dst);
	ft_pause();

	ft_striteri(dst, &void_fct2);
	printf("--- ft_striteri ---\n\n	AA < tolower : %s\n\n", dst);
	ft_pause();

	dst = (char*)ft_strmap(dst, &void_fct3);
	printf("--- ft_strmap ---\n\n	aa < toupper : %s\n\n", dst);
	ft_pause();

	dst = (char*)ft_strmapi(dst, &void_fct4);
	printf("--- ft_strmapi ---\n\n	AA < tolower : %s\n\n", dst);
	ft_pause();

	free(dst);
	dst = ft_strnew(10);
	strcpy(dst, "123456789");
	printf("--- ft_strsub ---\n\n	123456789 [0, 5] : %s\n\n",
			ft_strsub(dst, 0, 5));
	ft_pause();

	printf("--- ft_strjoin ---\n\n	123456789 + -test : %s\n\n",
			ft_strjoin(dst, "-test"));
	ft_pause();

	free(dst);
	dst = ft_strnew(20);
	strcpy(dst, " 1\n2\t34 \n\t56 7\n8\t9\t");
	printf("--- ft_strtrim ---\n\n	 1\\n2\\t34 \\n\\t56 7\\n8\\t9\\t : %s\n\n",
			ft_strtrim(dst));
	ft_pause();

	free(dst);
	dst = ft_strnew(20);
	strcpy(dst, "*1*2*3*4***56*7*8*9");
	tab = ft_strsplit(dst, '*');
	printf("--- ft_strsplit ---\n\n	 *1*2*3*4***56*7*8*9 : %s%s%s%s%s%s%s%s\n\n\n",
		tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6], tab[7]);
	ft_pause();

	printf("--- ft_itoa ---\n\n	-2147483648 : %s\n\n",
			ft_itoa(-2147483648));
	ft_pause();

	ft_putstr_fd("--- ft_putstr_fd ---\n\n	Check\n\n", 1);
	ft_pause();

	ft_putstr("--- ft_putnbr_fd ---\n\n	-123456789 : ");
	ft_putnbr_fd(-2147483648, 1);
	ft_pause();
*/
	return (0);
}
