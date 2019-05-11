/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:07:51 by edbaudou          #+#    #+#             */
/*   Updated: 2019/05/11 17:25:47 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>
#include "../libft/includes/libft.h"
#include <math.h>

long double	ft_get_arg_f(t_printf *v_printf)
{
	if (v_printf->flags & LF)
		return ((long double)va_arg(v_printf->ap, long double));
	else if (v_printf->flags & L)
		return ((double)va_arg(v_printf->ap, double));
	else 
		return ((float)va_arg(v_printf->ap, double));
}

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
		f->m--;
		f->prec *= 10;
	}
}
void		ft_ftoa(t_float *f, t_printf *v_printf)
{
	f->prec = ft_iterative_power_f(-(v_printf->prec + 1), 10.0);
	f->sign = ft_sign_f(f);
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
	while (*(f->res) && *(f->res) != '.' && *(f->res) == '9')
	{
		*(f->res) = '0';
		f->res--;
		if (*(f->res) < '9')
			(*f->res)++;
	}
}

void		ft_pad_f(t_printf *v_printf)
{
	t_float		f;
	char		*cpy_res;

	ft_memset(&f, 0, sizeof(t_float));
	f.f_arg = ft_get_arg_f(v_printf);	
	if (ft_isinf(&f, v_printf) || ft_isna(&f, v_printf))
		return ;
	if (!(f.res = ft_strnew(F_SIZE)))
		return ;
	cpy_res = f.res;
	if (!(v_printf->flags & DOT) || v_printf->prec == -2)
		v_printf->prec = 6;
	f.m = (int)ft_magnitude(&f);
	v_printf->width -= (v_printf->prec + f.m);
	if (f.sign == 1)
		v_printf->width--;
	if (f.prec != 0)
		v_printf->width--;
	ft_ftoa(&f, v_printf);
	ft_round(&f, v_printf);
	if (!(v_printf->flags & MINUS) && !(v_printf->flags & ZERO))
	{
		if ((v_printf->flags & PLUS || v_printf->flags & SP) && f.sign == 0)
			v_printf->width--;
		while (--(v_printf->width) > 0)
			ft_buff(v_printf, " ", 1);
	}
	if ((v_printf->flags & PLUS || v_printf->flags & SP) && f.sign == 0)
		v_printf->flags & PLUS ? ft_buff(v_printf, "+", 1)
				: ft_buff(v_printf, " ", 1);
	ft_buff(v_printf, cpy_res, ft_strlen(cpy_res) - 1);
	while ((v_printf->flags & MINUS) && --(v_printf->width) > 0)
		ft_buff(v_printf, " ", 1);
	ft_strdel(&cpy_res);
}
