/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:32:11 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/03 16:33:09 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_opt_c(t_printf *v_printf, va_list *ap)
{
	char	tmp[2];

	tmp[0] = va_arg(*ap, int);
	tmp[1] = '\0';
	if (v_printf->ret_progress + 1 <= BUFF_SIZE)
		ft_strcat(v_printf->buff , tmp);
}

void	ft_opt_s(t_printf *v_printf, va_list *ap)
{
	char	*var;
	int		tmp;

	var = va_arg(*ap, char *);
	v_printf->ret_to_do = ft_strlen(var);
/*	if (v_printf->ret_to_do + v_printf->ret_progress > BUFF_SIZE)
	{
		ft_flush(v_printf);
		ft_memmove(&(v_printf->buff), var, BUFF_SIZE);
		v_printf->ret_to_do -= BUFF_SIZE;
		v_printf->progess = BUFF_SIZE;
		while (v_printf->ret_to_do > 0)
		{
			tmp = v_printf->progress;
			ft_flush(v_printf);
			if (v_printf->ret_to_do > BUFF_SIZE)
			{
				ft_memmove(&(v_printf->buff), var + BUFF_SIZE, BUFF_SIZE);
				v_printf->ret_to_do -= BUFF_SIZE;
				v_printf->progess = BUFF_SIZE;
			else
			{
				ft_memmove(&(v_printf->buff), var + tmp_prog, BUFF_SIZE);

			}
		}
	}
	else
	{*/
		ft_strcat(v_printf->buff, var);
		v_printf->ret_progress += v_printf->ret_to_do;
	//}
}
