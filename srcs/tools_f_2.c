/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_f_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:01:54 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/07 13:05:15 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

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

void			ft_opt_pad_f(t_printf *v_printf, char *cpy_res, int opt, int i)
{
	if (opt == 0)
	{
		if (cpy_res[i] == '.' && v_printf->prec != 0 && i++)
			ft_buff(v_printf, ".", 1);
		ft_buff(v_printf, cpy_res + i, v_printf->prec);
		if (v_printf->flags & POUND && v_printf->prec == 0)
			ft_buff(v_printf, ".", 1);
	}
}

void			ft_pad_f(t_printf *v_printf, char *cpy_res, int opt, t_float f)
{
	int		i;

	i = 0;
	if (opt == 1 && v_printf->flags & ZERO)
		v_printf->flags &= ~ZERO;
	if (!(v_printf->flags & MINUS) && !(v_printf->flags & ZERO))
	{
		if ((v_printf->flags & PLUS || v_printf->flags & SP) && f.sign == 0)
			v_printf->width--;
		while (--(v_printf->width) > 0)
			ft_buff(v_printf, " ", 1);
		if (opt == 1 && v_printf->width == 0)
			ft_buff(v_printf, " ", 1);
	}
	if ((v_printf->flags & PLUS || v_printf->flags & SP) && f.sign == 0
			&& f.f_arg == f.f_arg)
		v_printf->flags & PLUS ? ft_buff(v_printf, "+", 1)
			: ft_buff(v_printf, " ", 1);
	while ((v_printf->flags & ZERO) && opt == 0 && --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	while (cpy_res[i] && cpy_res[i] != '.' && ++i)
		ft_buff(v_printf, cpy_res + i - 1, 1);
	ft_opt_pad_f(v_printf, cpy_res, opt, i);
	if (v_printf->flags & MINUS && (v_printf->flags & PLUS ||
				v_printf->flags & SP) && f.sign != 1)
		v_printf->width--;
	while ((v_printf->flags & MINUS) && --(v_printf->width) > 0)
		ft_buff(v_printf, " ", 1);
	if (opt == 1 && v_printf->flags & MINUS && v_printf->width == 0)
			ft_buff(v_printf, " ", 1);

}

long double		ft_get_arg_f(t_printf *v_printf)
{
	if (v_printf->flags & LF)
		return ((long double)va_arg(v_printf->ap, long double));
	else if (v_printf->flags & L)
		return ((double)va_arg(v_printf->ap, double));
	else 
		return ((float)va_arg(v_printf->ap, double));
}
