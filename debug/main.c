#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int		main(void)
{
    float nb = -77.2;

    ft_printf("%bf\n", nb);
	return (0);
}
