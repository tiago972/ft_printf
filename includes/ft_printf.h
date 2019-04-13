/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:59:30 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/13 15:46:03 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# define BUFF_SIZE 2048
# define HASH_TAG (1 << 0)
# define ZERO (1 << 1)
# define MINUS (1 << 2)
# define SPACE (1 << 3)
# define PLUS (1 << 4)
# define F_WIDTH (1 << 5)
# define DOT (1 << 6)
# define STAR (1 << 7)
# define H (1 << 8)
# define HH (1 << 9)
# define L (1 << 10)
# define LL (1 << 11)
# define C (1 << 0)
# define S (1 << 1)
# define U (1 << 2)
# define D (1 << 3)
# define X (1 << 4)
# define XX (1 << 5)
# define O (1 << 6)
# define P (1 << 7)
# define F (1 << 8)

typedef struct	s_printf
{
	int				flags;
	int				prec;
	int				conv_type;
	va_list			ap;
	char			*str;
	int				ret_progress;
	int				ret_tot;
	long int		width;
	char			buff[BUFF_SIZE];
	intmax_t		curr_len;
	char			*var_str;
	intmax_t		var_i;
	uintmax_t		var_u;
	char			var_c;
	long double		var_float;
	int				tmp;
	int				precision;
}				t_printf;
int				ft_printf(const char *str, ...);
void			ft_buff(t_printf *v_printf, char *str, int n);
void			ft_flush(t_printf *v_printf);
void			ft_write(t_printf *v_printf);
void			ft_parse_opt(t_printf *v_printf);
void			ft_pf_putstr(t_printf *v_printf);
void			ft_parse_conv(t_printf *v_printf);
void			ft_parse_width(t_printf *v_printf);
void			ft_pad_str(t_printf *v_printf);
void			ft_pad_i(t_printf *v_printf, int b_size, char *base);
intmax_t		ft_get_arg_i(t_printf *v_printf);
intmax_t		ft_power_i(intmax_t nb, int b_size);
uintmax_t		ft_power_u(uintmax_t nb, unsigned b_size);
void			ft_pf_putnbr_i(t_printf *v_printf, intmax_t nb, int b_size,
				char *base);
uintmax_t		ft_get_arg_u(t_printf *v_printf);
void			ft_pad_u(t_printf *v_printf, int b_size, char *base, int opt);
void			ft_pf_putnbr_u(t_printf *v_printf, uintmax_t nb, int b_size,
				char *base);
void			ft_parse_arg_size(t_printf *v_printf);
void			ft_pad_c(t_printf *v_printf);
void			ft_fill(t_printf *v_printf, int len);
void			ft_pad_f(t_printf *v_printf);
int				ft_iterative_power(int nb, int power);
void			ft_pf_putfloat(t_printf *v_printf);
void			ft_parse_precision(t_printf *v_printf);

# endif
