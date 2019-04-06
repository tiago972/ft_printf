/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:54:54 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/06 15:49:33 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_write(t_printf *v_printf)
{
	write(1, v_printf->buff, v_printf->ret_progress);
}

void		ft_flush(t_printf *v_printf)
{
	ft_write(v_printf);
	ft_bzero(&(v_printf->buff), BUFF_SIZE);
	v_printf->ret_tot += v_printf->ret_progress;
	v_printf->ret_progress = 0;
}

intmax_t	ft_get_arg_i(t_printf *v_printf)
{
	if (v_printf->flags & H)
		return ((short)va_arg(v_printf->ap, int));
	else if (v_printf->flags & HH)
		return ((char)va_arg(v_printf->ap,  int));
	else if (v_printf->flags & L)
		return (va_arg(v_printf->ap, long int));
	else if (v_printf->flags & LL)
		return (va_arg(v_printf->ap, long long int));
	else
		return (va_arg(v_printf->ap, int));
}
