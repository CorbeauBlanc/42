/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 12:26:49 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/02 17:55:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <fcntl.h>

int		get_next_data(int fd, char **data)
{
	int		n;

	if (!(n = get_next_line(fd, data)))
		return (0);
	while ((**data == '#' || !**data) && (n = get_next_line(fd, data)) > 0)
	;
	if (n < 0)
		exit_error("rtv1", "read");
	return (n);
}

t_scene	*get_scene(char *path)
{
	int			fd;
	t_scene		*scene;
	char		*data;
	t_sc_data	object;

	if ((fd = open(path, O_RDONLY)) < 0)
		exit_error("rtv1", "open");
	scene = new_scene(new_spotlight((t_dot){0, 0, 0, 0}, 1),
					new_camera(FOV, &(t_dot){0, 0, 0, 0}, 0, 0), 0,
					(SDL_Color){0, 0, 0, 255});
	data = NULL;
	object = VOID;
	while (get_next_data(fd, &data))
	{
		if (object == ENVIRONMENT)
			object = add_env_data(scene, data);
		if (object == LIGHT)
			object = add_light_data(scene, data);
		if (!object)
		{
			if (data == ft_strstr(data, "scene:"))
				object = ENVIRONMENT;
			if (data == ft_strstr(data, "spotlight:"))
				object = LIGHT;
		}
		free(data);
	}
	close(fd);
	return (scene);
}
