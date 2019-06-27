/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:13:52 by edbaudou          #+#    #+#             */
/*   Updated: 2019/06/27 19:38:42 by edbaudou         ###   ########.fr       */
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
	else if (v_printf->conv & J)
		return (va_arg(v_printf->ap, intmax_t));
	else if (v_printf->conv & Z)
		return ((intmax_t)(va_arg(v_printf->ap, size_t)));
	else
		return ((intmax_t)va_arg(v_printf->ap, int));
}

uintmax_t	ft_get_arg_u(t_printf *v_printf)
{
	if (v_printf-> conv & UU)
		return (va_arg(v_printf->ap, unsigned long int));
	else if (v_printf->flags & H)
		return ((unsigned short)va_arg(v_printf->ap, unsigned int));
	else if (v_printf->flags & HH)
		return ((unsigned char)va_arg(v_printf->ap,  unsigned int));
	else if (v_printf->flags & L)
		return (va_arg(v_printf->ap, unsigned long int));
	else if (v_printf->flags & LL)
		return (va_arg(v_printf->ap, unsigned long long int));
	else if (v_printf->conv & J)
		return (va_arg(v_printf->ap, uintmax_t));
	else if (v_printf->conv & Z)
		return (va_arg(v_printf->ap, size_t));
	else
		return ((uintmax_t)va_arg(v_printf->ap, unsigned int));
}

void		ft_llong_min(t_printf *v_printf, intmax_t int_arg)
{
	if ((v_printf->flags & DOT) && v_printf->prec == -1)
		v_printf->prec = 1;
	ft_fill_nb_i(v_printf, int_arg, 1);
	ft_buff(v_printf, "-", 1);
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
	while ((v_printf->flags & ZERO) && --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	ft_buff(v_printf, "9223372036854775808", 19);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}

void	ft_print_u(t_printf *v_printf, uintmax_t uintarg, uintmax_t power)
{
	if (v_printf->conv & X)
		ft_putnbr_pf_u(v_printf, uintarg, "0123456789abcdef", 16, power);
	else if (v_printf->conv & XX)
		ft_putnbr_pf_u(v_printf, uintarg, "0123456789ABCDEF", 16, power);
	else if (v_printf->conv & O)
		ft_putnbr_pf_u(v_printf, uintarg, "01234567", 8, power);
	else if (v_printf->conv & U)
		ft_putnbr_pf_u(v_printf, uintarg, "0123456789", 10, power);
	else if (v_printf->conv & UU)
		ft_putnbr_pf_u(v_printf, uintarg, "0123456789", 10, power);
}

int		ft_particular_octal(t_printf *v_printf, uintmax_t uintarg)
{
	if ((v_printf->conv & O) && (v_printf->flags & DOT)
			&& (v_printf->prec <= -2 || v_printf->prec == 0)
			&& (v_printf->flags & POUND))
	{
		if (uintarg == 0)
			v_printf->width--;
		ft_pad_nbr(v_printf, 0U);
		ft_buff(v_printf, "0", 1);
		return (1);
	}
	return (0);
}
