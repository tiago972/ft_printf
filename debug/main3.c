#include <stdio.h>
#include "../libft/includes/libft.h"

int		main()
{
	double long f = 14.45;
	char test[sizeof(double long)];
	int		i = 0;
	while (i < (int)sizeof(double long))
	{
		ft_memset(&test[i], &f++, 1);
		i++;
	}
	return (0);
}
