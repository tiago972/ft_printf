/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:13:52 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 17:34:13 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

intmax_t	ft_get_arg_i(t_printf *v_printf)
{
	if (v_printf->flags & H)
		return ((short)va_arg(v_printf->ap, int));
	else if (v_printf->flags & HH)
		return ((char)va_arg(v_printf->ap, int));
	else if (v_printf->flags & L)
		return (va_arg(v_printf->ap, long int));
	else if (v_printf->flags & LL)
		return (va_arg(v_printf->ap, long long int));
	else if (v_printf->flags & J)
		return (va_arg(v_printf->ap, intmax_t));
	else
		return ((intmax_t)va_arg(v_printf->ap, int));
}

uintmax_t	ft_get_arg_u(t_printf *v_printf)
{
	if (v_printf->flags & H)
		return ((unsigned short)va_arg(v_printf->ap, unsigned int));
	else if (v_printf->flags & HH)
		return ((unsigned char)va_arg(v_printf->ap,  unsigned int));
	else if (v_printf->flags & L)
		return (va_arg(v_printf->ap, unsigned long int));
	else if (v_printf->flags & LL)
		return (va_arg(v_printf->ap, unsigned long long int));
	else if (v_printf->flags & J)
		return (va_arg(v_printf->ap, uintmax_t));
	else
		return ((uintmax_t)va_arg(v_printf->ap, unsigned int));
}

void		ft_fill_nb_i(t_printf *v_printf, intmax_t int_arg, int opt)
{
	uintmax_t	len;
	uintmax_t	power;

	if (!opt)
		power = 20;
	power = ft_power(ft_abs(int_arg), 10);
	power = int_arg < 0 ? power++ : power;
	if (v_printf->flags & PLUS || v_printf->flags & SP)
		if (int_arg >= 0)
		{
			v_printf->width--;
			v_printf->flags & PLUS ? ft_buff(v_printf, "+", 1)
				: ft_buff(v_printf, " ", 1);
		}
	if (v_printf->flags & DOT)
		len = ft_max(power, v_printf->prec);
	else
		len = power;
	v_printf->width -= len;
	v_printf->prec -= power;
}

void		ft_llong_min(t_printf *v_printf, intmax_t int_arg)
{
	ft_fill_nb_i(v_printf, int_arg, 0);
	while ((v_printf->flags & ZERO) && --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	while (!(v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
	v_printf->prec -= 20;
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
	ft_buff(v_printf, "-9223372036854775808", 20);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}
