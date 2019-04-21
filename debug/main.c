#include "../includes/ft_printf.h"
#include <stdio.h>

int		main()
{
	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("@moulitest: %#.x %#.0x", 0, 0);
	return (0);
}
