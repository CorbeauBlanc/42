/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/04 21:10:04 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	t_vector p1, p2;
	t_mlx_core core;

	if (!(core.co = mlx_init()))
		return (1);
	core.win = mlx_new_window(core.co, 500, 500, "TEST");
	p1.x = 50;
	p1.y = 50;
	p2.x = 200;
	p2.y = 300;
	draw_line(&p1, &p2, &core);
	p1.x = 150;
	p1.y = 150;
	draw_line(&p2, &p1, &core);

	mlx_loop(core.co);
	return (0);
}
