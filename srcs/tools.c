/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:54:54 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/05 21:18:46 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_write(t_printf *v_printf)
{
	write(1, v_printf->buff, v_printf->ret_progress);
}

void	ft_flush(t_printf *v_printf)
{
	ft_write(v_printf);
	ft_bzero(&(v_printf->buff), BUFF_SIZE);
	v_printf->ret_tot += v_printf->ret_progress;
	v_printf->ret_progress = 0;
}
