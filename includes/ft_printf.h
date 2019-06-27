/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:59:30 by edbaudou          #+#    #+#             */
/*   Updated: 2019/06/27 19:38:38 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <string.h>
# define F_SIZE 1001
# define BUFF_SIZE 2048
# define MINUS (1 << 0)
# define PLUS (1 << 1)
# define ZERO (1 << 2)
# define SP (1 << 3)
# define POUND (1 << 4)
# define DOT (1 << 5)
# define STAR (1 << 6)
# define H (1 << 7)
# define HH (1 << 8)
# define L (1 << 9)
# define LL (1 << 10)
# define LF (1 << 11)
# define C (1 << 0)
# define S (1 << 1)
# define D (1 << 2)
# define I (1 << 3)
# define O (1 << 4)
# define U (1 << 5)
# define X (1 << 6)
# define XX (1 << 7)
# define P (1 << 8)
# define J (1 << 9)
# define Z (1 << 10)
# define POURCENT (1 << 11)
# define UU (1 << 12)
# define F (1 << 13)

typedef struct	s_printf
{
	char			*str;
	int				flags;
	int				width;
	int				prec;
	int				conv;
	char			buff[BUFF_SIZE + 1];
	int				ret_progress;
	int				ret_tot;
	va_list			ap;
	int				tmp;
	uintmax_t		power;
}				t_printf;

typedef struct	s_float
{
	int			m;
	int			new_mag;
	int			exp;
	int			sign;
	char		*res;
	long double f_arg;
	long double	prec;
}				t_float;
typedef struct	s_funptr
{
	int		conv;
	void	(*f)(t_printf *);
}				t_funptr;
int				ft_printf(const char *str, ...);
void			ft_buff(t_printf *v_printf, char *str, int n);
void			ft_inifunptr(t_funptr funptr[13]);
void			ft_get_info(t_printf *v_printf, t_funptr funptr[13]);
void			ft_get_size(t_printf *v_printf);
void			ft_dispatch(t_printf *v_printf, t_funptr funptr[13]);
uintmax_t		ft_log(uintmax_t nb, uintmax_t base);
void			ft_pad_c(t_printf *v_printf);
void			ft_pad_s(t_printf *v_printf);
void			ft_pad_i(t_printf *v_printf);
void			ft_pad_p(t_printf *v_printf);
void			ft_pad_u(t_printf *v_printf);
void			ft_pad_f(t_printf *v_printf);
void			ft_pad_escape(t_printf *v_printf);
void			ft_dispatch_jz(t_printf *v_printf);
uintmax_t		ft_log_dispatch(t_printf *v_printf, uintmax_t uintarg);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
intmax_t		ft_get_arg_i(t_printf *v_printf);
void			ft_putnbr_pf(t_printf *v_printf, intmax_t n, uintmax_t power);
void			ft_get_conversion(t_printf *v_printf);
uintmax_t		ft_abs(intmax_t a);
void			ft_llong_min(t_printf *v_printf, intmax_t int_arg);
void			ft_fill_nb_i(t_printf *v_printf, intmax_t int_arg, int opt);
uintmax_t		ft_get_arg_u(t_printf *v_printf);
void			ft_putnbr_pf_u(t_printf *v_printf, uintmax_t nb, char *base,
				uintmax_t size_b, uintmax_t power);
void			ft_pad_nbr(t_printf *v_printf, uintmax_t uintarg);
void			ft_print_u(t_printf *v_printf, uintmax_t uintarg,
				uintmax_t power);
void			ft_get_width(t_printf *v_printf);
uintmax_t		ft_leading_zero(uintmax_t nb);
int				ft_particular_octal(t_printf *v_printf, uintmax_t uintarg);
long double		ft_get_arg_f(t_printf *v_printf);
long double		ft_iterative_power_f(long double power, long double n);
long double		ft_magnitude(t_float *f);
int				ft_sign_f(t_float *f);
long double		ft_floor(long double n);
intmax_t		ft_iterative_power(intmax_t nb, int power);
void			ft_round(t_float *f, t_printf *v_printf);
void			ft_ftoa(t_float *f, t_printf *v_printf);
void			ft_ftoa_2(t_float *f);
int				ft_isna(t_float *f, t_printf *v_printf);
int				ft_isinf(t_float *f, t_printf *v_printf);

# include <stdio.h>
# endif
