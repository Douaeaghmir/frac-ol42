/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:44 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:30:45 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	ft_tricon(t_fract *fract)
{
	double	real1;
	double	imag1;
	int		i;

	fract->z.real = 0;
	fract->z.imag = 0;
	i = 0;
	while (i < fract->max_iter)
	{
		imag1 = fract->z.imag * fract->z.imag;
		real1 = fract->z.real * fract->z.real;
		fract->z.imag = -2 * fract->z.real * fract->z.imag + fract->c.imag;
		fract->z.real = real1 - imag1 + fract->c.real;
		i++;
		if (real1 + imag1 > 4)
			break ;
	}
	if (i == fract->max_iter)
		fract->color = ft_rgba_bonus(0, 0, 0, 255);
	else
		fract->color = get_color_bonus(i, fract);
}

void	ft_draw_bonus(t_fract *fract)
{
	double	width;
	double	hight;
	int		x;
	int		y;

	width = (4.0 / WIDTH) * fract->zoom;
	hight = (4.0 / HEIGHT) * fract->zoom;
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			fract->c.real = (x - WIDTH / 2) * width + fract->centre.real;
			fract->c.imag = (y - HEIGHT / 2) * hight + fract->centre.imag;
			ft_tricon(fract);
			mlx_put_pixel(fract->img, x, y, fract->color);
		}
	}
}
