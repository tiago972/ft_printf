#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int		main(void)
{
	unsigned int	nb = 0;

	/*printf("test o:%o\n", nb);
	  ft_printf("test o:%o\n", nb);
	  printf("hash:%#o\n", nb);
	  ft_printf("hash:%#o\n", nb);
	  printf("precision / grande:%.5o\n", nb);
	  ft_printf("precision / grande:%.5o\n", nb);
	  printf("Prec + hash / grande:%#.5o\n", nb);
	  ft_printf("Prec + hash / grande:%#.5o\n", nb);
	  printf("Prec + hash / petite:%#.1o\n", nb);
	  ft_printf("Prec + hash / petite:%#.1o\n", nb);
	  printf("Prec + 0:%0.5o\n", nb);
	  ft_printf("Prec + 0:%0.5o\n", nb);
	  printf("Prec + minus:%-.5o\n", nb);
	  ft_printf("Prec + minus:%-.5o\n", nb);
	  printf("Size:%5o\n", nb);
	  ft_printf("Size:%5o\n", nb);
	  printf("size + prec:%7.3o\n", nb);
	  ft_printf("size + prec:%7.3o\n", nb);
	  printf("size + minus:%-5o\n", nb);
	  printf("size + minus:%-5o\n", nb);
	  ft_printf("size + zero:%05o\n", nb);
	  printf("size + zero:%05o\n", nb);
	  printf("size + zero + hash:%#05o\n", nb);
	  ft_printf("size + zero + hash:%#05o\n", nb);
	  printf("size + zero + prec:%05.3o\n", nb);
	  ft_printf("size + zero + prec:%05.3o\n", nb);
	  printf("size + minus + prec:%-5.3o\n", nb);
	  ft_printf("size + minus + prec:%-5.3o\n", nb);
	  printf("size + hash + zero + prec:%#05.3o\n", nb);
	  ft_printf("size + hash + zero + prec:%#05.3o\n", nb);
	  printf("size + hash + zero + prec:%0#5.3o\n", nb);
	  ft_printf("size + hash + zero + prec:%0#5.3o\n", nb);
	  printf("size + hash + minus + prec:%-#7.3o\n", nb);
	  ft_printf("size + hash + minus + prec:%-#7.3o\n", nb);*/

	/*	nb = 45;
		printf("test o:%o\n", nb);
		ft_printf("test o:%o\n", nb);
		printf("hash:%#o\n", nb);
		ft_printf("hash:%#o\n", nb);
		printf("precision / grande:%.5o\n", nb);
		ft_printf("precision / grande:%.5o\n", nb);
		printf("precision / petite:%.0o\n", nb);
		ft_printf("precision / petite:%.0o\n", nb);
		printf("Prec + hash / grande:%#.5o\n", nb);
		ft_printf("Prec + hash / grande:%#.5o\n", nb);
		printf("Prec + hash / petite:%#.1o\n", nb);
		ft_printf("Prec + hash / petite:%#.1o\n", nb);
		printf("Prec + 0:%0.5o\n", nb);
		ft_printf("Prec + 0:%0.5o\n", nb);
		printf("Prec + minus:%-.5o\n", nb);
		ft_printf("Prec + minus:%-.5o\n", nb);
		printf("Size:%5o\n", nb);
		ft_printf("Size:%5o\n", nb);
		printf("size + prec:%7.3o\n", nb);
		ft_printf("size + prec:%7.3o\n", nb);
		printf("size + minus:%-5o\n", nb);
		ft_printf("size + minus:%-5o\n", nb);
		printf("size + zero:%05o\n", nb);
		ft_printf("size + zero:%05o\n", nb);
		printf("size + zero + hash:%#05o\n", nb);
		ft_printf("size + zero + hash:%#05o\n", nb);
		printf("size + zero + prec:%05.3o\n", nb);
		ft_printf("size + zero + prec:%05.3o\n", nb);
		printf("size + minus + prec:%-5.3o|\n", nb);
		ft_printf("size + minus + prec:%-5.3o\n", nb);
		printf("size + hash + zero + prec:%#05.8o\n", nb);
		ft_printf("size + hash + zero + prec:%#05.8o\n", nb);
		printf("size + hash + zero + prec:%0#5.3o\n", nb);
		ft_printf("size + hash + zero + prec:%0#5.3o\n", nb);
		printf("size + hash + minus + prec:%-#7.3o|\n", nb);
		ft_printf("size + hash + minus + prec:%-#7.3o|\n", nb);*/

	nb = 123564789;
	/*printf("test o:%o\n", nb);
	  ft_printf("test o:%o\n", nb);
	  printf("hash:%#o\n", nb);
	  ft_printf("hash:%#o\n", nb);
	  printf("precision / grande:%.5o\n", nb);
	  ft_printf("precision / grande:%.5o\n", nb);
	  printf("precision / petite:%.0o\n", nb);
	  ft_printf("precision / petite:%.0o\n", nb);
	  printf("Prec + hash / grande:%#.5o\n", nb);
	  ft_printf("Prec + hash / grande:%#.5o\n", nb);
	  printf("Prec + hash / petite:%#.1o\n", nb);
	  ft_printf("Prec + hash / petite:%#.1o\n", nb);
	  printf("Prec + 0:%0.5o\n", nb);
	  ft_printf("Prec + 0:%0.5o\n", nb);
	  printf("Prec + minus:%-.5o\n", nb);
	  ft_printf("Prec + minus:%-.5o\n", nb);
	  printf("Size:%5o\n", nb);
	  ft_printf("Size:%5o\n", nb);
	  printf("size + prec:%7.3o\n", nb);
	  ft_printf("size + prec:%7.3o\n", nb);
	  printf("size + minus:%-5o\n", nb);
	  ft_printf("size + minus:%-5o\n", nb);
	  printf("size + zero:%05o\n", nb);
	  ft_printf("size + zero:%05o\n", nb);
	  printf("size + zero + hash:%#05o\n", nb);
	  ft_printf("size + zero + hash:%#05o\n", nb);
	  printf("size + zero + prec:%05.3o\n", nb);
	  ft_printf("size + zero + prec:%05.3o\n", nb);
	  printf("size + minus + prec:%-5.3o\n", nb);
	  ft_printf("size + minus + prec:%-5.3o\n", nb);
	  printf("size + hash + zero + prec:%#05.3o\n", nb);
	  ft_printf("size + hash + zero + prec:%#05.3o\n", nb);
	  printf("size + hash + zero + prec:%0#5.3o\n", nb);
	  ft_printf("size + hash + zero + prec:%0#5.3o\n", nb);
	  printf("size + hash + minus + prec:%-#7.3o\n", nb);
	  ft_printf("size + hash + minus + prec:%-#7.3o\n", nb);*/


	nb = 0;

	/*printf("null prec : %.0x\n", nb);
	ft_printf("null prec : %.0x\n", nb);
	printf("null prec : %.x\n", nb);
	ft_printf("null prec : %.x\n", nb);
	printf("null prec : %12.0x\n", nb);
	ft_printf("null prec : %12.0x\n", nb);
	printf("null prec : %-5.x\n", nb);
	ft_printf("null prec : %-5.x\n", nb);
	printf("null prec : %.0x\n", nb);
	ft_printf("null prec : %#.0x\n", nb);
	printf("null prec : %#.x\n", nb);
	ft_printf("null prec : %#.x\n", nb);
	printf("null prec : %#12.0x\n", nb);
	ft_printf("null prec : %#12.0x\n", nb);
	printf("null prec : %#-5.x\n", nb);
	ft_printf("null prec : %#-5.x\n", nb);
	printf("null prec : %.0X\n", nb);
	ft_printf("null prec : %.0X\n", nb);
	printf("null prec : %.X\n", nb);
	ft_printf("null prec : %.X\n", nb);
	printf("null prec : %12.0X\n", nb);
	ft_printf("null prec : %12.0X\n", nb);
	printf( "null prec : %-5.X\n", nb);
	ft_printf( "null prec : %-5.X\n", nb);
	printf("null prec : %#.0X\n", nb);
	ft_printf("null prec : %#.0X\n", nb);
	printf("null prec : %#.X\n", nb);
	ft_printf("null prec : %#.X\n", nb);
	printf("null prec : %#12.0X\n", nb);
	ft_printf("null prec : %#12.0X\n", nb);
	printf("null prec : %#-5.X\n", nb);
	ft_printf("null prec : %#-5.X\n", nb);*/
	printf("null prec : %.0o\n", nb);
	ft_printf("null prec : %.0o\n", nb);
	printf("null prec : %.o\n", nb);
	ft_printf("null prec : %.o\n", nb);
	printf("null prec : %12.0o\n", nb);
	ft_printf("null prec : %12.0o\n", nb);
	printf( "null prec : %-5.o\n", nb);
	ft_printf( "null prec : %-5.o\n", nb);
	/*
	printf("null prec : %#.0o\n", nb);
	ft_printf("null prec : %#.0o\n", nb);
	printf("null prec : %#.o\n", nb);
	ft_printf("null prec : %#.o\n", nb);
	printf("null prec : %#12.0o\n", nb);
	ft_printf("null prec : %#12.0o\n", nb);
	printf("null prec : %#-5.o\n", nb);
	ft_printf("null prec : %#-5.o\n", nb);

	
	//printf("null prec : %12.15o\n", nb);
	nb = 21;
	printf("null prec : %.0x\n", nb);
	ft_printf("null prec : %.0x\n", nb);
	printf("null prec : %.x\n", nb);
	ft_printf("null prec : %.x\n", nb);
	printf("null prec : %12.0x\n", nb);
	ft_printf("null prec : %12.0x\n", nb);
	printf("null prec : %-5.x\n", nb);
	ft_printf("null prec : %-5.x\n", nb);
	printf("null prec : %.0X\n", nb);
	ft_printf("null prec : %.0X\n", nb);
	printf("null prec : %.X\n", nb);
	ft_printf("null prec : %.X\n", nb);
	printf("null prec : %12.0X\n", nb);
	ft_printf("null prec : %12.0X\n", nb);
	printf( "null prec : %-5.X\n", nb);
	ft_printf( "null prec : %-5.X\n", nb);
	printf("null prec : %.0o\n", nb);
	ft_printf("null prec : %.0o\n", nb);
	printf("null prec : %.o\n", nb);
	ft_printf("null prec : %.o\n", nb);
	printf("null prec : %12.0o\n", nb);
	ft_printf("null prec : %12.0o\n", nb);
	printf( "null prec : %-5.o\n", nb);
	ft_printf( "null prec : %-5.o\n", nb);

	nb = -543;
	printf("null prec : %.0x\n", nb);
	ft_printf("null prec : %.0x\n", nb);
	printf("null prec : %.x\n", nb);
	ft_printf("null prec : %.x\n", nb);
	printf("null prec : %12.0x\n", nb);
	ft_printf("null prec : %12.0x\n", nb);
	printf("null prec : %-5.x\n", nb);
	ft_printf("null prec : %-5.x\n", nb);
	printf("null prec : %.0X\n", nb);
	ft_printf("null prec : %.0X\n", nb);
	printf("null prec : %.X\n", nb);
	ft_printf("null prec : %.X\n", nb);
	printf("null prec : %12.0X\n", nb);
	ft_printf("null prec : %12.0X\n", nb);
	printf( "null prec : %-5.X\n", nb);
	ft_printf( "null prec : %-5.X\n", nb);
	printf("null prec : %.0o\n", nb);
	ft_printf("null prec : %.0o\n", nb);
	printf("null prec : %.o\n", nb);
	ft_printf("null prec : %.o\n", nb);
	printf("null prec : %12.0o\n", nb);
	ft_printf("null prec : %12.0o\n", nb);
	printf( "null prec : %-5.o\n", nb);
	ft_printf( "null prec : %-5.o\n", nb);*/
	return (0);
}
