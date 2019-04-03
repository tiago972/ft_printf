/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:59:30 by edbaudou          #+#    #+#             */
/*   Updated: 2019/04/03 16:26:22 by edbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/includes/libft.h"
# define BUFF_SIZE 2048

int				ft_printf(const char *str, ...);
typedef struct	s_printf 
{
	int		ret_tot;
	int		ret_progress;
	int		ret_to_do;
	char	buff[BUFF_SIZE];
}				t_printf;
void			ft_write(t_printf *v_printf);
void			ft_dispatch(t_printf *v_printf, va_list *ap, char **str);
typedef struct		s_dispatch
{
	char	*opt;
	void	(*f)(t_printf *v_printf, va_list *ap); 
}					t_dispatch;
void		ft_initialize(t_dispatch array[2]);
void		ft_flush(t_printf *v_printf);
void		ft_opt_s(t_printf *v_printf, va_list *ap);
void		ft_opt_c(t_printf *v_printf, va_list *ap);

# endif
