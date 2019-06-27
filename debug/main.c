#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int		main(void)
{
	printf("%f|", 0.);
	printf("\n");
	ft_printf("%f|", 0.);
	return (0);
}
