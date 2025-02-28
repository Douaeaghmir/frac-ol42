/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:43 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:16:44 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_itter(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_KP_ADD) && fract->max_iter < 500)
		fract->max_iter += 30;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_KP_SUBTRACT)
		&& fract->max_iter > 20)
		fract->max_iter -= 30;
}

static void	ft_finish(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(fract->mlx);
		mlx_delete_image(fract->mlx, fract->img);
		mlx_terminate(fract->mlx);
		exit(EXIT_FAILURE);
	}
}

void	ft_hooks(void *arg)
{
	t_fract	*fract;

	fract = (t_fract *)arg;
	ft_itter(fract);
	ft_finish(fract);
	if (!ft_strcmp(fract->name, "mandelbrot"))
		ft_draw(fract);
	if (!ft_strcmp(fract->name, "julia"))
		draw_julia(fract);
}
