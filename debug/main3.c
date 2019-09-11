#include <stdio.h>
#include "../libft/includes/libft.h"
#include <limits.h>
#include <math.h>
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
int		main()
{
	long double f1 = 0;
	long double f2 = 4;
	bit(f1);
	printf("\n");
	bit(f2);
	return (0);
}
