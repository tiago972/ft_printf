#include "../includes/ft_printf.h"
#include <limits.h>

long double	ft_get_arg_f(t_printf *v_printf)
{
	if (v_printf->flags & LF)
		return ((long double)va_arg(v_printf->ap, long double));
	else if (v_printf->flags & L)
		return ((double)va_arg(v_printf->ap, double));
	else 
		return ((float)va_arg(v_printf->ap, double));
}

void		ft_pad_f(t_printf *v_printf)
{
	long double		int_arg;
	long double		f_part;
	
	(void)f_part;
	int_arg = ft_get_arg_f(v_printf);
	if ((v_printf->flags & DOT) && v_printf->prec == -2 && int_arg != 0)
		v_printf->prec = 6;
	if (int_arg == LLONG_MIN)
	{
		ft_llong_min(v_printf, int_arg);
		return ;
	}
	ft_fill_nb_i(v_printf, int_arg, 1);
	if (int_arg < 0)
		ft_buff(v_printf, "-", 1);
	while (--(v_printf->prec) >= 0)
		ft_buff(v_printf, "0", 1);
	while ((v_printf->flags & ZERO) && --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	if (v_printf->prec <= -2 && int_arg == 0 && (v_printf->flags & DOT))
		return ;
	ft_putnbr_pf(v_printf, ft_abs(int_arg), v_printf->power);
	while ((v_printf->flags & MINUS) && --(v_printf->width) >= 0)
		ft_buff(v_printf, " ", 1);
}
