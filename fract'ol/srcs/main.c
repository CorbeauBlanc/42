/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/07 17:31:20 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <fcntl.h>

void	exit_error(char *s)
{
	if (!s)
	{
		perror("fractol");
		exit(1);
	}
	ft_putstr_fd(s, 2);
	exit(1);
}

void	exit_main(void)
{
	mlx_destroy_window(mlx_get_core()->co, mlx_get_core()->win);
	garbage_collector(CLEAR, NULL, NULL);
	exit(0);
}

void	create_events(t_key_evt **head, t_mlx_core *core)
{
	mlx_do_key_autorepeaton(core->co);
	new_key_evt(head, K_Z, &translate_up);
	new_key_evt(head, K_Q, &translate_left);
	new_key_evt(head, K_S, &translate_down);
	new_key_evt(head, K_D, &translate_right);
	new_key_evt(head, K_I, &zoom_in);
	new_key_evt(head, K_O, &zoom_out);
	new_key_evt(head, K_UP, &rotate_up);
	new_key_evt(head, K_LEFT, &rotate_left);
	new_key_evt(head, K_DOWN, &rotate_down);
	new_key_evt(head, K_RIGHT, &rotate_right);
	garbage_collector(ADD, head, &clear_key_evts);
	mlx_hook(core->win, K_PRESS_EVT, K_PRESS_MASK, &key_hook, *head);
}

int		main(int ac, char **av)
{
	t_mlx_core	*core;
	t_key_evt	*events;

	core = mlx_get_core();
	events = init_key_evts(K_ECHAP, &exit_main, cam, map);
	create_events(&events, core);
	mlx_loop(core->co);
	exit_main();
	return (0);
}
