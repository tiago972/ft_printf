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

void				ft_initialize_f_char(t_float *f)
{
	if (!(f->res = ft_strnew(F_SIZE)))
	    return ;
	if (!(f->mant = ft_strnew(F_SIZE)))
	{
		ft_strdel(&(f->res));
	    return;
	}
	if (!(f->tmp = ft_strnew(F_SIZE)))
	{
		ft_strdel(&(f->res));
		ft_strdel(&(f->mant));
	    return ;
	}
	ft_memset(f->res, '0', F_SIZE);
	ft_memset(f->mant, '0', F_SIZE);
	ft_memset(f->tmp, '0', F_SIZE);
}

void				ft_sign_f(t_float *f)
{
	unsigned		i;

	i = 79;
	if (f->ptr[i / CHAR_BIT] & (1U << (i % CHAR_BIT)))
	    f->sign = -1;
	else
	    f->sign = 1;
}

void			    ft_get_exp(t_float *f)
{
    int	    i;
	int		tmp;

    i = 64;
    while (i < 79)
	{
		if (f->ptr[i / CHAR_BIT] & (1U << (i % CHAR_BIT)))
			tmp = 1;
		else
			tmp = 0;
		f->exp += (tmp * (ft_iterative_power(2, i - 64)));
		i++;
	}
	f->exp = f->exp - 16383;
}
int				ft_isna(t_float *f, t_printf *v_printf, char **res)
{
	if (f->f_arg != f->f_arg)
	{
		v_printf->width -= 3;
		f->sign = 1;
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
		f->sign = 1;
		ft_memcpy(*res, "inf", 3);
		return (1);
	}
	else if (f->f_arg == -INFINITY)
	{
		v_printf->width -= 4;
		f->sign = -1;
		ft_memcpy(*res, "-inf", 4);
		return (1);
	}
	return (0);
}
