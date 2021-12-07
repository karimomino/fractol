/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:18:25 by kamin             #+#    #+#             */
/*   Updated: 2021/12/08 03:45:13 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/ft_fractol.h"
#include "../includes/ft_structs.h"

int	key_hook(int keycode, __attribute__((unused)) void *x)
{
	if (keycode == 53)
	{
		mlx_destroy_image(t_map.mlx, t_img.img);
		mlx_clear_window(t_map.mlx, t_map.win);
		mlx_destroy_window(t_map.mlx, t_map.win);
		exit(0);
	}
	else if (keycode == 13 || keycode == 1)
		ft_zoom(keycode);
	else if (keycode > 122 && keycode < 127)
		ft_move(keycode);
	return (0);
}

int	ft_mouse(void)
{
	mlx_mouse_get_pos(t_map.win, &t_mp.x, &t_mp.y);
	return (0);
}

void	ft_zoom(int key)
{
	if (key == 13)
	{
		t_pm.zoom += 0.07;
		t_pm.movex = (t_mp.x - t_map.w / 2) * 0.003 / t_pm.zoom - 0.5;
		t_pm.movey = (t_mp.y - t_map.h / 2) * 0.003 / t_pm.zoom - 0.5;
	}
	else
	{
		t_pm.zoom -= 0.07;
		t_pm.movex = (t_mp.x - t_map.w / 2) * 0.003 / t_pm.zoom - 0.5;
		t_pm.movey = (t_mp.y - t_map.h / 2) * 0.003 / t_pm.zoom - 0.5;
	}
	ft_redraw();
}

void	mlx_loops(void)
{
	mlx_put_image_to_window(t_map.mlx, t_map.win, t_img.img, 0, 0);
	mlx_hook(t_map.win, 2, 0, key_hook, (void *)0);
	mlx_loop_hook(t_map.mlx, ft_mouse, t_map.win);
	mlx_do_key_autorepeaton(t_map.mlx);
	mlx_loop(t_map.mlx);
}
