/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:28:40 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 17:51:32 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_inifunptr(t_funptr funptr[10])
{
	funptr[0].conv = 'c';
	funptr[0].f = &ft_pad_c;
	funptr[1].conv = 's';
	funptr[1].f = &ft_pad_s;
	funptr[2].conv = 'd';
	funptr[2].f = &ft_pad_i;
	funptr[3].conv = 'i';
	funptr[3].f = &ft_pad_i;
	funptr[4].conv = 'x';
	funptr[4].f = &ft_pad_x;
	funptr[5].conv = 'X';
	funptr[5].f = &ft_pad_X;
	funptr[6].conv = 'o';
	funptr[6].f = &ft_pad_o;
	funptr[7].conv = 'j';
	funptr[7].f = &ft_dispatch_j;
	funptr[8].conv = 'u';
	funptr[8].f = &ft_pad_u;
	funptr[9].conv = 'p';
	funptr[9].f = &ft_pad_p;
	funptr[10].conv = '%';
	funptr[10].f = &ft_pad_escape;
	/*funptr[4].conv = 'f';
	  funptr[4].f = &pad_f;
	  funptr[10].conv = 'z';
	  funptr[10].f = &ft_pad_i;*/
}

uintmax_t		ft_power(uintmax_t nb, uintmax_t base)
{
	uintmax_t	power;

	power = 0;
	while (nb >= base)
	{
		nb /= base;
		power++;
	}
	power++;
	return (power);
}

int				ft_min(int a, int b)
{
	return (a > b ? b : a);
}

int				ft_max(int a, int b)
{
	return (a > b ? a : b);
}

uintmax_t		ft_abs(intmax_t a)
{
	return (a < 0 ? -a : a);
}
