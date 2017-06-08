/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:29 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/06 17:11:48 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "structures.h"

/*
** camera.c
*/
void		delete_camera(t_camera *cam);
t_camera	*new_camera(int fov, double h_angle, double v_angle, double dist);
void		set_camera_crd(t_camera *cam, double h_ang, double v_ang, double d);
void		set_camera_fov(t_camera	*cam, int fov);

#endif
