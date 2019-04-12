#include <stdio.h>
#include "./includes/ft_printf.h"
#include <limits.h>

int		main()
{
	char *test;
	//char test2 = '\0';
	int	i;
	int	j;
	float f = 15.0;
	char c = 'f';

	test = ft_strnew(500);
	ft_strcpy(test, "test a la con");
	i = ft_printf("ceci est un %f\n", f);
	j = printf("ceci est un %f\n", f);
	printf("EUX = %d, MOI %d\n", j, i);
	ft_strdel(&test);
	return (0);
}
