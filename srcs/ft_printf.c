/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:00:09 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/04 14:35:31 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	char		*cpy;
	t_printf	v_printf;
	char		buff[BUFF_SIZE];
	int			ret_tot;

	va_start(ap, str);
	cpy = (char *)str;
	
}
