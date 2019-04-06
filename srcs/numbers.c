/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:05:15 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/06 18:26:51 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

uintmax_t	ft_get_arg_u(t_printf *v_printf)
{
	if (v_printf->flags & H)
		return ((unsigned short)va_arg(v_printf->ap, unsigned int));
	else if (v_printf->flags & HH)
		return ((unsigned char)va_arg(v_printf->ap,  unsigned int));
	else if (v_printf->flags & L)
		return (va_arg(v_printf->ap, unsigned long int));
	else if (v_printf->flags & LL)
		return (va_arg(v_printf->ap, unsigned long long int));
	else
		return (va_arg(v_printf->ap, unsigned int));
}

void	ft_pf_putnbr_i(t_printf *v_printf, intmax_t nb, int b_size,
		char *base)
{
	if (v_printf->ret_progress == BUFF_SIZE)
		ft_flush(v_printf);
	if (v_printf->var_i < 0)
	{
		ft_buff(v_printf, "-", 1);
		nb = -nb;
	}
	if (nb >= b_size)
		ft_pf_putnbr_i(v_printf, nb / b_size, b_size, base);
	ft_buff(v_printf, &base[nb % b_size], 1);
}

void	ft_pf_putnbr_u(t_printf *v_printf, uintmax_t nb, int b_size,
		char *base)
{
	if (v_printf->ret_progress == BUFF_SIZE)
		ft_flush(v_printf);
	if (nb >= (uintmax_t)b_size)
		ft_pf_putnbr_u(v_printf, nb / b_size, b_size, base);
	ft_buff(v_printf, &base[nb % b_size], 1);
}
