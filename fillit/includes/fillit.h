/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:29:46 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/05 13:49:28 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define TRUE 1
# define FALSE -100

typedef struct		s_piece
{
	char			**tab;
	struct s_piece	*next;
	struct s_piece	*prev;
	struct s_piece	*head;
}					t_piece;

void				exit_error();
void				*error_free(char *str);
int					error_free_int(char *str);
int					error_free_tab(char **tab);
void				exit_error_free_list(t_piece **piece);
int					check_file(char *str);
int					check_tetriminos(char **tab);
char				*get_next_line(int fd);
char				*get_file_content(char *path);
int					is_valid_line(char *line);
char				**get_next_piece(int fd);
t_piece				*new_piece(char **tab);
void				insert_piece(t_piece **head, t_piece *cell);
void				delete_piece(t_piece **cell);
t_piece				*create_pieces_list(char *file_path);
void				*free_list(t_piece **head);
void				free_tab(char ***tab);
void				search_smaller(t_piece *piece);
int					ft_lst_size(t_piece *piece);

int					ft_better_lst_size(t_piece *piece);

#endif
