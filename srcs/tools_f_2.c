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

void		ft_power_to_char(t_float *f, int power, int mant_index)
{
    int	    ret;
    int	    tmp_index;
    int	    res_tmp;

    ret = 0;
    tmp_index = ft_strlen(f->tmp) - 1;
    if (power == 0)
    {
	f->tmp[tmp_index] = 1 * f->mant[mant_index] + '0';
	return ;
    }
    if (f->mant[mant_index] == '0')
    {	
	ft_memset(f->tmp, '0', F_SIZE);
	return;
    }
    //printf("power = %d\n", power);
    /*(void)power;
    //(void)mant_index;
    (void)ret;
    (void)tmp_index;
    (void)res_tmp;
    printf("%s\n", f->tmp);*/
    //printf("va rentrer\n");
    while (power >= 0)
    {
	printf("c = %c, tmp_index %d\n", f->tmp[tmp_index], tmp_index);
	res_tmp = ((f->tmp[tmp_index] - '0') * 2 + ret);
	ret = res_tmp / 10;
	printf("ret = %d\n", ret);
	f->tmp[tmp_index] = res_tmp % 10 + '0';
	if (f->tmp[tmp_index] == '9' || ret > 0)
	{
	    printf("true\n");
	    tmp_index--;
	}
	power--;
    }
    printf("tmp = %s\n", f->tmp);
}

void		ft_calc_int(t_float *f)
{
	int	    mant_index;
	int	    i;

	mant_index = ft_strlen_c(f->mant, '.') - 1;
	i = mant_index;
	while (i >= 0)
	{
	    ft_memset(f->tmp, '0', F_SIZE);
	    f->tmp[ft_strlen(f->tmp) - 1] = '1';
	    ft_power_to_char(f, mant_index - i, i);
	    //ft_add_in_char(f->res, f->tmp);
	    i--;
	}
}
