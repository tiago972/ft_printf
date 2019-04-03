/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:20:57 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/03 17:35:08 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_param(char c)
{
	if (c != '#' && c != '0' && c != '-' && c != '+'
			&& !(c >= 1 && c <= 9) && c != '*' && c != '.'
			&& c != 'h' && c != 'h' && c != 'l' && c != 'd'
			&& c != 'i' && c != 'o' && c != 'u' && c != 'x'
			&& c != 'X' && c != 'f' && c != 'c' && c != 's' && c != '%')
		return(0);
	return (1);
}

void	ft_initialize(t_dispatch array[2])
{
	array[0].opt = "s";
	array[0].f = &ft_opt_s;
	array[1].opt = "c";
	array[1].f = &ft_opt_c;
}

void	ft_dispatch(t_printf *v_printf, va_list *ap, char **str)
{
	int			i;
	t_dispatch	array[2];

	ft_initialize(array);
	(*str)++;
	while (**str)
	{
		if (!ft_check_param(**str))
			break ;
		if (**str == 'a' && (!ft_strncmp(*str, "aq", 2)
				|| !ft_strncmp(*str, "aq aq", 5)))
			break ;
		i = 0;
		while (i < 2)
		{
			if (ft_strncmp(array[i].opt, *str, 1) == 0)
				array[i].f(v_printf, ap);
			i++;
		}
		(*str)++;
	}
}
