#include <stdio.h>
#include "../includes/ft_printf.h"
#include <limits.h>

int		main()
{
	char *test;
	char test2 = '\0';
	int	d = 15;
	test = ft_strnew(5);
	ft_strcpy(test, "12345");
	printf("% d", d);
	ft_strdel(&test);
	return (0);
}
