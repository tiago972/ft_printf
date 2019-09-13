/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:07:51 by edbaudou          #+#    #+#             */
/*   Updated: 2019/09/08 16:24:14 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

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

void		ft_handle_f(t_printf *v_printf)
{
	t_float		f;

	ft_memset(&f, 0, sizeof(t_float));
	f.f_arg = ft_get_arg_f(v_printf);
	f.ptr = (unsigned char *)&(f.f_arg);
	if (!(ft_initialize_f_char(&f)))
		return ;
	ft_sign_f(&f);
	ft_get_exp(&f);
	ft_get_mant(&f);
	ft_expand_mant(&f);
	ft_calc_int(&f);
	ft_calc_dec(&f);
	printf("int = %s\n dec = %s\n", f.res, f.dec);
	/*
	if (ft_isinf(&f, v_printf, &cpy_res) || ft_isna(&f, v_printf, &cpy_res))*/
	ft_strdel(&(f.res));
	ft_strdel(&(f.mant));
	ft_strdel(&(f.dec));
	ft_strdel(&(f.tmp));
}
