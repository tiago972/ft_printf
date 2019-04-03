/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:10:47 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/03 17:25:31 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flush(t_printf *v_printf)
{
	ft_write(v_printf);
	ft_bzero(&(v_printf->buff), BUFF_SIZE);
	v_printf->ret_tot += v_printf->ret_progress;
	v_printf->ret_progress = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_printf	v_printf;
	char		*cpy;

	cpy = (char *)str;
	va_start(ap, str);
	ft_memset(&v_printf, 0, sizeof(t_printf));
	while (*cpy)
	{
		if (v_printf.ret_progress == BUFF_SIZE)
			ft_flush(&v_printf);
		if (*cpy != '%')
		{
			v_printf.buff[(v_printf.ret_progress)++] = *cpy++;
			v_printf.buff[v_printf.ret_progress] = '\0';
		}
		else if (*cpy == '%')
			ft_dispatch(&v_printf, &ap, &cpy);
		else
			cpy++;
	}
	v_printf.ret_tot += v_printf.ret_progress;
	ft_write(&v_printf);
	va_end(ap);
	return (v_printf.ret_tot);
}
