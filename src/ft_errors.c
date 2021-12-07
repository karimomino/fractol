/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:59:11 by kamin             #+#    #+#             */
/*   Updated: 2021/12/08 03:41:12 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
#include "../includes/ft_structs.h"

void	julia_error(int *error)
{
	if (t_options.ac != 4)
		*error = 2;
	else if (!(check_op(t_options.av[2]) && check_op(t_options.av[3])))
		*error = 3;
	else
	{
		t_options.frac = 1;
		t_options.cx = ft_atof(t_options.av[2]);
		t_options.cy = ft_atof(t_options.av[3]);
	}
}
