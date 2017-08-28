/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 13:32:43 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/08 16:57:23 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "structures.h"

t_sc_data	add_camera_data(t_scene *scene, char *data);
t_sc_data	add_env_data(t_scene *scene, char *data);
t_sc_data	add_light_data(t_scene *scene, char *data);
t_sc_data	add_object_data(t_scene *scene, char *data);
t_sc_data	data_get_color(SDL_Color *col, char *data);
t_sc_data	data_get_crd(t_dot *crd, char *data);
double		data_get_val(char *data);
t_scene		*get_scene(char *path);

#endif
