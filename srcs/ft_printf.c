/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:00:09 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/05 21:18:35 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
int	g_tour = 0;

void	ft_buff(t_printf *v_printf, char *str, int n)
{
	int		tmp;
	
	if (v_printf->ret_progress == BUFF_SIZE)
		ft_flush(v_printf);
	while (n > (BUFF_SIZE - v_printf->ret_progress))
	{	
		tmp = BUFF_SIZE - v_printf->ret_progress;
		ft_strncat(v_printf->buff, str, tmp);
		str += tmp;
		n -= tmp;
		v_printf->ret_progress += tmp;
		ft_flush(v_printf);
	}
	ft_strncat(v_printf->buff, str, n);
	v_printf->ret_progress += n;
	g_tour++;
}

int		ft_printf(const char *str, ...)
{
	t_printf	v_printf;

	ft_memset(&v_printf, 0, sizeof(t_printf));
	va_start(v_printf.ap, str);
	v_printf.str = (char *)str;
	while (*(v_printf.str))
	{
		if (*(v_printf.str) == '%')
		{
			v_printf.str++;
			ft_parse_opt(&v_printf);
		}
		else
		{
			ft_buff(&v_printf, v_printf.str, 1);
			v_printf.str++;
		}
	}
	if (v_printf.ret_progress > 0)
		ft_flush(&v_printf);
	va_end(v_printf.ap);
	return (v_printf.ret_tot);
}
