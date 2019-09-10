#include <stdio.h>
#include "../libft/includes/libft.h"
#include <limits.h>
#include <math.h>

int		main()
{
	long double f = -0.073;
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
	}/*
	i =  CHAR_BIT * sizeof(f) - 8 * 8;
	while (--i + 1 > 80)
	{
		if (test[i/CHAR_BIT] & (1U << (i % CHAR_BIT)))
			count++;
	}
	printf("\n%d\n", count);
	printf("%100.200Lf\n", f);*/
	return (0);
}
