/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/14 11:48:41 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

double	dabs(double f)
{
	return (f < 0 ? -f : f);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	t_vector p1, p2, p3, p4;
	t_mlx_core *core = get_mlx_core();

	p1.x = 50;
	p1.y = 50;
	p2.x = 200;
	p2.y = 50;
	p3.x = 200;
	p3.y = 200;
	p4.x = 50;
	p4.y = 200;
	mlx_draw_quadrangle(&p1, &p2, &p3, &p4);

	mlx_loop(core->co);
	return (0);
}
