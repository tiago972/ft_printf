#include <stdio.h>
#include "../includes/ft_printf.h"
#include <limits.h>

int		main()
{
	char *test;
	int	i;
	int	j;
	char test2 = '\0';

	test = ft_strnew(5);
	ft_strcpy(test, "12345");
	i = ft_printf("%s lalala%s %c\n", test, "yououuuuu", test2);
	j = printf("%s lalala%s %c\n", test, "yououuuuu", test2);
	printf("RETURN me %d them %d\n", i, j);
	ft_strdel(&test);
	return (0);
}
