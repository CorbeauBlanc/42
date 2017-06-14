/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parametric_equations.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:15:01 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/14 16:35:22 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETRIC_EQUATIONS_H
# define PARAMETRIC_EQUATIONS_H
# include "structures.h"

t_dot		*equation_get_dot(t_dot *res, t_param_eq *eq, double t);
void		init_equation(t_param_eq *eq, const t_vector *vdir,
							const t_vector *vconst);
t_param_eq	*new_equation(const t_vector *vdir, const t_vector *vconst);

#endif
