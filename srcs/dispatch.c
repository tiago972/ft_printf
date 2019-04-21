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

void			ft_inifunptr(t_funptr funptr[12])
{
	funptr[0].conv |= C;
	funptr[0].f = &ft_pad_c;
	funptr[1].conv |= S;
	funptr[1].f = &ft_pad_s;
	funptr[2].conv |= D;
	funptr[2].f = &ft_pad_i;
	funptr[3].conv |= I;
	funptr[3].f = &ft_pad_i;
	funptr[4].conv |= O;
	funptr[4].f = &ft_pad_u;
	funptr[5].conv |= U;
	funptr[5].f = &ft_pad_u;
	funptr[6].conv |= X;
	funptr[6].f = &ft_pad_u;
	funptr[7].conv |= XX;
	funptr[7].f = &ft_pad_u;
	funptr[8].conv |= P;
	funptr[8].f = &ft_pad_p;
	funptr[9].conv |= J;
	funptr[9].f = &ft_dispatch_j;
	funptr[10].conv |= Z;
	funptr[10].f = &ft_pad_u;
	funptr[11].conv |= POURCENT;
	funptr[11].f = &ft_pad_escape;

	/*funptr[4].conv = 'f';
	  funptr[4].f = &pad_f;
	  funptr[10].conv = 'z';
	  funptr[10].f = &ft_pad_i;*/
}

uintmax_t	ft_power_dispatch(t_printf *v_printf, uintmax_t uintarg)
{
	if (v_printf->conv & X || v_printf->conv & XX)
		return (ft_power(uintarg, 16));
	else if (v_printf->conv & U || v_printf->conv & Z)
		return (ft_power(uintarg, 10));
	else if (v_printf->conv & 0)
		return (ft_power(uintarg, 8));
	return (0);
}

void	ft_dispatch_j(t_printf *v_printf)
{
	if (v_printf->conv & U && v_printf->str++)
		ft_pad_u(v_printf);
	else if (v_printf->conv & X && v_printf->str++)
		ft_pad_u(v_printf);
	else
		ft_pad_i(v_printf);
}