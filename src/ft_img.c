/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:24:42 by kamin             #+#    #+#             */
/*   Updated: 2021/12/07 20:46:53 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
#include "../includes/ft_structs.h"

/*
** This function pushes a pixel to an image.
** NOTE: This function should not be used with an image thats
** already on screen to ovid clipping in the image.
** 		Add Another Temp image to push to first before changing the
** 		displayed image on screen.
*/
void	ft_put_img_pix(int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * t_img.line_length + (x * (t_img.bits_per_pixel / 8)));
	dst = t_img.addr + offset;
	*(unsigned int *)dst = color;
}

/*
** This Function Generates An HSV Color
** Params:
** 	NAME		TYPE		DESCRIPTION
** 	 hue		FLOAT		Hue value of color
** 	 sat		FLOAT		Saturation value of color
** 	 val		FLOAT		Value of color
*/
int	ft_make_color(float hue, float sat, float val)
{
	float	f;

	t_col.h = hue / 256.0;
	t_col.s = sat / 256.0;
	t_col.v = val / 256.0;
	if (t_col.s == 0)
		return (0 << 24 | col(t_col.v) << 16 \
		| col(t_col.v) << 8 | col(t_col.v));
	else
	{
		t_col.h *= 6;
		t_col.m = (int)floor(t_col.h);
		f = t_col.h - t_col.m;
		t_col.a = t_col.v * (1 - t_col.s);
		t_col.bb = t_col.v * (1 - (t_col.s * f));
		t_col.c = t_col.v * (1 - (t_col.s * (1 - f)));
	}
	return (ft_hsv_rgb(t_col.v, t_col.a, t_col.bb, t_col.c));
}

/*
** This Function Converts A Color From HSV Format To RGB
*/
int	ft_hsv_rgb(float v, float a, float bb, float c)
{
	if (t_col.m == 0)
		return (0 << 24 | col(v) << 16 | col(c) << 8 | col(a));
	else if (t_col.m == 1)
		return (0 << 24 | col(bb) << 16 | col(v) << 8 | col(a));
	else if (t_col.m == 2)
		return (0 << 24 | col(bb) << 16 | col(v) << 8 | col(c));
	else if (t_col.m == 3)
		return (0 << 24 | col(a) << 16 | col(bb) << 8 | col(v));
	else if (t_col.m == 4)
		return (0 << 24 | col(a) << 16 | col(a) << 8 | col(v));
	else if (t_col.m == 5)
		return (0 << 24 | col(v) << 16 | col(a) << 8 | col(bb));
	return (0);
}

/*
** This Function Multiplies A Value By 255
*/
int	col(float val)
{
	return ((val * 255));
}
