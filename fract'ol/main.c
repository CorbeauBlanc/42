/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/10 19:26:24 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <fcntl.h>
#include <math.h>

void		exit_error(char *s)
{
	if (!s)
	{
		perror("fractol");
		exit(1);
	}
	ft_putstr_fd(s, 2);
	exit(1);
}

void		exit_main(void)
{
	mlx_destroy_window(mlx_get_core(0,0)->co, mlx_get_core(0,0)->win);
	garbage_collector(CLEAR, NULL, NULL);
	exit(0);
}

void		create_events(t_key_evt **head, t_mlx_core *core)
{
/*	mlx_do_key_autorepeaton(core->co);
	new_key_evt(head, K_Z, &translate_up);
	new_key_evt(head, K_Q, &translate_left);
	new_key_evt(head, K_S, &translate_down);
	new_key_evt(head, K_D, &translate_right);*/
	garbage_collector(ADD, head, &clear_key_evts);
	mlx_hook(core->win, K_PRESS_EVT, K_PRESS_MASK, &key_hook, *head);
}

t_fractal	**init_ftl_tab()
{
	t_fractal	**tab;

	if (!(tab = malloc(sizeof(t_fractal*) + 1)))
		return (NULL);
	tab[1] = create_mandelbrot();
	tab[2] = NULL;
	return (tab);
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_mlx_core	*core;
	t_key_evt	*events;
	int			width;
	int			height;
	t_fractal	**ftl_tab;
	t_image		*img;

	ftl_tab = init_ftl_tab();
	height = ((*ftl_tab)->y_max - (*ftl_tab)->y_min) * (*ftl_tab)->zoom;
	width = ((*ftl_tab)->x_max - (*ftl_tab)->x_min) * (*ftl_tab)->zoom;
	core = mlx_get_core(width, height);
	img = create_image(width, height, 32);
	events = init_key_evts(K_ECHAP, &exit_main);
	create_events(&events, core);

	draw_fractal(img, *ftl_tab);

	mlx_loop(core->co);
	exit_main();
	return (0);
}
