#include <stdio.h>
#include "../includes/ft_printf.h"
#include <limits.h>

int		main()
{
	char *test;
	char test2 = '\0';
	int	i;
	int	j;

	test = ft_strnew(500);
	ft_strcpy(test, "test a la con");
	i = ft_printf("ceci est un % 50s\n", test);
	//j = printf("ceci est un %-50s\n", test);
	//printf("EUX = %d, MOI %d\n", j, i);
	ft_strdel(&test);
	return (0);
}
