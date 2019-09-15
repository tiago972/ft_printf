#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

void	bit(long double f)
{
	unsigned char *test = (unsigned char *)&f;
	unsigned i = CHAR_BIT * sizeof(f);
	long int t = (long int)f;
	int count = 0;
	while (--i + 1 > 0)
	{
		if (test[i/CHAR_BIT] & (1U << (i % CHAR_BIT)))
			printf("1");
		else
			printf("0");
		if (i % 8 == 0)
			printf(" ");
	}
}

int		main(void)
{
 
	double		nb;

 nb = 1.0/0.0;
	/*printf("%f|\n", nb);
	ft_printf("%f|\n", nb);
	printf("%12f\n", nb);
	ft_printf("%12f\n", nb);
	printf("%-12f|\n", nb);
	ft_printf("%-12f|\n", nb);
	printf("%5.9f\n", nb);
	ft_printf("%5.9f\n", nb);*/

    nb = -1.0/0.0;
	printf("%f\n", nb);
	ft_printf("%f\n", nb);
	printf("%12f\n", nb);
	ft_printf("%12f\n", nb);
	printf("%-12f|\n", nb);
	ft_printf("%-12f|\n", nb);
	printf("%5.9f\n", nb);
	ft_printf("%5.9f\n", nb);
/*
	nb = 0.0/0.0;
	printf("%f\n", nb);
	ft_printf("%f\n", nb);
	printf("%12f\n", nb);
	ft_printf("%12f\n", nb);
	printf("%-12f|\n", nb);
	ft_printf("%-12f|\n", nb);
	printf("%5.9f\n", nb);
	ft_printf("%5.9f\n", nb);*/
	return (0);
}
