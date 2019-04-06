/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:11:31 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/05 21:19:31 by edbaudou         ###   ########.fr       */
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
void	ft_pad(t_printf *v_printf)
{

	v_printf->curr_len = ft_strlen(v_printf->var_c);
	if (v_printf->width > v_printf->curr_len)
	{
		v_printf->curr_len = v_printf->width - v_printf->curr_len;
		if (v_printf->flags &= MINUS)
		{
			printf("TRuE\n");
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
