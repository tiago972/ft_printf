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

void		ft_fill_nb_i(t_printf *v_printf, intmax_t int_arg, int opt)
{
	uintmax_t	len;

	if (!opt)
		v_printf->power = 20;
	v_printf->power = ft_log(ft_abs(int_arg), 10);
	if (v_printf->flags & DOT)
		len = ft_max(v_printf->power, v_printf->prec);
	else
		len = v_printf->power;
	if (int_arg != 0 || v_printf->prec > 0)
		v_printf->width -= len;
	v_printf->prec -= v_printf->power;
	if (int_arg < 0)
		v_printf->width--;
	if (!(v_printf->flags & MINUS) && !(v_printf->flags & ZERO))
	{
		if ((v_printf->flags & PLUS || v_printf->flags & SP) && int_arg >= 0)
			v_printf->width--;
		while (--(v_printf->width) >= 0)
			ft_buff(v_printf, " ", 1);
	}
	if ((v_printf->flags & PLUS || v_printf->flags & SP) && int_arg >= 0 && v_printf->width--)
			v_printf->flags & PLUS ? ft_buff(v_printf, "+", 1)
				: ft_buff(v_printf, " ", 1);
}
