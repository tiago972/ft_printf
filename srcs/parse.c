/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:46:14 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/13 15:08:47 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	ft_parse_opt(t_printf *v_printf)
{
	while ((v_printf->tmp = ft_strlen_c("#0- +", *(v_printf->str))) > -1
			&& v_printf->str++)
		v_printf->flags |= (1 << v_printf->tmp);
	if (v_printf->flags & ZERO && v_printf->flags & MINUS)
		v_printf->flags &= ~ZERO; 
	if (v_printf->flags & MINUS && v_printf->flags & SPACE)
		v_printf->flags &= ~SPACE;
	ft_parse_width(v_printf);
	ft_parse_precision(v_printf);
	ft_parse_arg_size(v_printf);
	ft_parse_conv(v_printf);
}

void	ft_parse_precision(t_printf *v_printf)
{
	if (*(v_printf->str) == '.' && v_printf->str++)
	{
		/*if (v_printf->str == '*' && v_printf->str++)
			//ft_do_something about it*/
		v_printf->flags |= DOT;
		v_printf->prec = ft_atoi(v_printf->str);
	}
	v_printf->str += ft_power_i(v_printf->prec, 10);

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
	v_printf->str += ft_power_i(v_printf->width, 10);
}

void	ft_parse_arg_size(t_printf *v_printf)
{
	if (*(v_printf->str) == 'l')
	{
		v_printf->flags |= (v_printf->str[1] == 'l' 
				&& v_printf->str++) ? LL : L;
		(v_printf->flags & LL) ? v_printf->str++ : v_printf->str;
	}
	else if (*(v_printf->str) == 'h')
	{
		v_printf->flags |= (v_printf->str[1] == 'h' 
				&& v_printf->str++) ? HH : H;
		(v_printf->flags & HH) ? v_printf->str++ : v_printf->str;
	}
}

void	ft_parse_conv(t_printf *v_printf)
{
	if (*(v_printf->str) == 's' && v_printf->str++)
		v_printf->conv_type |= S;
	else if ((*(v_printf->str) == 'd' || (*(v_printf->str) == 'i'))
			&& v_printf->str++)
			v_printf->conv_type |= D;
	else if (*(v_printf->str) == 'u' && v_printf->str++)
		v_printf->conv_type |= U;
	else if (*(v_printf->str) == 'x' && v_printf->str++)
		v_printf->conv_type |= X;
	else if (*(v_printf->str) == 'X' && v_printf->str++)
		v_printf->conv_type |= XX;
	else if (*(v_printf->str) == 'c' && v_printf->str++)
		v_printf->conv_type |= C;
	else if (*(v_printf->str) == 'p' && v_printf->str++)
		v_printf->conv_type |= P;
	else if (*(v_printf->str) == 'f' && v_printf->str++)
		v_printf->conv_type |= F;
	else if (*(v_printf->str) == 'o' && v_printf->str++)
		v_printf->conv_type |= O;
	ft_gen_pad(v_printf);
}
