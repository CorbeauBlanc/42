/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/16 19:55:36 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <fcntl.h>
#include <math.h>

void		exit_error(char *s)
{
	garbage_collector(CLEAR, NULL, NULL);
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
	mlx_hook(core->win, M_MOTION_EVT, M_MOTION_MASK, &move_hook, mse_args);
}

int			main(int ac, char **av)
{
	t_mlx_core	*core;
	t_fractal	**ftl_tab;
	t_fractal	*ftl;
	t_image		*img;

	ftl_tab = init_ftl_tab();
	ftl = NULL;
	garbage_collector(ADD, ftl_tab, &delete_ftl_tab);
	if (ac < 3 || !(ftl = get_fractal(av[1], ftl_tab)))
		exit_error("usage : ./fractol [name] [coloration]\n");
	if (!(ftl->get_color = get_color_fct(ft_atoi(av[2]))))
		exit_error("usage : ./fractol [name] [coloration]\n");
	core = mlx_get_core((ftl->x_max - ftl->x_min) * ftl->zoom,
						(ftl->y_max - ftl->y_min) * ftl->zoom);
	img = create_image((ftl->x_max - ftl->x_min) * ftl->zoom,
						(ftl->y_max - ftl->y_min) * ftl->zoom, 32);
	create_events(core, ftl, img);
	draw_fractal(img, ftl);
	mlx_loop(core->co);
	exit_main();
	return (0);
}
