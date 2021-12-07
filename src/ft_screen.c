/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 05:19:40 by kamin             #+#    #+#             */
/*   Updated: 2021/12/08 03:45:37 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
#include "../includes/ft_structs.h"

/*
** This Function Initializes The Program Window And Creates A New Image
*/
void	init_screen(void)
{
	t_map.mlx = mlx_init();
	t_map.win = mlx_new_window(t_map.mlx, t_map.w, t_map.h,
			t_options.av[1]);
	t_img.img = mlx_new_image(t_map.mlx, t_map.w, t_map.h);
	t_img.addr = mlx_get_data_addr(t_img.img, &t_img.bits_per_pixel,
			&t_img.line_length, &t_img.endian);
}

/*
** This Function Will Redraw The Chosen Fractal
*/
void	ft_redraw(void)
{
	mlx_destroy_image(t_map.mlx, t_img.img);
	mlx_clear_window(t_map.mlx, t_map.win);
	t_img.img = mlx_new_image(t_map.mlx, t_map.w, t_map.h);
	t_img.addr = mlx_get_data_addr(t_img.img, &t_img.bits_per_pixel,
			&t_img.line_length, &t_img.endian);
	ft_print_frac(t_map.w, t_map.h, t_options.frac);
	mlx_put_image_to_window(t_map.mlx, t_map.win, t_img.img, 0, 0);
}

void	ft_move(int key)
{
	if (key == 123)
		t_pm.movex -= 0.07;
	else if (key == 124)
		t_pm.movex += 0.070;
	else if (key == 125)
		t_pm.movey += 0.070;
	else if (key == 126)
		t_pm.movey -= 0.070;
	ft_redraw();
}
