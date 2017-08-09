/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 12:26:49 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/09 17:25:42 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <fcntl.h>

int		get_next_data(int fd, char **data)
{
	static int		n = 1;
	static int		fd_buff = 0;

	if (fd != fd_buff)
	{
		fd_buff = fd;
		n = 1;
	}
	if (!n)
		return (0);
	if (!(n = get_next_line(fd, data)))
		return (0);
	while ((**data == '#' || !**data) && (n = get_next_line(fd, data)) > 0)
	;
	if (n < 0)
		exit_error("rtv1: ", "read");
	if (!n)
	{
		*data = ft_strnew(0);
		return (1);
	}
	return (n);
}

t_scene	*get_scene(char *path)
{
	int			fd;
	t_scene		*scene;
	char		*data;
	t_sc_data	object;

	if ((fd = open(path, O_RDONLY)) < 0)
		exit_error("rtv1: ", "open");
	scene = new_scene(new_spotlight((t_dot){0, 0, 0, 0}, 1),
					new_camera(FOV, (t_dot){0, 0, 0, 0}, 0, 0), 0,
					(SDL_Color){0, 0, 0, 255});
	data = NULL;
	object = VOID;
	while (get_next_data(fd, &data))
	{
		if (object == ENVIRONMENT)
			object = add_env_data(scene, data);
		else if (object == LIGHT)
			object = add_light_data(scene, data);
		else if (object == CAMERA)
			object = add_camera_data(scene, data);
		else if (object == OBJECT)
			object = add_object_data(scene, data);
		if (!object)
		{
			if (data == ft_strstr(data, "scene:"))
				object = ENVIRONMENT;
			else if (data == ft_strstr(data, "spotlight:"))
				object = LIGHT;
			else if (data == ft_strstr(data, "camera:"))
				object = CAMERA;
			else
				object = add_object_data(scene, data);
		}
		free(data);
	}
	init_cam_screen(scene->cam);
	close(fd);
	return (scene);
}
