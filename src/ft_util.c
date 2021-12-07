/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:16:05 by kamin             #+#    #+#             */
/*   Updated: 2021/12/08 03:37:25 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

/*
** This Function Calculates How Many Charachters A String Is Made Up Of.
** Params:
** 	NAME		Type		Description
** 	 str		String			The String To Count
*/
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	len++;
	return (len - 1);
}

/*
** This Functions Prints An Error Message In Console To The User.
** Params:
** 	NAME		TYPE		Description
** 	 exception	INT				Error Code To Display
*/
void	ft_error_handler(int exception)
{
	if (exception == 0)
		printf("Please enter a type of fractal\n");
	else if (exception == 1)
		printf("The chosen Fractol Is Not Implemented.\n");
	else if (exception == 2)
		printf("The Julia Fractol Requires Exactly\
				TWO Arguments Of Type Double\n");
	else if (exception == 3)
		printf("The Julia Arguments Entered Are Not Valid,\
				Must Be Number Of Type Double.\n");
	else if (exception == 4)
		printf("The Mandelbrot\\Mandelbar Fractol Doesnt Take Arguments\n");
}

/*
** This Function Compares Two Strings To Eachother To See If
** They Are The Same.
** Params:
** 	NAME		TYPE		Description
** 	 s1			String			String One To Compare
** 	 s2			String			String Two To Compare
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
** This functions Converts A String To Its Number Equivalent
** Params:
** 	NAME		TYPE		Description
** 	 str		String			String to be converted to number.
*/
long	ft_atoi(const char *str)
{
	long	final;
	long	sign;

	final = 0;
	sign = 1;
	while (*str == '\t' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == '\n' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str > 47 && *str < 58)
	{
		final = (final * 10) + *str - 48;
		str++;
	}
	return (final * sign);
}

/*
** This functions Converts A String To Its Number Equivalent With
** Decimal Points.
** Params:
** 	NAME		TYPE		Description
** 	 nbr		String			String to be converted to number.
*/
double	ft_atof(const char *nbr)
{
	double	in;
	double	dec;
	double	sign;
	int		len;

	sign = 1;
	in = (double)ft_atoi(nbr);
	if (*nbr == '-')
	{
		sign *= -1;
		nbr++;
	}
	while (*nbr && *nbr != '.')
		nbr++;
	if (*nbr == '.')
		nbr++;
	len = ft_strlen((char *)nbr) + 1;
	dec = (double)ft_atoi(nbr);
	while (len--)
		dec /= 10;
	return ((in + dec) * sign);
}
