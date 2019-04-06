/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:11:31 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/06 18:29:07 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*
void	ft_pf_putstr(t_printf *v_printf)
{
	char	*str;

	str = va_arg(v_printf->ap, char *);
	ft_buff(v_printf, str, ft_strlen(str));
}
*/
void	ft_pad_str(t_printf *v_printf)
{
	v_printf->curr_len = ft_strlen(v_printf->var_c);
	if (v_printf->width > v_printf->curr_len)
	{
		v_printf->curr_len = v_printf->width - v_printf->curr_len;
		if (v_printf->flags & MINUS)
		{
			ft_buff(v_printf, v_printf->var_c, ft_strlen(v_printf->var_c));
			while (v_printf->curr_len--)
				ft_buff(v_printf, " ", 1);
		}
		else
		{
			while (v_printf->curr_len--)
				ft_buff(v_printf, " ", 1);
			ft_buff(v_printf, v_printf->var_c, ft_strlen(v_printf->var_c));
		}
	}
	else
		ft_buff(v_printf, v_printf->var_c, v_printf->curr_len);
}

void	ft_pad_i(t_printf *v_printf, int b_size, char *base)
{
	intmax_t	power;

	power = ft_power(v_printf->var_i, b_size);
	power = v_printf->var_i < 0 ? power++ : power;
	if (v_printf->width > power)
	{
		v_printf->curr_len = v_printf->width - power;
		if (v_printf->flags & MINUS)
		{
			ft_pf_putnbr_i(v_printf, v_printf->var_i, b_size, base);
			while (v_printf->curr_len--)
				ft_buff(v_printf, " ", 1);
		}
		else
		{
			while (v_printf->curr_len--)
				ft_buff(v_printf, " ", 1);
			ft_pf_putnbr_i(v_printf, v_printf->var_i, b_size, base);
		}
	}
	else
		ft_pf_putnbr_i(v_printf, v_printf->var_i, b_size, base);
}

void	ft_pad_u(t_printf *v_printf, int b_size, char *base)
{
	uintmax_t	power;

	power = ft_power(v_printf->var_i, b_size);
	power = v_printf->var_i < 0 ? power++ : power;
	if ((uintmax_t)(v_printf->width) > power)
	{
		v_printf->curr_len = v_printf->width - power;
		if (v_printf->flags & MINUS)
		{
			ft_pf_putnbr_u(v_printf, v_printf->var_u, b_size, base);
			while (v_printf->curr_len--)
				ft_buff(v_printf, " ", 1);
		}
		else
		{
			while (v_printf->curr_len--)
				ft_buff(v_printf, " ", 1);
			ft_pf_putnbr_u(v_printf, v_printf->var_u, b_size, base);
		}
	}
	else
		ft_pf_putnbr_u(v_printf, v_printf->var_u, b_size, base);
}
