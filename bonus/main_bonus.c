/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:42 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:30:43 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

char	*ft_init_bonus(int ac, char **av, t_fract *fract)
{
	if (!fract)
		(write(2, "error2\n", 7), exit(EXIT_FAILURE));
	if (ac < 2)
		return (NULL);
	if (ac == 2)
	{
		if (fract->name && !ft_strcmp_bonus(av[1], "tricon"))
			return (ft_strdup_bonus("tricon"));
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_fract	fract;

	fract.mlx = NULL;
	fract.img = NULL;
	fract.name = ft_init_bonus(ac, av, &fract);
	if (!fract.name)
		(write(2, "error\n", 6), exit(EXIT_FAILURE));
	if (HEIGHT < 0 || WIDTH < 0)
		(write(2, "error4\n", 7), exit(EXIT_FAILURE));
	fract.mlx = mlx_init(WIDTH, HEIGHT, fract.name, false);
	if (!fract.mlx)
		(write(2, "error\n", 6), exit(EXIT_FAILURE));
	fract.img = mlx_new_image(fract.mlx, WIDTH, HEIGHT);
	if (!fract.img)
		(write(2, "error\n", 6), exit(EXIT_FAILURE));
	fract.max_iter = 100;
	fract.zoom = 1.0;
	fract.centre.real = 0.0;
	fract.centre.imag = 0.0;
	mlx_image_to_window(fract.mlx, fract.img, 0, 0);
	mlx_scroll_hook(fract.mlx, (void *)ft_scroll_bonus, &fract);
	mlx_loop_hook(fract.mlx, ft_hooks_bonus, &fract);
	mlx_loop(fract.mlx);
	ft_free_bonus((char **)&fract.name);
	clean_bonus(&fract);
}
