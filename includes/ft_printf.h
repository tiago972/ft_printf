/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:59:30 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/04 13:11:58 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"
# define BUFF_SIZE 2048
# define 
typedef struct	s_printf
{
	int			flags;
	int			field_width;
	int			prec;
	int			len_modifier;
	va_list		ap;
	char		*str;
	int			ret_progress;
}				t_printf;
int				ft_printf(const char *str, ...);

# endif
