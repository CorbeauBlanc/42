/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:59:50 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/01 18:26:49 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_piece
{
	char			**tab;
	struct s_piece	*next;
	struct s_piece	*prev;
}					t_piece;

void				exit_error();
void				exit_error_free(char *str);
void				exit_error_free_tab(char **tab);
void				*NULL_free(void *ptr);
void				*NULL_free_list(t_piece **head);
void				check_file(char *str);
void				check_tetriminos(char **tab);
char				*get_next_line(int fd);
char				*get_file_content(char *path);
int					is_valid_line(char *line);
char				**get_next_piece(int fd);
t_piece				*new_piece(char **tab);
t_piece				*insert_piece(t_piece **head, t_piece *cell);
void				delete_piece(t_piece **cell);
t_piece				*create_pieces_list(char *file_path);
void				free_list(t_piece **head);
void				free_tab(char ***tab);

#endif
