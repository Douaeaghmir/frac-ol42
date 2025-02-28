/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:34 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:16:35 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	the_beginning(char *s, int *i)
{
	int	res;

	res = 0;
	if (s[*i] == '-' || s[*i] == '+')
		(*i)++;
	while (s[*i] && s[*i] != '.')
	{
		if (s[*i] < '0' || s[*i] > '9')
			(write(2, "error\n", 6), exit(EXIT_FAILURE));
		res = res * 10 + (s[*i] - 48);
		(*i)++;
	}
	return (res);
}

static double	th_end(char *s)
{
	double	frac;
	double	res;

	frac = 1;
	res = 0;
	if (*s == '.')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			(write(2, "error\n", 6), exit(EXIT_FAILURE));
		frac /= 10;
		res += frac * (*s - 48);
		s++;
	}
	return (res);
}

double	ft_atof(char *str)
{
	int		first;
	double	last;
	int		sign;
	int		i;
	int		x;

	i = 0;
	x = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i] || str[i] == '+' || str[i] == '-')
		(write(2, "error\n", 6), exit(EXIT_FAILURE));
	first = the_beginning(str, &x);
	last = th_end(str + x);
	return ((last + first) * sign);
}
