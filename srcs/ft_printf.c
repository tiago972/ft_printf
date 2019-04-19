/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:00:09 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 16:55:56 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static void		ft_flush(t_printf *v_printf)
{
	write(1, v_printf->buff, v_printf->ret_progress);
	ft_bzero(&(v_printf->buff), BUFF_SIZE);
	v_printf->ret_tot += v_printf->ret_progress;
	v_printf->ret_progress = 0;
}

void			ft_buff(t_printf *v_printf, char *str, int n)
{
	int		tmp;

	if (v_printf->ret_progress == BUFF_SIZE)
		ft_flush(v_printf);
	while (str && n > (BUFF_SIZE - v_printf->ret_progress))
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
}

int				ft_printf(const char *str, ...)
{
	t_printf	v_printf;
	t_funptr	funptr[12];

	ft_memset(&v_printf, 0, sizeof(t_printf));
	ft_inifunptr(funptr);
	va_start(v_printf.ap, str);
	v_printf.str = (char *)str;
	while (*(v_printf.str))
	{
		if (*(v_printf.str) == '%')
		{
			v_printf.str++;
			ft_get_info(&v_printf, funptr);
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
