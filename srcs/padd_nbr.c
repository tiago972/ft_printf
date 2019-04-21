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

void	ft_pad_nbr(t_printf *v_printf, uintmax_t uintarg)
{
	while (!(v_printf->flags & ZERO) && !(v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
	if (uintarg > 0 && (v_printf->flags & POUND) && (v_printf->conv & X))
		ft_buff(v_printf, "0x", 2);
	else if (uintarg > 0 && (v_printf->flags & POUND) && (v_printf->conv & XX))
		ft_buff(v_printf, "0X", 2);
	else if (uintarg > 0 && (v_printf->flags & POUND) && (v_printf->conv & O))
		ft_buff(v_printf, "0", 1);
	while ((v_printf->flags & ZERO) && --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
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

