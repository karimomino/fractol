/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:53:30 by kamin             #+#    #+#             */
/*   Updated: 2021/12/08 03:44:36 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

struct	s_map
{
	int		w;
	int		h;
	int		i_max;
	int		x;
	int		y;
	void	*win;
	void	*mlx;
}		t_map;

struct	s_point
{
	double	re;
	double	im;
	double	oldre;
	double	newre;
	double	oldim;
	double	newim;
	int		color;
}		t_point;

struct		s_color
{
	float	h;
	float	s;
	float	v;
	float	a;
	float	bb;
	float	c;
	int		m;

}			t_col;

struct s_pm
{
	double	zoom;
	double	movex;
	double	movey;
} t_pm;

struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img;

struct s_mp
{
	int	x;
	int	y;
}		t_mp;

struct	s_options
{
	int		ac;
	char	**av;
	int		frac;
	float	cx;
	float	cy;
}		t_options;

#endif
