#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"
#include <limits.h>

// For printf

static double PRECISION = 0.000001;
static int MAX_NUMBER_STRING_SIZE = 32;

/**
 * Double to ASCII
 */
char * dtoa(char *s, double n) {
    // handle special cases
    if (isnan(n)) {
        strcpy(s, "nan");
    } else if (isinf(n)) {
        strcpy(s, "inf");
    } else if (n == 0.0) {
        strcpy(s, "0");
    } else {
        int digit, m, m1;
        char *c = s;
        int neg = (n < 0);
        if (neg)
            n = -n;
        // calculate magnitude
        m = log10(n);
        int useExp = (m >= 14 || (neg && m >= 9) || m <= -9);
        if (neg)
            *(c++) = '-';
        // set up for scientific notation
        if (useExp) {
            if (m < 0)
               m -= 1.0;
            n = n / pow(10.0, m);
            m1 = m;
            m = 0;
        }
        if (m < 1.0) {
            m = 0;
        }
        // convert the number
        while (n > PRECISION || m >= 0) {
            double weight = pow(10.0, m);
            if (weight > 0 && !isinf(weight)) {
                digit = floor(n / weight);
                n -= (digit * weight);
                *(c++) = '0' + digit;
            }
            if (m == 0 && n > 0)
                *(c++) = '.';
            m--;
        }
        if (useExp) {
            // convert the exponent
            int i, j;
            *(c++) = 'e';
            if (m1 > 0) {
                *(c++) = '+';
            } else {
                *(c++) = '-';
                m1 = -m1;
            }
            m = 0;
            while (m1 > 0) {
                *(c++) = '0' + m1 % 10;
                m1 /= 10;
                m++;
            }
            c -= m;
            for (i = 0, j = m-1; i<j; i++, j--) {
                // swap without temporary
                c[i] ^= c[j];
                c[j] ^= c[i];
                c[i] ^= c[j];
            }
            c += m;
        }
        *(c) = '\0';
    }
    return s;
}

void	ft_print_bits(long double n) 
{ 

	unsigned char *test = (unsigned char *)&n;
	unsigned i = CHAR_BIT * sizeof(n);
	while (--i + 1 > 0)
	{
		if (test[i/CHAR_BIT] & (1U << (i % CHAR_BIT)))
		{
			printf("i = %u\n", i);
			ft_putstr("1");
		}
		else
			ft_putstr("0");
		if (i % 8 == 0)
			ft_putstr(" ");
	}
	ft_putstr("\n");
}
int		main(void)
{
	unsigned long long int lon = 1234567890123456789;
	double	doub;
	double	doub2;
	double	doub3;
	double	doub4;
	double	doub5 = 1000000;
	char *str2 = NULL;
	double	doub6;

	doub6 = 0;
	doub5 *= doub5 * doub5;
	doub5 *= doub5 * doub5;
	doub5 *= doub5 * doub5;
	doub5 *= doub5 * doub5;
	doub5 *= doub5 * doub5;
	doub5 *= doub5 * doub5;
	doub4 = -10;
	doub3 = -56461.6551616465;
	doub = -0;
	doub6 /= doub;
	doub4 *= doub;
	doub2 = 165456.561165;

	//ft_print_bits(-0.0);
	ft_printf("\nFt_Printf : | %-20.5lf |", 0.0);
	printf("\nPrintf :    | %-20.5lf |\n", 0.0);
	return (0);
}
