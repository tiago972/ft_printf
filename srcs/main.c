#include <stdio.h>
#include "../includes/ft_printf.h"
#include <limits.h>

int		main()
{
	char *test;
	//char test2 = '\0';
	int	i;
	int	j;
	char c = 'f';

	test = ft_strnew(500);
	ft_strcpy(test, "test a la con");
	//i = ft_printf("ceci est un %-050d\n", 42);
	j = printf("ceci est un % -50d\n", 42);
	//printf("EUX = %d, MOI %d\n", j, i);
	ft_strdel(&test);
	return (0);
}
