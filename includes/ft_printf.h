/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:59:30 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/05 20:33:42 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# define BUFF_SIZE 2048
# define HASH_TAG (1 << 0)
# define ZERO (1 << 1)
# define MINUS (1 << 2)
# define SPACE (1 << 3)
# define PLUS (1 << 4)
# define F_WIDTH (1 << 5)
# define F_STAR (1 << 6)
# define N_PRECISE (1 << 7)
# define N_STAR (1 << 8)
# define H (1 << 9)
# define HH (1 << 10)
# define L (1 << 11)
# define LL (1 << 12)

typedef struct	s_printf
{
	int			flags;
	int			field_width;
	int			prec;
	int			len_modifier;
	va_list		ap;
	char		*str;
	int			ret_progress;
	int			ret_tot;
	int			width;
	char		buff[BUFF_SIZE];
	int			curr_len;
	char		*var_char;
	int			var_int;
	float		var_float;
	int			tmp;
}				t_printf;
int				ft_printf(const char *str, ...);
void			ft_buff(t_printf *v_printf, char *str, int n);
void			ft_flush(t_printf *v_printf);
void			ft_write(t_printf *v_printf);
void			ft_parse_opt(t_printf *v_printf);
void			ft_pf_putstr(t_printf *v_printf);
void			ft_parse_conv(t_printf *v_printf);
void			ft_parse_width(t_printf *v_printf);

# endif
