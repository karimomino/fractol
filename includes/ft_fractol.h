/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:19:09 by kamin             #+#    #+#             */
/*   Updated: 2021/12/08 03:46:05 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <math.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>

int		ft_strlen(char *str);
void	ft_error_handler(int exception);
void	ft_put_img_pix(int x, int y, int color);
void	ft_fractol(char *fractol);
void	ft_print_frac(int screenw, int screenh, int option);
void	ft_mandelbrot_escape(int x, int y, int i_max);
int		ft_make_color(float hue, float sat, float val);
int		ft_hsv_rgb(float v, float a, float b, float c);
int		col(float val);
void	ft_init_structs(void);
int		key_hook(int keycode, __attribute__((unused)) void *x);
int		ft_mouse(void);
void	ft_redraw(void);
void	ft_zoom(int key);
void	ft_move(int key);
void	ft_julia_escape(int x, int y, int i_max);
int		ft_strcmp(char *s1, char *s2);
void	ft_change_frac(void);
double	ft_atof(const char *nbr);
long	ft_atoi(const char *str);
int		check_op(char *op);
void	init_screen(void);
void	mlx_loops(void);
void	julia_error(int *error);
void	ft_mandelbar_escape(int x, int y, int i_max);

#endif