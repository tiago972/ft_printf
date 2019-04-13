/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:09:09 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/13 17:03:38 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_gen_pad(t_printf *v_printf)
{
	if (v_printf->flags & SPACE && !(v_printf->flags & PLUS))
		ft_buff(v_printf, " ", 1);
	if (v_printf->conv & C)
	{
		v_printf->var_c = (char)va_arg(v_printf->ap, int);
		v_printf->curr_len = 1;
		ft_pad_str(v_printf);
	}
	else if (v_printf->conv & S)
	{
		v_printf->var_str = va_arg(v_printf->ap, char *);
		if (!(v_printf->flags & DOT))
			v_printf->prec = ft_strlen(v_printf->var_str);
		ft_pad_str(v_printf);
	}
	else if (v_printf->conv & D)
	{
		v_printf->var_i = ft_get_arg_i(v_printf);
		v_printf->curr_len = ft_power_i(v_printf->var_i, b_size);
		v_printf->curr_len = v_printf->var_i < 0 ? power++ : power;
		ft_pad_i(v_printf, 10, "0123456789");
	}
	else
		ft_gen_pad_b(v_printf);
}

void	ft_gen_pad_b(t_printf *v_printf)
{
	if (v_printf->conv & P)
	{
		v_printf->flags |= HASH_TAG;
		v_printf->var_u = (uintmax_t)va_arg(v_printf->ap, void *);
	}
	else if (v_printf->conv & F)
	{
		v_printf->var_float = va_arg(v_printf->ap, double);
		ft_pf_putfloat(v_printf);
		return ;
	}
	else
		v_printf->var_u = ft_get_arg_u(v_printf);
	if (v_printf->flags & HASH)
		ft_hash(v_printf);
	ft_pad_u(v_printf, 16, 
}

void	ft_hash(t_printf *v_printf)
{
	if (v_printf->conv & P || v_printf->conv & X)
		ft_buff(v_printf, "0x", 2);
	else if (v_printf->conv & XX)
		ft_buff(v_printf, "0X", 2);
	else if (v_printf->conv & O)
		ft_buff(v_printf, "0", 1);
}
