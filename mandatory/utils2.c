/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:28 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:16:29 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

void	clean(t_fract *fract)
{
	if (fract->mlx)
		mlx_close_window(fract->mlx);
	if (fract->mlx && fract->img)
		mlx_delete_image(fract->mlx, fract->img);
	if (fract->mlx)
		mlx_terminate(fract->mlx);
}

void	ft_protect(void *s)
{
	write(2, "error\n", 6);
	free(s);
	exit(EXIT_FAILURE);
}
