/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:23:26 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/08 16:18:07 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>
#include <math.h>
#include "../libft/includes/libft.h"

int				ft_sign_f(t_float *f)
{
	unsigned char	*ptr;
	unsigned		i;

	i = 79;
	ptr = (unsigned char *)&(f->f_arg);
	if (ptr[i / CHAR_BIT] & (1U << (i % CHAR_BIT)))
	{
		*(f->res)++ = '-';
		f->f_arg = -(f->f_arg);
		return (1);
	}
	return (0);
}

int				ft_isna(t_float *f, t_printf *v_printf, char **res)
{
	if (f->f_arg != f->f_arg)
	{
		v_printf->width -= 3;
		ft_memcpy(*res, "nan", 3);
		return (1);
	}
	return (0);
}

int				ft_isinf(t_float *f, t_printf *v_printf, char **res)
{
	if (f->f_arg == INFINITY)
	{
		v_printf->width -= 3;
		ft_memcpy(*res, "inf", 3);
		return (1);
	}
	else if (f->f_arg == -INFINITY)
	{
		v_printf->width -= 4;
		f->sign = 1;
		ft_memcpy(*res, "-inf", 4);
		return (1);
	}
	return (0);
}
