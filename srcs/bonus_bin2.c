/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bin2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:08:48 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/05 20:08:45 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned	ft_size_i_b(t_printf *v_printf)
{
	if (v_printf->flags & LL)
		return (sizeof(long long));
	else if (v_printf->flags & L)
		return (sizeof(long));
	else if (v_printf->flags & HH)
		return (sizeof(char));
	else if (v_printf->flags & H)
		return (sizeof(short));
	else
		return (sizeof(int));
}
