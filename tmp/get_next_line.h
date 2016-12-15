/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:41:03 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/12 20:06:51 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_file
{
	int				fd;
	char			*buffer;
	struct s_file	*head;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
