#include <stdio.h>
#include "../includes/ft_printf.h"
#include <limits.h>

int		main()
{
	char *test;
	char test2 = '\0';
	int	d = 42;
	test = ft_strnew(500);
	ft_strcpy(test, "test a la con");
	//d = ft_printf("ceci est un %#s\n", test);
	//printf("N = %d\n", d);
	printf("test %5s", test);
	ft_strdel(&test);
	return (0);
}
