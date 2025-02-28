/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:46 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:30:47 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_free_bonus(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}

void	clean_bonus(t_fract *fract)
{
	if (fract->mlx)
		mlx_close_window(fract->mlx);
	if (fract->mlx && fract->img)
		mlx_delete_image(fract->mlx, fract->img);
	if (fract->mlx)
		mlx_terminate(fract->mlx);
}

void	handle_movement_bonus(t_fract *fract, double move_step)
{
	double	dx;
	double	dy;

	dx = 0.0;
	dy = 0.0;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_UP))
		dy -= move_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_DOWN))
		dy += move_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_RIGHT))
		dx += move_step;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_LEFT))
		dx -= move_step;
	fract->centre.real += dx;
	fract->centre.imag += dy;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_KP_ADD) && fract->max_iter < 500)
		fract->max_iter += 30;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_KP_SUBTRACT)
		&& fract->max_iter > 20)
		fract->max_iter -= 30;
}
