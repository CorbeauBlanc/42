/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:52 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/26 20:07:15 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define NB_FTLS		4

# define  PRIMARY		0x00000033
# define  SECONDARY		0x00000000
# define  TERTIARY		0x00110000

# ifndef __APPLE__
#  define K_Z			233
#  define K_Q			97
#  define K_S			117
#  define K_D			105
#  define K_I			100
#  define K_O			108
#  define K_UP			65362
#  define K_LEFT		65361
#  define K_DOWN		65364
#  define K_RIGHT		65363
#  define K_ECHAP		65307
#  define M_L_CLICK		1
#  define M_R_CLICK		3
#  define M_SCROLL_UP	4
#  define M_SCROLL_DOWN	5
# else
#  define K_Z			13
#  define K_Q			0
#  define K_S			1
#  define K_D			2
#  define K_I			34
#  define K_O			31
#  define K_UP			126
#  define K_LEFT		123
#  define K_DOWN		125
#  define K_RIGHT		124
#  define K_ECHAP		53
#  define M_L_CLICK		1
#  define M_R_CLICK		2
#  define M_SCROLL_UP	4
#  define M_SCROLL_DOWN	5
# endif
# define K_PRESS_MASK	(1L<<0)
# define K_PRESS_EVT	2
# define M_MOTION_MASK	(1L<<6)
# define M_MOTION_EVT	6

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "structures.h"

/*
** burning_ship.c
*/
int			is_in_burning_ship(double x, double y, int precision);
t_fractal	*create_burning_ship();

/*
** colors.c
*/
int			(*get_color_fct(int i))();

/*
** cpx_numbers.c
*/
t_complex	*new_cpx(double r, double i);
void		set_nbr(t_complex *nb, double r, double i);

/*
** cpx_operations.c
*/
t_complex	*cpx_add(t_complex *res, t_complex *nb1, t_complex *nb2);
t_complex	*cpx_div(t_complex *res, t_complex *nb1, t_complex *nb2);
double		cpx_mod(t_complex *nb);
t_complex	*cpx_mult(t_complex *res, t_complex *nb1, t_complex *nb2);
t_complex	*cpx_sub(t_complex *res, t_complex *nb1, t_complex *nb2);

/*
** cpx_operations_2.c
*/
t_complex	*cpx_pow(t_complex *res, t_complex *nb1, double nb2);
t_complex	*cpx_real_div(t_complex *res, t_complex *nb1, double nb2);
t_complex	*cpx_real_mult(t_complex *res, t_complex *nb1, double nb2);

/*
** fractals.c
*/
void		delete_ftl_tab(t_fractal **tab);
void		draw_fractal(t_image *img, t_fractal *ftl);
t_fractal	**init_ftl_tab();
t_fractal	*get_fractal(char *name, t_fractal **ftl_tab);
t_fractal	*new_fractal(char *name, int (*fct)(), double zoom);

/*
** graphics.c
*/
t_mlx_core	*mlx_get_core(int width, int height);
void		put_string(int x, int y, char *str);

/*
** images.c
*/
void		clear_image(t_image *img);
t_image		*create_image(int width, int height, int depth);
void		delete_image(t_image *img);
void		display_image(t_image *img, int x, int y);

/*
** img_graphics.c
*/
int			is_in_img(int x, int y, t_image *img);
void		mlx_pixel_put_img(t_image *img, int x, int y, int color);

/*
** julia.c
*/
int			is_in_julia(double x, double y, int precision, t_complex *init);
t_fractal	*create_julia();

/*
** key_events.c
*/
void		clear_key_evts(t_key_evt **head);
void		delete_key_evt(t_key_evt **head);
t_key_evt	*init_key_evts(int key, void *param, void (*fct)());
int			key_hook(int key, void *param);
void		new_key_evt(t_key_evt **head, void *param, int key, void (*fct)());

/*
** key_functions_*.c
*/
void		translate_down();
void		translate_left();
void		translate_right();
void		translate_up();

/*
** main.c
*/
void		exit_main();

/*
** mandelbrot
*/
int			is_in_mandelbrot(double x, double y, int precision);
t_fractal	*create_mandelbrot();

/*
** mouse_events.c
*/
int			mouse_hook(int button, int x, int y, void *param);
int			move_hook(int x, int y, void *param);

/*
** newton.c
*/
int			is_in_newton(double x, double y, int precision);
t_fractal	*create_newton();

#endif
