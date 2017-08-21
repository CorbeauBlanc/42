/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:39 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 18:35:06 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "structures.h"

/*
** scene.c
*/
void		delete_scene(t_scene *scene);
t_scene		*new_scene(t_spotlight *light, t_camera *cam, double brightness,
						SDL_Color bgcolor);
void		scene_add_object(t_object *obj, t_scene *scene);

/*
** spotlight.c
*/
void		delete_spotlight(t_spotlight *spot);
t_spotlight	*new_spotlight(t_dot crd, double power);

#endif
