/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:59:50 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/28 16:51:55 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_piece
{
	int				nb;
	char			c;
	struct s_piece	*next;
	struct s_piece	*prev;
}					t_piece;

char	*get_next_line(int fd);
int		is_valid_line(char *line);
char	*get_next_piece(int fd);
t_piece	*new_piece(int nb, char c);
t_piece	*insert_piece(t_piece **head, t_piece *cell);
void	delete_piece(t_piece **cell);

#endif
