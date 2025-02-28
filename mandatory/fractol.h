/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:16:47 by doaghmir          #+#    #+#             */
/*   Updated: 2025/02/25 16:16:48 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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
}				t_fract;

int				ft_strlen(char *s);
void			ft_putendl_fd(char *s, int fd);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(char *str);
void			ft_free(char **str);
void			fatals(t_fract *fract, int flag);
int				ft_rgba(int r, int g, int b, int a);
int				get_color(int i, t_fract *fract);
double			ft_atof(char *str);
void			ft_draw(t_fract *fract);
void			draw_julia(t_fract *fract);
void			ft_hooks(void *arg);
double			ft_atof(char *str);
void			clean(t_fract *fract);
void			ft_scroll(double x, double y, void *param);
void			ft_protect(void *s);
#endif
