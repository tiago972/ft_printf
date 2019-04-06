/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:11:31 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/06 15:48:16 by edbaudou         ###   ########.fr       */
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
		//printf("flags %d, MINUS %d\n", v_printf->flags, MINUS);
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
