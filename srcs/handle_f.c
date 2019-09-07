/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:07:51 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/07 11:20:16 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>
#include "../libft/includes/libft.h"
#include <math.h>

void		ft_ftoa_2(t_float *f)
{
	double		weight;
	int			nbr;
	
	if (f->f_arg == 0)
		f->m--;
	while (f->prec < 1 || f->m >= 0)
	{
		weight = ft_iterative_power_f(f->m, 10.0);
		if (weight >= 0 && weight != INFINITY)
		{
			nbr = ft_floor(f->f_arg / weight);
			f->f_arg -= (nbr * weight);
			*(f->res++) = '0' + nbr;
		}
		if (f->m == 0)
			*(f->res++) = '.';
		if (f->m < 0)
			f->prec *= 10;
		f->m--;
	}
}

void		ft_ftoa(t_float *f, t_printf *v_printf)
{
	f->prec = ft_iterative_power_f(-(v_printf->prec + 1), 10.0);
	while ((v_printf->flags & ZERO) && --(v_printf->width) > 0)
		*(f->res++) = '0';
	if (f->m >= 14 || (f->sign && f->m >= 9) || f->m <= -9)
	{
		f->exp = 1;
		if (f->m < 0)
			f->m -= 1.0;
		f->f_arg /= ft_iterative_power_f(10.0, f->f_arg);
		f->new_mag = f->m;
		f->m = 0;
	}
	if (f->m < 1.0)
		f->m = 0;
	ft_ftoa_2(f);
}

void		ft_round(t_float *f, t_printf *v_printf)
{
	if (v_printf->prec == 0)
		return ;
	f->res--;
	while (*(f->res) && *(f->res) != '.' && *(f->res) >= '5')
	{
		if (*(f->res) == '9')
			*(f->res) = '0';
		else 
			(*f->res)++;
		f->res--;
		if (*(f->res) < '9')
			(*f->res)++;
	}
}

void		ft_handle_f2(t_printf *v_printf, t_float *f, char *cpy_res)
{
	if ((v_printf->flags & DOT) && v_printf->prec == -2)
		v_printf->prec = 0;
	else if (!(v_printf->flags & DOT) || v_printf->prec == -2)
		v_printf->prec = 6;
	f->sign = ft_sign_f(f);
	f->m = (int)ft_magnitude(f);
	v_printf->width -= (v_printf->prec + f->m);
	if (f->sign == 1)
		v_printf->width--;
	if (f->prec != 0)
		v_printf->width--;
	ft_ftoa(f, v_printf);
	ft_round(f, v_printf);
	ft_pad_f(v_printf, cpy_res, 0, *f);
}

void		ft_handle_f(t_printf *v_printf)
{
	t_float		f;
	char		*cpy_res;

	ft_memset(&f, 0, sizeof(t_float));
	f.f_arg = ft_get_arg_f(v_printf);
	if (!(f.res = ft_strnew(F_SIZE)))
		return ;
	cpy_res = f.res;
	if (ft_isinf(&f, v_printf, &cpy_res) || ft_isna(&f, v_printf, &cpy_res))
	{
		ft_pad_f(v_printf, cpy_res, 1, f);
		return ;
	}
	ft_handle_f2(v_printf, &f, cpy_res);
	ft_strdel(&cpy_res);
}
