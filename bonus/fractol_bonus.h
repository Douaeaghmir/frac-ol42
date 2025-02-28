/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:37 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:30:38 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define WIDTH 1200
# define HEIGHT 920

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_fract
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*name;
	t_complex	z;
	t_complex	c;
	t_complex	centre;
	t_complex	move;
	int			color;
	int			max_iter;
	double		zoom;
	double		scale;
	int			color_shift;
}				t_fract;
int				ft_rgba_bonus(int r, int g, int b, int a);
int				get_color_bonus(int i, t_fract *fract);
void			ft_finish_bonus(t_fract *fract);
void			ft_maxitter_bonus(t_fract *fract);
void			ft_hooks_bonus(void *arg);
void			ft_draw_bonus(t_fract *fract);
void			clean_bonus(t_fract *fract);
void			ft_free_bonus(char **s);
int				ft_strcmp_bonus(char *s1, char *s2);
char			*ft_strdup_bonus(char *str);
char			*ft_init_bonus(int ac, char **av, t_fract *fract);
void			ft_scroll_bonus(double x, double y, void *param);
double			ft_sclae(double value, double max, double min,
					double demention);
void			handle_movement_bonus(t_fract *fractal, double move_step);
#endif
