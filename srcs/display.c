/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:11:31 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/05 20:37:01 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_pf_putstr(t_printf *v_printf)
{
	char	*str;

	str = va_arg(v_printf->ap, char *);
	ft_buff(v_printf, str, ft_strlen(str));
}

void	ft_pad(t_printf *v_printf)
{
	v_printf->var_char = va_arg(v_printf->ap, char *);
		v_printf->curr_len = ft_strlen(v_printf->var_char);
		if (v_printf->width > v_printf->curr_len)
		{
			if (v_printf->flags &= MINUS)
			else
		}
}
