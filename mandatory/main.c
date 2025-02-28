/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:39 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:16:40 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_scroll(double x, double y, void *param)
{
	t_fract	*fract;
	double	zoom;

	fract = (t_fract *)param;
	zoom = 1.1;
	(void)x;
	if (y > 0)
		fract->zoom /= zoom;
	if (y < 0)
		fract->zoom *= zoom;
}

char	*init_fract(int ac, char **av, t_fract *fract)
{
	if (!fract)
		(write(2, "error\n", 6), exit(EXIT_FAILURE));
	if (ac < 2)
		return (NULL);
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			return (ft_strdup("mandelbrot"));
	}
	else if (!ft_strcmp(av[1], "julia"))
	{
		if (ac < 4)
			return (NULL);
		fract->c.real = ft_atof(av[2]);
		fract->c.imag = ft_atof(av[3]);
		fract->move.real = 2.0;
		fract->move.imag = 2.0;
		fract->scale = 1.0;
		return (ft_strdup("julia"));
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_fract	fract;

	fract.mlx = NULL;
	fract.img = NULL;
	fract.name = init_fract(ac, av, &fract);
	if (!fract.name)
		ft_protect(fract.name);
	if (WIDTH < 0 && HEIGHT < 0)
		(write(2, "error\n", 6), exit(EXIT_FAILURE));
	fract.mlx = mlx_init(WIDTH, HEIGHT, fract.name, false);
	if (!fract.mlx)
		ft_protect(fract.mlx);
	fract.img = mlx_new_image(fract.mlx, WIDTH, HEIGHT);
	if (!fract.img)
		ft_protect(fract.img);
	fract.max_iter = 100;
	fract.zoom = 1.0;
	mlx_image_to_window(fract.mlx, fract.img, 0, 0);
	mlx_scroll_hook(fract.mlx, (void *)ft_scroll, &fract);
	mlx_loop_hook(fract.mlx, ft_hooks, &fract);
	mlx_loop(fract.mlx);
	ft_free((char **)&fract.name);
	clean(&fract);
}
