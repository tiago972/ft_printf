/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_f_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:01:54 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/08 16:18:07 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include <limits.h>

long double		ft_get_arg_f(t_printf *v_printf)
{
	if (v_printf->flags & LF)
		return ((long double)va_arg(v_printf->ap, long double));
	else if (v_printf->flags & L)
		return ((double)va_arg(v_printf->ap, double));
	else 
		return ((float)va_arg(v_printf->ap, double));
}

void			ft_get_mant(t_float *f)
{
	int		i;
	int		f_size;

	f_size = F_SIZE;
	i = 0;
	while (i < 64)
	{
		f->mant[f_size--] = f->ptr[i / CHAR_BIT] & (1U << (i % CHAR_BIT)) ? '1' : '0';
		i++;
	}
	f->mant[++f_size] = '.';
	f->mant[--f_size] = '1';
}

void		ft_expand_mant(t_float *f)
{
	char	tmp;
	int		index;

	tmp = 0;
	index = 938;
	if (f->exp > 0)
	{
		while (f->mant[index + 1] && f->exp > 0)
		{
			tmp = f->mant[index];
			f->mant[index] = f->mant[index + 1];
			f->mant[index + 1] = tmp;
			index++;
			f->exp--;
		}
	}
	//else don't forget to do something
}
/*
void		ft_to_char(char *res, uintmax_t)
{

}

void		ft_calc_int(t_float *f)
{
	int		i;

	i = ft_strlen_c(f->mant, '.');
	while (i >= 0)
	{

	}
}*/
