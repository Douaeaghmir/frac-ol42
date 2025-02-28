/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:34 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:30:35 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_rgba_bonus(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_color_bonus(int i, t_fract *fract)
{
	double	t;

	if (i == fract->max_iter)
		return (ft_rgba_bonus(0, 0, 0, 255));
	t = (double)i / fract->max_iter;
	if (fract->color_shift == 0)
		return (ft_rgba_bonus(255 * pow(t, 0.3), 125 * pow(t, 0.5), 150 * pow(1
					- t, 2), 255));
	else if (fract->color_shift == 1)
		return (ft_rgba_bonus(255 * pow(t, 0.5), 50 * (1 - t), 125 * pow(t,
					0.3), 255));
	else if (fract->color_shift == 2)
		return (ft_rgba_bonus(255 * pow(t, 0.4), 50 * (1 - t), 120 * pow(1 - t,
					0.6), 255));
	return (ft_rgba_bonus(255, 255, 255, 255));
}
