/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:29 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/14 20:21:25 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "structures.h"

/*
** camera.c
*/
void		delete_camera(t_camera *cam);
t_camera	*new_camera(int fov, const t_dot *crd, double h_ang, double v_ang);
void		set_camera_fov(t_camera	*cam, int fov);

#endif
