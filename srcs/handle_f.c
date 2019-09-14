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

void		ft_round(t_printf *v_printf, t_float *f)
{
	int	    i;

	i = v_printf-> prec;
	i += ft_strlen_c(f->res, '.');
	if (v_printf->prec == 0)
	    i++;
	while (i >= 0 && f->res[i + 1] >= '5' && f->res[i] != '.')
	{ 
		if (f->res[i] == '9')
			f->res[i] = '0';
		else 
			f->res[i]++;
		i--;
		if (f->res[i] == '.')
		    i--;
		if (f->res[i] < '9')
			f->res[i]++;
	}
}

void		ft_del_f(t_float *f)
{
	ft_strdel(&(f->res));
	ft_strdel(&(f->mant));
	ft_strdel(&(f->dec));
	ft_strdel(&(f->tmp));
}

void		ft_handle_f(t_printf *v_printf)
{
	t_float		f;

	ft_memset(&f, 0, sizeof(t_float));
	f.f_arg = ft_get_arg_f(v_printf);
	f.ptr = (unsigned char *)&(f.f_arg);
	if (!(ft_initialize_f_char(&f)))
		return ;
	if (ft_isinf(&f, v_printf) || ft_isna(&f, v_printf))
	{
	    ft_del_f(&f);
	    return; 
	}
	if ((v_printf->flags & DOT) && v_printf->prec == -2)
		v_printf->prec = 0;
	else if (!(v_printf->flags & DOT) || v_printf->prec == -2)
		v_printf->prec = 6;
	ft_sign_f(&f);
	ft_get_exp(&f);
	ft_get_mant(&f);
	ft_expand_mant(&f);
	ft_calc_int(&f);
	ft_calc_dec(&f);
	ft_memcpy(f.res + f.int_size + 1, f.dec, F_SIZE - (f.int_size + 1));
	ft_round(v_printf, &f);
	ft_pad_f(v_printf, &f, 0);
	ft_del_f(&f);
    }
