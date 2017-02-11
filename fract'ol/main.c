/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/11 18:38:47 by edescoin         ###   ########.fr       */
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

void		create_events(t_mlx_core *core, t_fractal *ftl, t_image *img)
{
	t_key_evt	**head;
	t_mouse_evt	*mse_args;

	head = malloc(1);
	*head = init_key_evts(K_ECHAP, &exit_main);
/*	mlx_do_key_autorepeaton(core->co);
	new_key_evt(head, K_Z, &translate_up);
	new_key_evt(head, K_Q, &translate_left);
	new_key_evt(head, K_S, &translate_down);
	new_key_evt(head, K_D, &translate_right);*/
	garbage_collector(ADD, head, &clear_key_evts);
	mlx_hook(core->win, K_PRESS_EVT, K_PRESS_MASK, &key_hook, *head);

	mse_args = malloc(sizeof(t_mouse_evt));
	mse_args->ftl = ftl;
	mse_args->img = img;
	garbage_collector(ADD, mse_args, &free);
	mlx_mouse_hook(core->win, &mouse_hook, mse_args);
}

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_mlx_core	*core;
	int			width;
	int			height;
	t_fractal	**ftl_tab;
	t_image		*img;

	ftl_tab = init_ftl_tab();
	garbage_collector(ADD, ftl_tab, &delete_ftl_tab);
	height = ((*ftl_tab)->y_max - (*ftl_tab)->y_min) * (*ftl_tab)->zoom;
	width = ((*ftl_tab)->x_max - (*ftl_tab)->x_min) * (*ftl_tab)->zoom;
	core = mlx_get_core(width, height);
	img = create_image(width, height, 32);
	create_events(core, *ftl_tab, img);

	draw_fractal(img, *ftl_tab);

	mlx_loop(core->co);
	exit_main();
	return (0);
}
