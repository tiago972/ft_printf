/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:59:30 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/07 15:46:41 by edbaudou         ###   ########.fr       */
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
# define N_PRECISE (1 << 6)
# define STAR (1 << 7)
# define H (1 << 8)
# define HH (1 << 9)
# define L (1 << 10)
# define LL (1 << 11)

typedef struct	s_printf
{
	int				flags;
	int				field_width;
	int				prec;
	int				len_modifier;
	va_list			ap;
	char			*str;
	int				ret_progress;
	int				ret_tot;
	long int		width;
	char			buff[BUFF_SIZE];
	int				curr_len;
	char			*var_str;
	intmax_t		var_i;
	uintmax_t		var_u;
	char			var_c;
	uintptr_t		var_p;
	float			var_float;
	int				tmp;
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
void			ft_pad_u(t_printf *v_printf, int b_size, char *base);
void			ft_pf_putnbr_u(t_printf *v_printf, uintmax_t nb, int b_size,
				char *base);
void			ft_parse_arg_size(t_printf *v_printf);
void			ft_pad_c(t_printf *v_printf);
void			ft_pad_p(t_printf *v_printf);
# endif
