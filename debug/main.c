#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int		main(void)
{
	unsigned int		nb;
	nb = 42;
	/*printf("test o:%o\n", nb);
	printf("hash:%#o\n", nb);
	ft_printf("precision / grande:%.5o|\n", nb);
	printf("precision / grande:%.5o|\n", nb);
	ft_printf("precision / petite:%.0o|\n", nb);
	printf("precision / petite:%.0o|\n", nb);*/
	ft_printf("Prec + hash / grande:%#.5o|\n", nb);
	printf("Prec + hash / grande:%#.5o|\n", nb);
	ft_printf("Prec + hash / petite:%#.1o|\n", nb);
	printf("Prec + hash / petite:%#.1o|\n", nb);
	/*printf("Prec + 0:%0.5o\n", nb);
	printf("Prec + minus:%-.5o\n", nb);
	printf("Size:%5o\n", nb);
	printf("size + prec:%7.3o\n", nb);
	printf("size + minus:%-5o\n", nb);
	printf("size + zero:%05o\n", nb);
	printf("size + zero + hash:%#05o\n", nb);
	printf("size + zero + prec:%05.3o\n", nb);
	printf("size + minus + prec:%-5.3o\n", nb);*/
	ft_printf("size + hash + zero + prec:%#05.3o\n", nb);
	printf("size + hash + zero + prec:%#05.3o\n", nb);
	ft_printf("size + hash + minus + prec:%-#7.3o|\n", nb);
	printf("size + hash + minus + prec:%-#7.3o|\n", nb);
	return (0);
}
