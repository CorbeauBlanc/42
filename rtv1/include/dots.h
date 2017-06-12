/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:57:05 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/12 19:58:51 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOTS_H
# define DOTS_H
# include "structures.h"

void	mult_dot(t_dot *dest, t_matrix *mtx, t_dot *vec);
t_dot	*new_dot(double x, double y, double z);
void	set_dot(t_dot *dot, double x, double y, double z);

#endif
