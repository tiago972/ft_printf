/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:59:30 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 17:55:45 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
#include <string.h>
# define BUFF_SIZE 2048
# define MINUS (1 << 0)
# define PLUS (1 << 1)
# define ZERO (1 << 2)
# define SP (1 << 3)
# define POUND (1 << 4)
# define DOT (1 << 5)
# define H (1 << 6)
# define HH (1 << 7)
# define L (1 << 8)
# define LL (1 << 9)

typedef struct	s_printf
{
	char		*str;
	int			flags;
	int			width;
	int			prec;
	char		buff[BUFF_SIZE + 1];
	int			ret_progress;
	int			ret_tot;
	va_list		ap;
	int			tmp;
}				t_printf;
typedef struct	s_funptr
{
	char	conv;
	void	(*f)(t_printf *);
}				t_funptr;
int				ft_printf(const char *str, ...);
void			ft_buff(t_printf *v_printf, char *str, int n);
void			ft_inifunptr(t_funptr funptr[10]);
void			ft_get_info(t_printf *v_printf, t_funptr funptr[10]);
void			ft_dispatch(t_printf *v_printf, t_funptr funptr[10]);
uintmax_t		ft_power(uintmax_t nb, uintmax_t base);
void			ft_pad_c(t_printf *v_printf);
void			ft_pad_s(t_printf *v_printf);
void			ft_pad_i(t_printf *v_printf);
void			ft_pad_x(t_printf *v_printf);
void			ft_pad_X(t_printf *v_printf);
void			ft_pad_o(t_printf *v_printf);
void			ft_pad_u(t_printf *v_printf);
void			ft_pad_p(t_printf *v_printf);
void			ft_pad_escape(t_printf *v_printf);
void			ft_dispatch_j(t_printf *v_printf);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
intmax_t		ft_get_arg_i(t_printf *v_printf);
void			ft_putnbr_pf(t_printf *v_printf, intmax_t n);
void			ft_get_precision(t_printf *v_printf);
uintmax_t		ft_abs(intmax_t a);
void			ft_llong_min(t_printf *v_printf, intmax_t int_arg);
void			ft_fill_nb_i(t_printf *v_printf, intmax_t int_arg, int opt);
uintmax_t		ft_get_arg_u(t_printf *v_printf);
void			ft_putnbr_pf_u(t_printf *v_printf, uintmax_t nb, char *base,
				uintmax_t size_b, uintmax_t power);

# include <stdio.h>
# endif
