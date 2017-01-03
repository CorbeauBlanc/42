/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/03 18:10:02 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	void	*core;
	void	*window;
	if (!(core = mlx_init()))
		return (1);
	window = mlx_new_window(core, 500, 500, "TEST");
	mlx_loop(core);
	return (0);
}
