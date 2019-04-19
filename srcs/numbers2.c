/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:36:00 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 18:16:27 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putnbr_pf_u(t_printf *v_printf, uintmax_t nb, char *base,
			uintmax_t size_b)
{
	if (nb >= size_b)
		ft_putnbr_pf_u(v_printf, (nb / size_b), base, size_b);
	ft_buff(v_printf, &base[nb % size_b], 1);
}

void	ft_pad_X(t_printf *v_printf)
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
	ft_putnbr_pf_u(v_printf, uintarg, "0123456789ABCDEF", 16);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}

void	ft_pad_o(t_printf *v_printf)
{
	uintmax_t	uintarg;
	uintmax_t	power;
	uintmax_t	len;

	uintarg = ft_get_arg_u(v_printf);
	power = ft_power(uintarg, 8);
	if (v_printf->flags & POUND)
		v_printf->width -= 1;	
	if (v_printf->flags & DOT)
		len = ft_max(power, v_printf->prec);
	else
		len = power;
	v_printf->width -= len;
	v_printf->prec -= power;
	while (!(v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
	if (v_printf->flags & POUND)
		ft_buff(v_printf, "0", 2);	
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
	ft_putnbr_pf_u(v_printf, uintarg, "01234567", 8);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}

void	ft_pad_u(t_printf *v_printf)
{
	uintmax_t	uintarg;
	uintmax_t	power;
	uintmax_t	len;

	uintarg = ft_get_arg_u(v_printf);
	power = ft_power(uintarg, 10);
	if (v_printf->flags & DOT)
		len = ft_max(power, v_printf->prec);
	else
		len = power;
	v_printf->width -= len;
	v_printf->prec -= power;
	while (!(v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
	ft_putnbr_pf_u(v_printf, uintarg, "0123456789", 10);
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
	ft_putnbr_pf_u(v_printf, uintarg, "0123456789abcdef", 16);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}
