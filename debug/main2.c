#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include "../libft/includes/libft.h"

typedef union test 
{
	float f;
	uint32_t t;
}			t_bits;

int		ft_iterative_power(int nb, int power)
{
	int		res = 1;

	if (power == 0)
		return (1);
	while (power > 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}

int		main()
{
	t_bits	test;
	float	a = 263.3;
	test.f = a;
	int		i = 31;
	int		j = 0;
	char	conv[32];
	char	res[1001];
	int		sign = 1;
	int		exponant = 0;

	while (i >= 0)
	{
		conv[j] = ((test.t >> i) & 1);
		j++;
		i--;
	}
	i = 0;
	while (i < 32)
	{
		printf("%d", conv[i]);
		i++;
	}
	printf("\n");
	if (conv[0] & 1)
		sign = -1;
	j = 8;
	i = 0;
	while (j > 0)
	{
		exponant += ft_iterative_power(2, i) * conv[j];
		i++;
		j--;
	}
	exponant = exponant - 127;
	printf("signe = %d, exponant = %d\n", sign, exponant);
	i = 0;
	j = 9;
	while (j <= 32)
	{
		res[i] = conv[j];
		i++;
		j++;
	}
	i = 0;
	unsigned char *convert;
	convert = (unsigned char *)ft_strnew(100000);
	ft_memcpy(convert, &a, sizeof(float));
	/*while (i < 23)
	{
		if (res[i] & 1)
			convert = &ed + '0';
		convert++;
		ed /= 2;
		i++;
	}*/
	while (i < 32)
	{
		printf("%c", convert[i]);
		i++;
	}
	ft_memdel(&convert);
	return (0);
}
