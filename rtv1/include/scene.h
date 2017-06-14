/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:39 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 17:23:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef scene_H
# define scene_H
# include "structures.h"

/*
** scene_projection.c
*/
void	projection(t_scene *scene, t_camera *cam);
void	transform_scene(t_scene *scene, t_matrix *mat);

#endif
