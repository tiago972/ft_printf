/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:14:29 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/17 19:54:53 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

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
	uintmax_t	len;
	uintmax_t	power;

	int_arg = ft_get_arg_i(v_printf);
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
	while ((v_printf->flags & ZERO) && --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	while (!(v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
	v_printf->prec -= power;
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
	ft_putnbr_pf(v_printf, int_arg);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}
/*
void	ft_pad_p()
{
}
void	ft_pad_u()
{
}*/
