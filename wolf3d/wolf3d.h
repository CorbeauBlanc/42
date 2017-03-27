/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:52 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/27 23:51:04 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define TITLE			"Wolf3D"
# define HEIGHT 		700
# define WIDTH 			700
# define NB_TEXTURES	2
# define SPEED			1
# define WALL_SIZE		16
# define TEXT_SIZE		64
# define BUFF_SIZE		1024

# ifndef __APPLE__
#  include <SDL2/SDL.h>
#  define SDL_VIDEO		SDL_VIDEO_DRIVER_X11
# else
#  include "SDL.h"
#  define SDL_VIDEO		SDL_VIDEO_DRIVER_COCOA
# endif

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "structures.h"

/*
** angles.c
*/
int					is_east(double angle);
int					is_north(double angle);
int					is_south(double angle);
int					is_west(double angle);

/*
** camera.c
*/
t_camera			*create_camera(int fov, int angle);
void				delete_camera(t_camera *cam);
void				refresh_cam(t_camera *cam);
void				set_camera_fov(t_camera	*cam, int fov);

/*
** graphics.c
*/
Uint32				get_color(int r, int g, int b);
void				refresh_win();
void				SDL_DestroyCore();
t_SDL_Core			*SDL_GetCore();

/*
** images.c
*/
void				clear_image(t_image *img);
t_image				*create_image(int width, int height, int depth);
void				delete_image(t_image *img);
void				display_image(t_image *img, int x, int y);

/*
** img_graphics.c
*/
void				mlx_draw_line_img(t_image *img, t_vector *pt1, t_vector *pt2);
void				mlx_pixel_put_img(t_image *img, int x, int y, int color);

/*
** events.c
*/
void				clear_events(t_event **head);
void				delete_event(t_event **head);
void				new_event(t_event **head, SDL_Scancode key, int (*fct)());
void				wait_events(t_event *list_evts, t_player *player);

/*
** key_events.c
**t_key_data			*new_key_data(SDL_Keycode key, int (*fct)(), t_player *player);
**int					key_hook(SDL_Event evt, t_event *list_evts);
*/

/*
** key_functions_*.c
*/
int					move_down(t_player *player);
int					move_left(t_player *player);
int					move_right(t_player *player);
int					move_up(t_player *player);
int					rotate_left(t_player *player);
int					rotate_right(t_player *player);

/*
** main.c
*/
void				exit_error(char *s);
void				exit_main();

/*
** map.c
*/
void				delete_map(t_map *map);
SDL_Texture			*load_texture(t_tile type);
t_map				*read_file(int fd);

/*
** player.c
*/
t_player			*create_player(t_camera *cam, int x, int y, t_map *map);
void				delete_player(t_player *player);
void				scan_environment(t_player *player);

/*
** screen.c
*/
void				clear_screen(t_screen *scr);
t_screen			*create_screen(int width, int height);
void				delete_screen(t_screen *scr);
void				put_pxl_screen(t_screen *scr, int x, int y, Uint32 color);

/*
** textures.c
*/
SDL_Texture			*create_texture(char *path);

/*
** tiles.c
*/
void				delete_cell(t_map *cell);
t_map				*insert_cell(t_map *head, t_map *cell);
int					is_empty(t_map *tile);
t_map				*goto_tile(t_vector *crd, t_map *tile);
t_map				*new_cell(t_vector *vect, t_tile type);

/*
** transformations.c
*/
void				translation();
void				rotation();

#endif
