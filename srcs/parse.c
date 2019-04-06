/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:46:14 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/06 18:29:07 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	ft_parse_opt(t_printf *v_printf)
{
	while ((v_printf->tmp = ft_strlen_c("#0- +", *(v_printf->str))) > -1
			&& v_printf->str++)
		v_printf->flags |= (1 << v_printf->tmp);
	ft_parse_width(v_printf);
	ft_parse_conv(v_printf);
}

void	ft_parse_width(t_printf *v_printf)
{
	if ((*(v_printf->str) >= '1' && *(v_printf->str) <= '9')
			|| *(v_printf->str) == '-')
	{
		v_printf->width = ft_atoi(v_printf->str);
		if (v_printf->width < 0)
		{
			v_printf->width = -v_printf->width;
			v_printf->str++;
		}
	}
	v_printf->str += ft_power(v_printf->width, 10);
}

void	ft_parse_conv(t_printf *v_printf)
{
	if (*(v_printf->str) == 's' && v_printf->str++)
	{
		v_printf->var_c = va_arg(v_printf->ap, char *);
		ft_pad_str(v_printf);
	}
	else if ((*(v_printf->str) == 'd' || (*(v_printf->str) == 'i'))
			&& v_printf->str++)
	{
		v_printf->var_i = ft_get_arg_i(v_printf);
		ft_pad_i(v_printf, 10, "0123456789");
	}
	else if (*(v_printf->str) == 'u' && v_printf->str++)
	{
		v_printf->var_u = ft_get_arg_u(v_printf);
		ft_pad_u(v_printf, 10, "0123456789");
	}
}
