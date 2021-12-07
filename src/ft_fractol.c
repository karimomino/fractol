/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 05:19:37 by kamin             #+#    #+#             */
/*   Updated: 2021/12/08 03:45:04 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/ft_fractol.h"
#include "../includes/ft_structs.h"

/*
** This Function Initializes All The variables That Need To Be Initialized
** Inside Our Structures In The ft_structs.h File.
*/
void	ft_init_structs(void)
{
	t_map.h = 900;
	t_map.w = 1440;
	t_map.i_max = 300;
	t_map.x = 0;
	t_map.y = 0;
	t_pm.movex = 0;
	t_pm.movey = 0;
	t_pm.zoom = 0.7;
}

/*
** This Function Iterates All The Pixels On Screen Based On The
** Window Size And Checks To See If It's Part Of The Selected Fractal.
** Params:
** 	NAME		TYPE		Description
** 	 w			Int			Width Of The Window
** 	 h			Int			Height Of The Window
** 	 option		Int			The Selected Fractal
*/
void	ft_print_frac(int w, int h, int option)
{
	t_map.x = 0;
	t_map.y = 0;
	while (t_map.y < h)
	{
		while (t_map.x < w)
		{
			if (option == 0)
				ft_mandelbrot_escape(t_map.x, t_map.y, t_map.i_max);
			else if (option == 1)
				ft_julia_escape(t_map.x, t_map.y, t_map.i_max);
			else if (option == 2)
				ft_mandelbar_escape(t_map.x, t_map.y, t_map.i_max);
			t_map.x++;
		}
		t_map.x = 0;
		t_map.y++;
	}
}

/*
** This Function Checks Which Fractal Was Selected By The User
** And Does Error Checking On The User Input.
** Params:
** 	NAME		TYPE		Description
** 	 fractol	String		The name of the fractal selected By the user
*/
void	ft_fractol(char *fractol)
{
	int	error;

	error = -1;
	if (!ft_strcmp(fractol, "mandelbrot") || !ft_strcmp(fractol, "mandelbar"))
	{
		if (t_options.ac != 2)
			error = 4;
		else if (!ft_strcmp(fractol, "mandelbar"))
			t_options.frac = 2;
		else
			t_options.frac = 0;
	}
	else if (!ft_strcmp(fractol, "julia"))
		julia_error(&error);
	else
		error = 1;
	if (error != -1)
		ft_error_handler(error);
	else
	{
		init_screen();
		ft_print_frac(t_map.w, t_map.h, t_options.frac);
		mlx_loops();
	}
}

/*
** This Function Checks If The User Input For The Fractal Arguments
** Is A Valid Input.
** Params:
** 	NAME		TYPE		Description
** 	 op			String		The input to verify
*/
int	check_op(char *op)
{
	int	valid;
	int	dec;

	valid = 1;
	dec = 0;
	if (*op == '-')
		op++;
	if (!((*op > 47) && (*op < 58)))
		valid = 0;
	while (valid && *op)
	{
		if ((*op == '.' && dec > 1))
			valid = 0;
		if (*op != '.' && !((*op > 47) && (*op < 58)))
			valid = 0;
		op++;
	}
	return (valid);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		ft_error_handler(0);
	else
	{
		ft_init_structs();
		t_options.ac = argc;
		t_options.av = argv;
		ft_fractol(argv[1]);
		return (0);
	}
}
