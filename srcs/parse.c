/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:51:03 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 16:59:21 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_printf.h"

void	ft_get_size(t_printf *v_printf)
{
	if (*(v_printf->str) == 'l' && v_printf->str++)
		v_printf->flags |= (v_printf->str[0] == 'l'
				&& v_printf->str++) ? LL : L;
	else if (*(v_printf->str) == 'h' && v_printf->str++)
		v_printf->flags |= (v_printf->str[0] == 'h'
				&& v_printf->str++) ? HH : H;
}

void	ft_get_precision(t_printf *v_printf)
{
	int		tmp;

	tmp = ft_strlen_c("csdiouxXpjz%", *(v_printf)->str);
	if (tmp != -1)
		v_printf->conv |= (1 << tmp);
	v_printf->str++;
	if (v_printf->flags & ZERO && v_printf->flags & MINUS)
		v_printf->flags &= ~ZERO;
	if (v_printf->flags & PLUS && v_printf->flags & SP)
		v_printf->flags &= ~SP;
}

void	ft_dispatch(t_printf *v_printf, t_funptr funptr[12])
{
	int		i;

	i = -1;
	ft_get_size(v_printf);
	ft_get_precision(v_printf);
	while (++i < 12)
	{
		if (funptr[i].conv & v_printf->conv)
			funptr[i].f(v_printf);
	}
}

void	ft_get_info(t_printf *v_printf, t_funptr funptr[10])
{
	while ((v_printf->tmp = ft_strlen_c("-+0 #", *(v_printf->str))) > -1
			&& v_printf->str++)
		v_printf->flags |= (1 << v_printf->tmp);
	if (*(v_printf->str) == '*' && v_printf->str++)
		v_printf->width = va_arg(v_printf->ap, int);
	else
	{
		v_printf->width = ft_atoi(v_printf->str);
		if (v_printf->width > 0 || *(v_printf->str) == '0')
			v_printf->str += (int)ft_power(v_printf->width, 10);
	}
	if (*(v_printf->str) == '.' && v_printf->str++ && (v_printf->flags |= DOT))
	{
		if (v_printf->flags & ZERO)
			v_printf->flags &= ~ZERO;
		if (*(v_printf->str) == '*' && v_printf->str++)
			v_printf->prec = va_arg(v_printf->ap, int);
		else
			if (*(v_printf->str) >= '0' && *(v_printf->str) <= '9')
			{
				v_printf->prec = ft_atoi(v_printf->str);
				v_printf->str += (int)ft_power(v_printf->prec, 10);
			}
	}
	ft_dispatch(v_printf, funptr);
}
