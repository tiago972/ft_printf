/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:11:31 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/07 17:49:07 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_pad_p(t_printf *v_printf)
{
	v_prinf->var_p = (uintptr_t)va_arg(v_printf->ap, void *);
}

void	ft_pad_c(t_printf *v_printf)
{
	v_printf->var_c = (char)va_arg(v_printf->ap, int);
	v_printf->curr_len = 1; 
	if (v_printf->width > v_printf->curr_len)
	{
		v_printf->curr_len = v_printf->width - v_printf->curr_len;
		if (v_printf->flags & MINUS)
		{
			ft_buff(v_printf, &(v_printf->var_c), 1);
			ft_fill(v_printf);
		}
		else
		{
			ft_fill(v_printf);
			ft_buff(v_printf, &(v_printf->var_c), 1);
		}
	}
	else
		ft_buff(v_printf, &(v_printf->var_c), 1);
}

void	ft_pad_str(t_printf *v_printf)
{
	v_printf->var_str = va_arg(v_printf->ap, char *);
	v_printf->curr_len = ft_strlen(v_printf->var_str);
	if (v_printf->width > v_printf->curr_len)
	{
		v_printf->curr_len = v_printf->width - v_printf->curr_len;
		if (v_printf->flags & MINUS)
		{
			ft_buff(v_printf, v_printf->var_str, ft_strlen(v_printf->var_str));
			ft_fill(v_printf);
		}
		else
		{
			ft_fill(v_printf);
			ft_buff(v_printf, v_printf->var_str, ft_strlen(v_printf->var_str));
		}
	}
	else
		ft_buff(v_printf, v_printf->var_str, v_printf->curr_len);
}

void	ft_pad_i(t_printf *v_printf, int b_size, char *base)
{
	intmax_t	power;

	v_printf->var_i = ft_get_arg_i(v_printf);
	power = ft_power(v_printf->var_i, b_size);
	power = v_printf->var_i < 0 ? power++ : power;
	if (v_printf->width > power)
	{
		v_printf->curr_len = v_printf->width - power;
		if (v_printf->flags & MINUS)
		{
			ft_pf_putnbr_i(v_printf, v_printf->var_i, b_size, base);
			ft_fill(v_printf);
		}
		else
		{
			ft_fill(v_printf);
			ft_pf_putnbr_i(v_printf, v_printf->var_i, b_size, base);
		}
	}
	else
		ft_pf_putnbr_i(v_printf, v_printf->var_i, b_size, base);
}

void	ft_pad_u(t_printf *v_printf, int b_size, char *base)
{
	uintmax_t	power;

	v_printf->var_u = ft_get_arg_u(v_printf);
	power = ft_power(v_printf->var_i, b_size);
	power = v_printf->var_i < 0 ? power++ : power;
	if ((uintmax_t)(v_printf->width) > power)
	{
		v_printf->curr_len = v_printf->width - power;
		if (v_printf->flags & MINUS || v_printf->flags & ZERO)
		{
			ft_pf_putnbr_u(v_printf, v_printf->var_u, b_size, base);
			ft_fill(v_printf);
		}
		else
		{
			ft_fill(v_printf);
			ft_pf_putnbr_u(v_printf, v_printf->var_u, b_size, base);
		}
	}
	else
		ft_pf_putnbr_u(v_printf, v_printf->var_u, b_size, base);
}
