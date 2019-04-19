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
	char l;

	l = (char)va_arg(v_printf->ap, int);
	if (v_printf->flags & MINUS)
		while (v_printf->width--)
			ft_buff(v_printf, " ", 1);
	ft_buff(v_printf, &l, 1);
	if (!(v_printf->flags & MINUS))
		while (v_printf->width--)
			ft_buff(v_printf, " ", 1);
}

void	ft_pad_escape(t_printf *v_printf)
{
	char l;

	l = '%';
	if (v_printf->flags & MINUS)
		while (v_printf->width--)
			ft_buff(v_printf, " ", 1);
	ft_buff(v_printf, &l, 1);
	if (!(v_printf->flags & MINUS))
		while (v_printf->width--)
			ft_buff(v_printf, " ", 1);
}

void	ft_pad_s(t_printf *v_printf)
{
	char	*str_arg;
	int		len;

	str_arg = (char *)va_arg(v_printf->ap, char *);
	if (v_printf->flags & DOT)
		len = ft_min(v_printf->prec, ft_strlen(str_arg));
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
	if (int_arg == LLONG_MIN)
	{
		ft_llong_min(v_printf, int_arg);
		return ;
	}
	ft_fill_nb_i(v_printf, int_arg, 1);
	while ((v_printf->flags & ZERO) && --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	while (!(v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
	ft_putnbr_pf(v_printf, int_arg);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}

void	ft_pad_x(t_printf *v_printf)
{
	uintmax_t	uintarg;
	uintmax_t	power;
	uintmax_t	len;

	uintarg = ft_get_arg_u(v_printf);
	power = ft_power(uintarg, 16);
	if (v_printf->flags & POUND)
		v_printf->width -= 2;	
	if (v_printf->flags & DOT)
		len = ft_max(power, v_printf->prec);
	else
		len = power;
	v_printf->width -= len;
	v_printf->prec -= power;
	while (!(v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
	if (v_printf->flags & POUND)
		ft_buff(v_printf, "0x", 2);	
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
	ft_putnbr_pf_u(v_printf, uintarg, "0123456789abcdef", 16);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}
