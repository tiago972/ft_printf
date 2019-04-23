/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:14:29 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 17:56:01 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include <limits.h>

void	ft_pad_c(t_printf *v_printf)
{
	char	l;
	int		len;

	if (v_printf->conv & POURCENT)
		l = '%';
	else
		l = (char)va_arg(v_printf->ap, int);
	len = 1;
	v_printf->width -= len;
	if (!(v_printf->flags & MINUS))
		while (--(v_printf->width) >= 0)
			ft_buff(v_printf, " ", 1);
	ft_buff(v_printf, &l, len);
	if (v_printf->flags & MINUS)
		while (--(v_printf->width) >= 0)
			ft_buff(v_printf, " ", 1);
}

void	ft_pad_s(t_printf *v_printf)
{
	char	*str_arg;
	int		len;

	str_arg = (char *)va_arg(v_printf->ap, char *);
	if (!str_arg)
		str_arg = "(null)";
	if (v_printf->flags & DOT)
	{
		if (v_printf->prec == -1)
			v_printf->prec = ft_strlen(str_arg);
		len = ft_min(v_printf->prec, ft_strlen(str_arg));
	}
	else
		len = ft_strlen(str_arg);
	v_printf->width -= len;
	if (!(v_printf->flags & MINUS))
		while (--(v_printf->width) >= 0)
			ft_buff(v_printf, " ", 1);
	ft_buff(v_printf, str_arg, len);
	if (v_printf->flags & MINUS)
		while (--(v_printf->width) >= 0)
			ft_buff(v_printf, " ", 1);
}

void	ft_pad_i(t_printf *v_printf)
{
	intmax_t	int_arg;

	int_arg = ft_get_arg_i(v_printf);
	if ((v_printf->flags & DOT) && v_printf->prec == -1)
		v_printf->prec = 1;
	if (int_arg == LLONG_MIN)
	{
		ft_llong_min(v_printf, int_arg);
		return ;
	}
	ft_fill_nb_i(v_printf, int_arg, 1);
	while ((v_printf->flags & ZERO) && --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	if (v_printf->prec <= -1 && int_arg == 0 && (v_printf->flags & DOT))
		return ;
	ft_putnbr_pf(v_printf, int_arg);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}

void	ft_pad_u(t_printf *v_printf)
{
	uintmax_t	uintarg;
	uintmax_t	power;
	uintmax_t	len;

	uintarg = ft_get_arg_u(v_printf);
	power = ft_power_dispatch(v_printf, uintarg);
	if ((v_printf->flags & DOT) && v_printf->prec == -1)
		v_printf->prec = 1;
	if (v_printf->flags & POUND && uintarg > 0)
		v_printf->width = v_printf->conv & O ? v_printf->width - 1
			: v_printf->width - 2;
	len = v_printf->flags & DOT ? ft_max(power, v_printf->prec) : power;
	if (uintarg != 0)
		v_printf->width -= len;
	v_printf->prec -= power;
	ft_pad_nbr(v_printf, uintarg);
	if (v_printf->prec <= -1 && uintarg == 0 && (v_printf->flags & DOT))
		return ;
	ft_print_u(v_printf, uintarg, power);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}

void	ft_pad_p(t_printf *v_printf)
{
	uintmax_t	uintarg;
	uintmax_t	len;

	uintarg = (uintmax_t)va_arg(v_printf->ap, void *);
	len = ft_power(uintarg, 16);
	v_printf->width -= 2;	
	v_printf->width -= len;
	while (!(v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
	ft_buff(v_printf, "0x", 2);	
	ft_putnbr_pf_u(v_printf, uintarg, "0123456789abcdef", 16, len);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}
