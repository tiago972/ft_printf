/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:28:40 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/18 17:51:32 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_dispatch_j(t_printf *v_printf)
{
	v_printf->flags |= J;
	if (*(v_printf->str) == 'u' && v_printf->str++)
		ft_pad_u(v_printf);
	else if (*(v_printf->str) == 'x' && v_printf->str++)
		ft_pad_x(v_printf);
	else
		ft_pad_i(v_printf);
}
