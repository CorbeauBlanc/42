/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:52 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/26 18:26:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define TITLE			"Wolf3D"
# define WIDTH 			1280
# define HEIGHT 		720
# define BOBBING		2
# define FPS			60
# define SENSI			1.5
# define FOV			60
# define SPEED			1.5
# define WALL_SIZE		32
# define TEXT_SIZE		512
# define BUFF_SIZE		1024
# define EVT_DELAY		7

# ifndef __APPLE__
#  include <SDL2/SDL.h>
#  define SDL_VIDEO		SDL_VIDEO_DRIVER_X11
# else
#  include "SDL.h"
#  define SDL_VIDEO		SDL_VIDEO_DRIVER_COCOA
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "structures.h"

/*
** angles.c
*/
int				is_east(double angle);
int				is_north(double angle);
int				is_south(double angle);
int				is_west(double angle);

/*
** camera.c
*/
t_camera		*create_camera(int fov, double angle, int fps,
								double sensibility);
void			delete_camera(t_camera *cam);
void			set_camera_bobbing(t_camera *cam, int bobbing);
void			set_camera_fov(t_camera	*cam, int fov);
void			set_camera_mvt(t_camera *cam);

/*
** cam_angles.c
*/
int				is_looking_down(double angle);
int				is_looking_left(double angle);
int				is_looking_right(double angle);
int				is_looking_up(double angle);

/*
** cam_scanning.c
*/
void			scan_environment(t_player *player);

/*
** events.c
*/
void			clear_events(t_event **head);
void			delete_event(t_event **head);
void			new_event(t_event **head, SDL_Scancode key, int (*fct)());
void			wait_events(t_event *list_evts, t_player *player);

/*
** graphics.c
*/
Uint32			get_color(int r, int g, int b);
Uint8			get_filter_value(t_map_data *data, double dist);
void			refresh_win();
void			SDL_DestroyCore();
t_SDL_Core		*SDL_GetCore();

/*
** key_functions_*.c
*/
int				move_down(t_player *player, int mvt_nb);
int				move_left(t_player *player, int mvt_nb);
int				move_right(t_player *player, int mvt_nb);
int				move_up(t_player *player, int mvt_nb);
int				rotate_left(t_player *player);
int				rotate_right(t_player *player);
int				toggle_fullscreen();

/*
** main.c
*/
void			exit_main();

/*
** map*.c
*/
void			check_player(t_map *map);
void			delete_map(t_map *map);
char			*get_data(const char *str, char *buff, int fd);
t_map_data		*get_map_data(int fd, char *path);
int				is_empty(t_map *tile);
void			open_map(char *path);
t_map			*read_file(int fd, char *path);
void			set_map_brightness(t_map_data *data, int percent);

/*
** map_data.c
*/
int				get_map_background(t_map_data *data, int fd, char *buff);
int				get_map_brightness(t_map_data *data, int fd, char *buff);
int				get_map_ceiling(t_map_data *data, int fd, char *buff);
int				get_map_floor(t_map_data *data, int fd, char *buff);
int				get_map_reflection(t_map_data *data, int fd, char *buff);

/*
** mutexes.c
*/
void			delete_mutexes();
t_mutexes		*get_mutexes();

/*
** orientations.c
*/
t_orientation	get_horiz_side(double angle);
t_orientation	get_vert_side(double angle);

/*
** player.c
*/
t_player		*create_player(t_camera *cam);
void			delete_player();
t_player		*get_player();
void			insert_player(t_map *map, double x, double y);

/*
** sprites.c
*/
t_sprite		*create_sprite(char *path, int h, int map_width, int delay);
void			delete_sprite(t_sprite *sprite);

/*
** textures.c
*/
t_texture		*create_texture(char *path);
t_texture		*create_texture_rect(char *path, SDL_Rect *dim);
void			delete_texture(t_texture *texture);
t_texture		*load_reflection(t_tile type, t_orientation side,
								t_map_data *data);
t_texture		*load_texture(t_tile type, t_orientation side,
								t_map_data *data);

/*
** threads.c
*/
void			init_thread(t_thread *thread, int(*fct)(void*), void *arg,
						t_thread_state state);
void			close_thread(t_thread *thread);
t_thread_state	get_thread_state(t_thread *thread);
void			set_thread_state(t_thread *thread, t_thread_state state);

/*
** tiles.c
*/
void			delete_cell(t_map *cell);
t_map			*insert_cell(t_map *head, t_map *cell);
t_map			*goto_tile(t_vector *crd, t_map *tile);
t_map			*goto_tile2(double x, double y, t_map *tile);
t_map			*new_cell(t_vector *vect, t_tile type, t_map_data *data);


/*
** tools.c
*/
char			*get_data_path(char *map_path, char *data);
void			set_rect_crd(SDL_Rect *rect, int x, int y);
void			set_rect_dim(SDL_Rect *rect, int w, int h);
void			set_vect_crd(t_vector *vect, double x, double y);
t_ray			*set_wall(t_ray *ray, t_map **ray_wall, t_map *wall);

#endif
