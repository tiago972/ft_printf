/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_f_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:01:54 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/05 13:14:57 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double		ft_iterative_power_f(long double power, long double n)
{
	long double res;

	res = 1;
	if (power < 0)
	{
		power = -power;
		while (--power + 1 > 0)
			res = res * 1 / n;
		return (res);
	}
	else
		res = ft_iterative_power(n, power);
	return (res);
}
