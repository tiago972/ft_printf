#include "../includes/ft_printf.h"
#include <stdio.h>

int		main()
{	
	printf("@moulitest: %#.o %#.0o", 0, 0);
	printf("\n");
	ft_printf("@moulitest: %#.o %#.0o", 0, 0);
	return (0);
}
