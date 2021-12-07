/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 04:28:59 by kamin             #+#    #+#             */
/*   Updated: 2021/12/08 03:45:27 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
#include "../includes/ft_structs.h"

/*
** This Function Checks A Point On The Screen To See If It Is
** Part Of The Mandelbrot Set. Then Applies a color To that Pixel And
** Puts It On An Image
** Params:
** 	NAME		TYPE		DESCRIPTION
** 	 X			INT			current x coordinate on screen
** 	 Y			INT			current y coordinate on screen
** 	 i-max		INT			max iteration amount
*/
void	ft_mandelbrot_escape(int x, int y, int i_max)
{
	int	counter;

	t_point.re = 1.5 * (x - t_map.w / 2) / (0.5 * t_pm.zoom * t_map.w) + \
		t_pm.movex;
	t_point.im = (y - t_map.h / 2) / (0.5 * t_pm.zoom * t_map.h) + t_pm.movey;
	t_point.newre = 0;
	t_point.newim = 0;
	t_point.oldre = 0;
	t_point.oldim = 0;
	counter = 0;
	while (counter < i_max)
	{
		t_point.oldre = t_point.newre;
		t_point.oldim = t_point.newim;
		t_point.newre = t_point.oldre * t_point.oldre - t_point.oldim * \
			t_point.oldim + t_point.re;
		t_point.newim = 2.0 * t_point.oldre * t_point.oldim + t_point.im;
		if ((t_point.newre * t_point.newre + t_point.newim * t_point.newim) > 4)
			break ;
		counter++;
	}
	t_point.color = ft_make_color(counter * 15, counter * 15, 255);
	ft_put_img_pix(x, y, t_point.color);
}

/*
** This Function Checks A Point On The Screen To See If It Is
** Part Of The Julia Set. Then Applies a color To that Pixel And
** Puts It On An Image
** Params:
** 	NAME		TYPE		DESCRIPTION
** 	 X			INT			current x coordinate on screen
** 	 Y			INT			current y coordinate on screen
** 	 i-max		INT			max iteration amount
*/
void	ft_julia_escape(int x, int y, int i_max)
{
	int	counter;

	t_point.re = 1.5 * (x - t_map.w / 2) / (0.5 * t_pm.zoom * t_map.w) + \
		t_pm.movex;
	t_point.im = (y - t_map.h / 2) / (0.5 * t_pm.zoom * t_map.h) + t_pm.movey;
	counter = 0;
	while (counter < i_max)
	{
		t_point.oldre = t_point.re;
		t_point.oldim = t_point.im;
		t_point.re = t_point.oldre * t_point.oldre - t_point.oldim * \
			t_point.oldim + t_options.cx;
		t_point.im = 2.0 * t_point.oldre * t_point.oldim + t_options.cy;
		if ((t_point.re * t_point.re + t_point.im * t_point.im) > 4)
			break ;
		counter++;
	}
	t_point.color = ft_make_color(counter % 256, counter, counter * 27);
	ft_put_img_pix(x, y, t_point.color);
}

/*
** This Function Checks A Point On The Screen To See If It Is
** Part Of The Mandelbar Set. Then Applies a color To that Pixel And
** Puts It On An Image
** Params:
** 	NAME		TYPE		DESCRIPTION
** 	 X			INT			current x coordinate on screen
** 	 Y			INT			current y coordinate on screen
** 	 i-max		INT			max iteration amount
*/
void	ft_mandelbar_escape(int x, int y, int i_max)
{
	int	counter;

	t_point.re = 1.5 * (x - t_map.w / 2) / (0.5 * t_pm.zoom * t_map.w) + \
		t_pm.movex;
	t_point.im = (y - t_map.h / 2) / (0.5 * t_pm.zoom * t_map.h) + t_pm.movey;
	t_point.newre = 0;
	t_point.newim = 0;
	t_point.oldre = 0;
	t_point.oldim = 0;
	counter = 0;
	while (counter < i_max)
	{
		t_point.oldre = t_point.newre;
		t_point.oldim = t_point.newim;
		t_point.newre = t_point.oldre * t_point.oldre - t_point.oldim * \
			t_point.oldim + t_point.re;
		t_point.newim = -2.0 * t_point.oldre * t_point.oldim + t_point.im;
		if ((t_point.newre * t_point.newre + t_point.newim * t_point.newim) > 4)
			break ;
		counter++;
	}
	t_point.color = ft_make_color(counter * 15, counter * 15, 255);
	ft_put_img_pix(x, y, t_point.color);
}
