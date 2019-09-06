#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int		main(void)
{
	printf("%f|%-f|%+f|% f|%#f|%0f", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY);
	printf("\n");
	ft_printf("%f|%-f|%+f|% f|%#f|%0f", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY);
	return (0);
}
