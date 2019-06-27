#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int		main(void)
{
	printf("%.5hho|%-.5hho|%#.5hho|%0.5hho", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	printf("\n");
	ft_printf("%.5hho|%-.5hho|%#.5hho|%0.5hho", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	return (0);
}
