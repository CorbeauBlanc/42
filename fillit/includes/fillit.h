/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:29:46 by edescoin          #+#    #+#             */
/*   Updated: 2016/12/07 17:41:23 by edescoin         ###   ########.fr       */
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
# define FALSE -2

typedef struct		s_piece
{
	char			**tab;
	char			c;
	struct s_piece	*next;
	struct s_piece	*prev;
	struct s_piece	*head;
}					t_piece;

int					check_file(char *str);
int					check_tetriminos(char **tab);
t_piece				*create_pieces_list(char *file_path);
void				delete_piece(t_piece **cell);
void				*error_free(char *str);
int					error_free_int(char *str);
int					error_free_tab(char **tab);
void				exit_error();
void				exit_error_free_list(t_piece **piece);
void				*free_list(t_piece **head);
void				free_tab(char ***tab);
int					ft_lst_size(t_piece *piece);
void				ft_puttab(char **tab);
char				*get_file_content(char *path);
char				*get_next_line(int fd);
char				**get_next_piece(int fd);
int					get_square(char **tab, t_piece *piece);
void				insert_piece(t_piece **head, t_piece *cell);
int					is_valid_line(char *line);
t_piece				*move_piece(t_piece *piece);
t_piece				*new_piece(char **tab);
void				search_smaller(t_piece *piece);

int					ft_better_lst_size(t_piece *piece);

#endif
