#include <stdio.h>
#include "../libft/includes/libft.h"
#include <limits.h>

int		main()
{
	long double f = 263.3;
	unsigned char *test = (unsigned char *)&f;
	unsigned i = CHAR_BIT * sizeof(f);
	while (--i + 1 > 0)
	{
		if (test[i/CHAR_BIT] & (1U << (i%CHAR_BIT)))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	printf("%+15Lf\n", f);
	return (0);
}
