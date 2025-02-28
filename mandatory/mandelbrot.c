/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:36 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:16:37 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mandelbroot(t_fract *fract)
{
	int		i;
	double	real1;
	double	imag1;

	i = 0;
	fract->z.imag = 0;
	fract->z.real = 0;
	while (i < fract->max_iter)
	{
		imag1 = fract->z.imag * fract->z.imag;
		real1 = fract->z.real * fract->z.real;
		fract->z.imag = 2 * fract->z.real * fract->z.imag + fract->c.imag;
		fract->z.real = real1 - imag1 + fract->c.real;
		if (real1 + imag1 > 4)
			break ;
		i++;
	}
	if (i == fract->max_iter)
		fract->color = ft_rgba(0, 0, 0, 255);
	else
		fract->color = get_color(i, fract);
}

void	ft_draw(t_fract *fract)
{
	int		x;
	int		y;
	double	weidht_scale;
	double	highest_scale;

	weidht_scale = (4.0 / WIDTH) * fract->zoom;
	highest_scale = (4.0 / HEIGHT) * fract->zoom;
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			fract->c.real = (x - WIDTH / 2) * weidht_scale + fract->centre.real;
			fract->c.imag = (y - HEIGHT / 2) * highest_scale
				+ fract->centre.imag;
			ft_mandelbroot(fract);
			mlx_put_pixel(fract->img, x, y, fract->color);
		}
	}
}
