#include "../includes/ft_printf.h"

int	ft_where_is_not_0(char *str, int index)
{
    int	    i;

    i = 0;
    while (str[i] && i < index)
    {
	if (str[i] != '0')
	    return (i);
	i++;
    }
    return (F_SIZE);
}

void	ft_add_in_char(t_float *f)
{
    int	    i;
    int	    ret;
    int	    tmp;
    int	    lim;

    lim = ft_min(ft_where_is_not_0(f->tmp, F_SIZE), ft_where_is_not_0(f->res, F_SIZE));
    i = 1;
    ret = 0;
    while (i <= lim)
    {
	tmp = (f->res[F_SIZE - i] - '0') + (f->tmp[F_SIZE - i] - '0') + ret;
	ret = tmp / 10;
	f->res[F_SIZE - i] = tmp % 10 + '0';
	i++;
    }
}
/*
void	ft_calc_dec(t_flot *f)
{
    int	    mant_index;
    int	    i;

    mant_index = ft_strlen_c(f->mant, '.') + 1;
    i = 1;
    while (mant_index < F_SIZE)
    {
	ft_memset(f->tmp, '0', F_SIZE);
	if (f->mant[mant_index] != '0')
	{
	    ft_negpower_to_char(f, mant_index - i, mant_firstnbr);
	    ft_add_in_char(f);
	}
	i++;
	mant_index++;
    }

}*/
