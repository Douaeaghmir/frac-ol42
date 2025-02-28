/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:40 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:30:41 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_finish_bonus(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(fract->mlx);
		mlx_delete_image(fract->mlx, fract->img);
		mlx_terminate(fract->mlx);
		exit(EXIT_FAILURE);
	}
}

void	ft_maxitter_bonus(t_fract *fract)
{
	if (mlx_is_key_down(fract->mlx, MLX_KEY_KP_ADD) && fract->max_iter < 500)
		fract->max_iter += 30;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_KP_SUBTRACT)
		&& fract->max_iter > 20)
		fract->max_iter -= 30;
}

void	ft_hooks_bonus(void *arg)
{
	t_fract	*fract;
	double	moves;

	fract = (t_fract *)arg;
	moves = 0.04 * fract->zoom;
	ft_maxitter_bonus(fract);
	ft_finish_bonus(fract);
	if (mlx_is_key_down(fract->mlx, MLX_KEY_SPACE))
		fract->color_shift = (fract->color_shift + 1) % 3;
	handle_movement_bonus(fract, moves);
	if (!ft_strcmp_bonus(fract->name, "tricon"))
		ft_draw_bonus(fract);
}

void	ft_scroll_bonus(double x, double y, void *param)
{
	t_fract	*fract;
	double	zoom_fract;
	double	old_zoom;
	int		wheel_x;
	int		wheel_y;

	fract = (t_fract *)param;
	(void)x;
	zoom_fract = 1.1;
	old_zoom = fract->zoom;
	mlx_get_mouse_pos(fract->mlx, &wheel_x, &wheel_y);
	if (y > 0)
		fract->zoom /= zoom_fract;
	if (y < 0)
		fract->zoom *= zoom_fract;
	fract->centre.real += ft_sclae(wheel_x, 2, -2, WIDTH) * (old_zoom
			- fract->zoom);
	fract->centre.imag += ft_sclae(wheel_y, 2, -2, HEIGHT) * (old_zoom
			- fract->zoom);
	ft_draw_bonus(fract);
}

double	ft_sclae(double value, double max, double min, double demention)
{
	return ((value / demention) * (max - min) + min);
}
