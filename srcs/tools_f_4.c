#include "../includes/ft_printf.h"

void	ft_to_front(t_float *f)
{
    int	    i;
    int	    j;
    char    tmp;

    i = ft_where_is_not_0(f->res, F_SIZE);
    if (i == F_SIZE)
    {
	f->int_size = 1;
	return ;
    }
    j = 0;
    f->int_size = F_SIZE - i;
    while (f->res[i])
    {
	tmp = f->res[i];
	f->res[i] = f->res[j];
	f->res[j] = tmp;
	i++;
	j++;
    }
}

void			ft_opt_pad_f(t_printf *v_printf, t_float *f, int opt, int i)
{
	if (opt == 0)
	{
		if (f->res[i] == '.' && v_printf->prec != 0 && i++)
			ft_buff(v_printf, ".", 1);
		ft_buff(v_printf, f->res + i, v_printf->prec);
		if (v_printf->flags & POUND && v_printf->prec == 0)
			ft_buff(v_printf, ".", 1);
	}
}

void			ft_pad_f(t_printf *v_printf, t_float *f, int opt)
{
	int		i;

	i = 0;
	if (opt == 1 && v_printf->flags & ZERO)
		v_printf->flags &= ~ZERO;
	if (f->sign == -1)
	    v_printf->width--;
	if (!(v_printf->flags & MINUS) && !(v_printf->flags & ZERO))
	{
		if ((v_printf->flags & PLUS || v_printf->flags & SP) && f->sign == 1)
			v_printf->width--;
		while (--(v_printf->width) > 0)
			ft_buff(v_printf, " ", 1);
		if (opt == 1 && v_printf->width == 0)
			ft_buff(v_printf, " ", 1);
	}
	if ((v_printf->flags & PLUS || v_printf->flags & SP) && f->sign == 1
			&& f->f_arg == f->f_arg)
		v_printf->flags & PLUS ? ft_buff(v_printf, "+", 1)
			: ft_buff(v_printf, " ", 1);
	if (f->sign == -1 && opt == 0)
	    ft_buff(v_printf, "-", 1);
	while ((v_printf->flags & ZERO) && opt == 0 && --(v_printf->width) >= 0)
		ft_buff(v_printf, "0", 1);
	while (f->res[i] && f->res[i] != '.' && ++i)
		ft_buff(v_printf, f->res + i - 1, 1);
	ft_opt_pad_f(v_printf, f, opt, i);
	if (v_printf->flags & MINUS && (v_printf->flags & PLUS ||
				v_printf->flags & SP) && f->sign != -1)
		v_printf->width--;
	while ((v_printf->flags & MINUS) && --(v_printf->width) > 0)
		ft_buff(v_printf, " ", 1);
	if (opt == 1 && v_printf->flags & MINUS && v_printf->width == 0)
			ft_buff(v_printf, " ", 1);
}


