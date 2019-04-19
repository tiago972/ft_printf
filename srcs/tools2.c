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

void	ft_dispatch_j(t_printf *v_printf)
{
	if (*(v_printf->str) == 'u' && v_printf->str++)
		ft_pad_u(v_printf);
	else
		ft_pad_i(v_printf);
}
