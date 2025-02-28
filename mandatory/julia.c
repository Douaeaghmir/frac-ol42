/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:41 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:16:42 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_julia(t_fract *fract, int x, int y)
{
	int		i;
	double	hold;

	i = 0;
	fract->z.real = -((double)x - WIDTH / 2.0) * fract->zoom * 4.0 / WIDTH
		+ fract->centre.real;
	fract->z.imag = ((double)y - HEIGHT / 2.0) * fract->zoom * 4.0 / HEIGHT
		+ fract->centre.imag;
	while (i < fract->max_iter)
	{
		hold = fract->z.real * fract->z.real - fract->z.imag * fract->z.imag
			+ fract->c.real;
		fract->z.imag = 2 * fract->z.real * fract->z.imag + fract->c.imag;
		fract->z.real = hold;
		if (fract->z.real * fract->z.real + fract->c.imag * fract->c.imag > 4)
			break ;
		i++;
	}
	if (i == fract->max_iter)
		fract->color = ft_rgba(0, 0, 0, 255);
	else
		fract->color = get_color(i, fract);
}

void	draw_julia(t_fract *fract)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			ft_julia(fract, x, y);
			mlx_put_pixel(fract->img, x, y, fract->color);
		}
	}
}
