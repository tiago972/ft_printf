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
