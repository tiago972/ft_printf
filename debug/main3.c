#include <stdio.h>

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


int		main()
{
	float f = 14.45;
	int	 prec = 15;
	int	ipart = (int)f;
	float fpart = ipart - f;
	printf("%.15f\n", f);
	printf(".............\n");
	printf("%d.", ipart);
	float res = 0;
	int	i = 1;
	while (prec > 0)
	{
		res = f * ft_iterative_power(10, i);
		res = (int)res % 10;
		printf("%d", (int)res);
		prec--;
		i++;
	}
	return (0);
}
