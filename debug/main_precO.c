#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int		main(void)
{
	unsigned int		nb;
	nb = 0;
	printf("null prec : %.0x\n", nb);
	printf("null prec : %.x\n", nb);
	printf("null prec : %12.0x\n", nb);
	printf("null prec : %-5.x\n", nb);
	printf("null prec : %#.0x\n", nb);
	printf("null prec : %#.x\n", nb);
	printf("null prec : %#12.0x\n", nb);
	printf("null prec : %#-5.x\n", nb);
	printf("null prec : %.0X\n", nb);
	printf("null prec : %.X\n", nb);
	printf("null prec : %12.0X\n", nb);
	printf( "null prec : %-5.X\n", nb);
	printf("null prec : %#.0X\n", nb);
	printf("null prec : %#.X\n", nb);
	printf("null prec : %#12.0X\n", nb);
	printf("null prec : %#-5.X\n", nb);
	printf("null prec : %.0o\n", nb);
	printf("null prec : %.o\n", nb);
	printf("null prec : %12.0o\n", nb);
	printf( "null prec : %-5.o\n", nb);
	printf("null prec : %#.0o|\n", nb);
	printf("null prec : %#.o|\n", nb);
	printf("null prec : %#12.0o|\n", nb);
	printf("null prec : %#-5.o|\n", nb);

	nb = 21;
	printf("null prec : %.0x\n", nb);
	printf("null prec : %.x\n", nb);
	printf("null prec : %12.0x\n", nb);
	printf("null prec : %-5.x\n", nb);

	nb = 21;
	printf("null prec : %.0X\n", nb);
	printf("null prec : %.X\n", nb);
	printf("null prec : %12.0X\n", nb);
	printf( "null prec : %-5.X\n", nb);
	nb = 21;
	printf("null prec : %.0o\n", nb);
	printf("null prec : %.o\n", nb);
	printf("null prec : %12.0o\n", nb);
	printf( "null prec : %-5.o\n", nb);

	nb = -543;
	printf("null prec : %.0x\n", nb);
	printf("null prec : %.x\n", nb);
	printf("null prec : %12.0x\n", nb);
	printf("null prec : %-5.x\n", nb);

	nb = -543;
	printf("null prec : %.0X\n", nb);
	printf("null prec : %.X\n", nb);
	printf("null prec : %12.0X\n", nb);
	printf( "null prec : %-5.X\n", nb);

	nb = -543;
	printf("null prec : %.0o\n", nb);
	printf("null prec : %.o\n", nb);
	printf("null prec : %12.0o\n", nb);
	printf( "null prec : %-5.o\n", nb);
	return (0);
}
