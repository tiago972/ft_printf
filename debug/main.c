#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int		main(void)
{
	printf("%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f", 6., 0., 0., 0., 0., 0.);
	printf("\n");
	ft_printf("%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f", 6., 0., 0., 0., 0., 0.);
	return (0);
}
