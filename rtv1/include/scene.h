/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:39 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/19 15:08:40 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "structures.h"

void	clear_scene(t_scene *scene);
void	scene_add_object(t_object *obj, t_scene *scene);

#endif
