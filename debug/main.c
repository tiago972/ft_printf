#include "../includes/ft_printf.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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

int		main(void)
{
	char *str;
	int i = 0;
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
	doub3 = -56461.6551619465;
	doub = -0;
	doub6 /= doub;
	doub4 *= doub;
	doub2 = 165456.561165;
	str = (char*)malloc(sizeof(char) * 50);
	while (i < 49)
		str[i++] = 'A';
	str[i] = 0;
	/*
	** TEST DE %f
	*/
	printf("\nTEST DE f\n");
	/*ft_printf("\nFt_Printf : | %1000.505lf |", doub);
	printf("\nPrintf :    | %1000.505lf |\n", doub);
	ft_printf("\nFt_Printf : | %50.600lf |", doub);
	printf("\nPrintf :    | %50.600lf |\n", doub);*/
	ft_printf("\nFt_Printf : | %.700lf |", doub3);
	printf("\nPrintf :    | %.700lf |\n", doub3);
	/*ft_printf("\nFt_Printf : | %70.50lf |", doub2);
	printf("\nPrintf :    | %70.50lf |\n", doub2);
	ft_printf("\nFt_Printf : | %f |", doub);
	printf("\nPrintf :    | %f |\n", doub);
	ft_printf("\nFt_Printf : | %-5.1f |", doub3);
	printf("\nPrintf :    | %-5.1f |\n", doub3);
	ft_printf("\nFt_Printf : | %+012.1f |", doub2);
	printf("\nPrintf :    | %+012.1f |\n", doub2);
	ft_printf("\nFt_Printf : | %012.7lf |", doub);
	printf("\nPrintf :    | %012.7lf |\n", doub);
	ft_printf("\nFt_Printf : | %#.f |", doub);
	printf("\nPrintf :    | %#.f |\n", doub);
	ft_printf("\nFt_Printf : | %027.3f |", doub3);
	printf("\nPrintf :    | %027.3f |\n", doub3);
	ft_printf("\nFt_Printf : | %#2f |", doub2);
	printf("\nPrintf :    | %#2f |\n", doub2);
	ft_printf("\nFt_Printf : | %#60.30f |", doub4);
	printf("\nPrintf :    | %#60.30f |\n", doub4);
	ft_printf("\nFt_Printf : | %#+60.30f |", doub5);
	printf("\nPrintf :    | %#+60.30f |\n", doub5);
	ft_printf("\nFt_Printf : | %#.30F |", doub6);
	printf("\nPrintf :    | %#.30F |\n", doub6);
	doub2 *= doub2 * doub2 *doub2 *doub2;
	ft_printf("\nFt_Printf : | %#.30F |", doub2);
	printf("\nPrintf :    | %#.30F |\n", doub2);
	ft_printf("\nft_printf : %50v\n");
	ft_printf("\nft_printf : %50d\n", 50);*/
	free(str);
	return (0);
}
