/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:54:54 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/11 20:39:57 by edbaudou         ###   ########.fr       */
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

intmax_t	ft_power_i(intmax_t nb, int b_size)
{
	intmax_t	power;

	power = 0;
	while (nb != b_size)
	{
		nb /= b_size;
		power++;
	}
	return (power);
}

uintmax_t	ft_power_u(uintmax_t nb, unsigned b_size)
{
	uintmax_t	power;

	power = 0;
	while (nb != b_size)
	{
		nb /= b_size;
		power++;
	}
	return (power);
}

int	ft_iterative_power(int nb, int power)
{
	int		count;
	int		res;

	res = 1;
	if (power == 0)
		return (1);
	if (nb == 0 || power < 0)
		return (0);
	count = 0;
	while (count < power)
	{
		res *= nb;
		count++;
	}
	return (res);
}

void	ft_fill(t_printf *v_printf)
{
	if (v_printf->flags & ZERO)
		while (v_printf->curr_len--)
			ft_buff(v_printf, "0", 1);
	else
		while (v_printf->curr_len--)
			ft_buff(v_printf, " ", 1);
}
