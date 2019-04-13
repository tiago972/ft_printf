/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:11:31 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/13 16:27:43 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
void	ft_pad_c(t_printf *v_printf)
{
	if (v_printf->width > v_printf->curr_len)
	{
		v_printf->curr_len = v_printf->width - v_printf->curr_len;
		if (v_printf->flags & MINUS)
		{
			ft_buff(v_printf, &(v_printf->var_c), 1);
			ft_fill(v_printf, v_printf->curr_len);
		}
		else
		{
			ft_fill(v_printf, v_printf->curr_len);
			ft_buff(v_printf, &(v_printf->var_c), 1);
		}
	}
	else
		ft_buff(v_printf, &(v_printf->var_c), 1);
}
*/
void	ft_pad_str(t_printf *v_printf)
{
	if (v_printf->conv & S)
		v_printf->curr_len = ft_strlen(v_printf->var_str) - v_printf->prec;
	if (v_printf->width > v_printf->curr_len)
	{
		v_printf->curr_len = v_printf->width - v_printf->curr_len;
		if (v_printf->flags & MINUS)
		{
			ft_buff(v_printf, v_printf->var_str, v_printf->prec);
			ft_fill(v_printf, v_printf->curr_len);
		}
		else
		{
			ft_fill(v_printf, v_printf->curr_len);
			ft_buff(v_printf, v_printf->var_str, v_printf->prec);
		}
	}
	else
		ft_buff(v_printf, v_printf->var_str, v_printf->prec);
}

void	ft_pad_i(t_printf *v_printf, int b_size, char *base)
{
	if (v_printf->flags & PLUS)
		v_printf->var_i < 0 ? ft_buff(v_printf, "-", 1)
			: ft_buff(v_printf, "+", 1);
	if (v_printf->prec > v_printf->curr_len)
	{
		v_printf->flags |= ZERO;
		ft_fill(v_printf, v_printf->prec - v_printf->curr_len);
	}
	if (v_printf->width > v_printf->curr_len)
	{
		v_printf->curr_len = v_printf->width - v_printf->curr_len;
		if (v_printf->flags & MINUS)
		{
			ft_pf_putnbr_i(v_printf, v_printf->var_i, b_size, base);
			ft_fill(v_printf, v_printf->curr_len);
		}
		else
		{
			ft_fill(v_printf, v_printf->curr_len);
			ft_pf_putnbr_i(v_printf, v_printf->var_i, b_size, base);
		}
	}
	else
		ft_pf_putnbr_i(v_printf, v_printf->var_i, b_size, base);
}

void	ft_pad_u(t_printf *v_printf, int b_size, char *base)
{
	uintmax_t power;

	power = ft_power_u(v_printf->var_i, b_size);
	power = v_printf->var_i < 0 ? power++ : power;
	if ((uintmax_t)v_printf->prec > power)
	{
		v_printf->flags |= ZERO;
		ft_fill(v_printf, v_printf->prec - power);
	}
	if ((uintmax_t)(v_printf->width) > power)
	{
		v_printf->curr_len = v_printf->width - power;
		if (v_printf->flags & MINUS || v_printf->flags & ZERO)
		{
			ft_pf_putnbr_u(v_printf, v_printf->var_u, b_size, base);
			ft_fill(v_printf, v_printf->curr_len);
		}
		else
		{
			ft_fill(v_printf, v_printf->curr_len);
			ft_pf_putnbr_u(v_printf, v_printf->var_u, b_size, base);
		}
	}
	else
		ft_pf_putnbr_u(v_printf, v_printf->var_u, b_size, base);
}
