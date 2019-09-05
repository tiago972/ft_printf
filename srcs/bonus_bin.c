/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:35:58 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/05 20:28:46 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include <limits.h>

void	ft_bin_c(t_printf *v_printf)
{
	char			l;
	unsigned char	*res;
	unsigned		i; 

	l = (char)va_arg(v_printf->ap, int);
	res = (unsigned char *)&l;
	i = CHAR_BIT * sizeof(l);
	while (--i + 1 > 0)
	{
		(res[i / CHAR_BIT] & (1U << (i % CHAR_BIT))) ?
			ft_buff(v_printf, "1", 1) : ft_buff(v_printf, "0", 1);
		if (i % 8 == 0 && i != 0)
			ft_buff(v_printf, " ", 1);
	}
}

void	ft_bin_s(t_printf *v_printf)
{
	unsigned char	*res;
	unsigned		i; 

	res = (unsigned char *)va_arg(v_printf->ap, char *);
	i = CHAR_BIT * sizeof(res);
	while (--i + 1 > 0)
	{
		(res[i / CHAR_BIT] & (1U << (i % CHAR_BIT))) ?
			ft_buff(v_printf, "1", 1) : ft_buff(v_printf, "0", 1);
		if (i % 8 == 0 && i != 0)
			ft_buff(v_printf, " ", 1);
	}
}

void	ft_bin_i(t_printf *v_printf)
{
	char			*res;
	unsigned		i; 
	intmax_t		int_arg;

	int_arg = ft_get_arg_i(v_printf);
	res = (char *)&int_arg;
	i = CHAR_BIT * ft_size_i_b(v_printf);
	while (--i + 1 > 0)
	{
		(res[i / CHAR_BIT] & (1U << (i % CHAR_BIT))) ?
			ft_buff(v_printf, "1", 1) : ft_buff(v_printf, "0", 1);
		if (i % 8 == 0 && i != 0)
			ft_buff(v_printf, " ", 1);
	}
}

void	ft_bin_f(t_printf *v_printf)
{
	unsigned char	*res;
	unsigned		i; 
	float		f_arg;

	f_arg = (float)va_arg(v_printf->ap, double);
	res = (unsigned char *)&f_arg;
	i = CHAR_BIT * sizeof(float);
	while (--i + 1 > 0)
	{
		(res[i / CHAR_BIT] & (1U << (i % CHAR_BIT))) ?
			ft_buff(v_printf, "1", 1) : ft_buff(v_printf, "0", 1);
		if (i % 8 == 0 && i != 0)
			ft_buff(v_printf, " ", 1);
	}
}
void	ft_inifunptrb(t_funptrb funptrb[5])
{
	funptrb[0].conv |= C;
	funptrb[0].f = &ft_bin_c;
	funptrb[1].conv |= S;
	funptrb[1].f = &ft_bin_s;
	funptrb[2].conv |= I;
	funptrb[2].f = &ft_bin_i;
	funptrb[3].conv |= D;
	funptrb[3].f = &ft_bin_i;
	funptrb[4].conv |= F;
	funptrb[4].f = &ft_bin_f;
}

void	ft_funptrb_dispatch(t_printf *v_printf)
{
	int			i;
	t_funptrb funptrb[5];

	i = -1;
	ft_get_size(v_printf);
	ft_get_conversion(v_printf);
	ft_inifunptrb(funptrb);
	v_printf->flags |= BIN;
	while (++i < 5)
		if (funptrb[i].conv & v_printf->conv)
		{
			funptrb[i].f(v_printf);
			return;
		}
	if (i == 5)
		ft_putstr("not supported\n");
}
