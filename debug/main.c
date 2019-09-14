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
    nb = 45.123456789;

    /*printf("space:% f|\n", nb);
    printf("plus:%+f\n", nb);
    printf("hash:%#f\n", nb);
    printf("precision:%.2f\n", nb);
  	printf("big prec:%.14f\n", nb);
    printf("precision + hash:%#.0f\n", nb);
    printf("space + prec:% .5f\n", nb);
    printf("space + prec + hash:%# .0f\n", nb);
    printf("space + prec + hash:% #.0f\n", nb);
    printf("Plus + prec / grande:%+.5f\n", nb);
    printf("Plus + prec / petite:%+.0f\n", nb);
    printf("Plus + prec + hash:%#+.0f\n", nb);
    printf("Prec + 0:%0.5f\n", nb);
    printf("Prec + minus:%-.5f\n", nb);
    printf("size:%5f\n", nb);
    printf("size + space:% 5f\n", nb);
    printf("size + plus:%+5f\n", nb);
    printf("size + space:%# 5f\n", nb);
    printf("size + plus:%#+5f\n", nb);
    printf("size + minus:%-5f\n", nb);
    printf("size + 0:%05f\n", nb);
    printf("size + 0 + plus:%+05f\n", nb);
    printf("size + 0 + plus:%0+5f\n", nb);
    printf("size + 0 + prec:%05.3f\n", nb);
    printf("size + 0 + prec + hash:%0#5.0f\n", nb);
    printf("size + minus + prec:%-5.3f\n", nb);*/
    ft_printf("size + minus + prec + hash:%-#5.0f|\n", nb);
    printf("size + minus + prec + hash:%-#5.0f|\n", nb);
    /*printf("size + plus + 0 + prec:%+05.3f\n", nb);
    printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
    printf("size + espace + zero + prec:%0 5.3f\n", nb);
    printf("size + espace + zero + prec:% 05.3f\n", nb);
    printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
    printf("size + minus + plus + prec:%-+5.3f\n", nb);
    printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb); */
	return (0);
}
