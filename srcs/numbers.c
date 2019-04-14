/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:13:52 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/14 20:54:44 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

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

void	ft_putnbr_pf(t_printf *v_printf, intmax_t n)
{
    int            order;
	char			tmp;
	intmax_t		nb2;

	if (n < 0)
	{
        ft_buff(v_printf, "-", 1);
		n = -n;
		if (n == LLONG_MIN)
		{
			ft_buff(v_printf, "9", 1);
			n = 223372036854775808;
		}
	}
    nb2 = n;
    order = 1;
    while ((nb2 >= 10 || nb2 <= -10) && (nb2 /= 10))
        order = order * 10;
    while (order > 0)
    {
        tmp = '0' + n / order;
		ft_buff(v_printf, &tmp, 1);
        n = n % order;
        order = order / 10;
    }
}
