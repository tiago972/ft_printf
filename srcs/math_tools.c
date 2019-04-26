#include "../includes/ft_printf.h"

uintmax_t		ft_log(uintmax_t nb, uintmax_t base)
{
	uintmax_t	power;

	power = 0;
	while (nb >= base)
	{
		nb /= base;
		power++;
	}
	power++;
	return (power);
}/*
uintmax_t	ft_leading_zero(uintmax_t nb)
{
	unsigned long	i;
	uintmax_t		count;

	count = 0;
	i = 63;
	while (i > 0)
	{
		if (1 & (nb >> i))
			count++;
		i--;
	}
	return (count);
}
uintmax_t	ft_power(uintmax_t nb, uintmax_t base)
{
	double		ln;
	uintmax_t	res;

	ln = 0.0;
	if (base == 16)
		ln = LOG16;
	else if (base == 8)
		ln = LOG8;
	else if (base == 10)
		ln = LOG10;
	ln = ft_leading_zero(nb)/ln;
	ln += 1;
	res = (uintmax_t)ln;
	return (res);
}*/

int				ft_min(int a, int b)
{
	return (a > b ? b : a);
}

int				ft_max(int a, int b)
{
	return (a > b ? a : b);
}

uintmax_t		ft_abs(intmax_t a)
{
	return (a < 0 ? -a : a);
}

int		ft_iterative_power(int nb, int power)
{
	int		res = 1;

	if (power == 0)
		return (1);
	while (power > 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}
