/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:59:30 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/17 19:33:12 by edbaudou         ###   ########.fr       */
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
# define DOT (1 << 4)
# define H (1 << 5)
# define HH (1 << 6)
# define L (1 << 7)
# define LL (1 << 8)

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
int				ft_min(int a, int b);
int				ft_max(int a, int b);
intmax_t		ft_get_arg_i(t_printf *v_printf);
void			ft_putnbr_pf(t_printf *v_printf, intmax_t n);
void			ft_get_precision(t_printf *v_printf);
uintmax_t		ft_abs(intmax_t a);

# include <stdio.h>
# endif
