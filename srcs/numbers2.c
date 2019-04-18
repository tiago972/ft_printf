/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:36:00 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 18:16:27 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putnbr_pf_u(t_printf *v_printf, uintmax_t nb, char *base,
			uintmax_t power, uintmax_t size_b)
{
	char		tmp;
	uintmax_t	order;

	order = 1;
	while (power > 0)
	{
		order *= order;
		power--;
	}
	while (order > 0)
	{
		tmp = base[nb / size_b];
		ft_buff(v_printf, &tmp, 1);
		nb = nb % order;
		order /= size_b;
	}
}
