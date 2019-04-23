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
	else if ((v_printf->flags & POUND) && (v_printf->conv & O))
		ft_buff(v_printf, "0", 1);
	while ((v_printf->flags & ZERO) && --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
}

void		ft_fill_nb_i(t_printf *v_printf, intmax_t int_arg, int opt)
{
	uintmax_t	len;
	uintmax_t	power;

	if (!opt)
		power = 20;
	power = ft_power(ft_abs(int_arg), 10);
	power = int_arg < 0 ? power + 1 : power;
	if (v_printf->flags & DOT)
		len = ft_max(power, v_printf->prec);
	else
		len = power;
	if (int_arg != 0)
		v_printf->width -= len;
	v_printf->prec -= power;
	while (!(v_printf->flags & MINUS) && !(v_printf->flags & ZERO)
			&& --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
	if (v_printf->flags & PLUS || v_printf->flags & SP)
		if (int_arg >= 0)
		{
			v_printf->width--;
			v_printf->flags & PLUS ? ft_buff(v_printf, "+", 1)
				: ft_buff(v_printf, " ", 1);
		}
	if (int_arg < 0)
		ft_buff(v_printf, "-", 1);
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
}
