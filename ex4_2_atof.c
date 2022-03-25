#include <stdio.h>

double atof(char num[])
{
    int i, e_sign = 1, e_digit;
    double number, power, sign = 1.0, e_power = 1.0;

    for (i = 0; num[i] == ' ' && num[i] == '\t'; i++)
        ;

    if (num[i] == '+' || num[i] == '-') /* check sign */
        sign = (num[i++] == '+')? 1.0: -1.0;

    for (number = 0.0; num[i] >= '0' && num[i] <= '9'; i++) /* digits before decimal */
        number = 10 * number + num[i] - '0';

    if (num[i] == '.') /* digits after decimal */
        for (++i, power = 1.0; num[i] >= '0' && num[i] <= '9'; i++, power *= 10)
             number = 10 * number + num[i] - '0';
    if (num[i] == 'e' || num[i] == 'E') {
        i++;
        if (num[i] == '+' || num[i] == '-')
            e_sign = (num[i++] == '+')? 1: -1;
        for (e_digit = 0; num[i] >= '0' && num[i] <= '9'; i++)
            e_digit = e_digit * 10 + num[i] - '0';
        for (; e_digit--; )
            e_power *= (e_sign > 0)? 10: 0.1;
    }
    return sign * number / power * e_power;
}

int main()
{
    char num[] = "+10.e-";
    
    printf("num: %s, atof: %f", num, atof(num));

    return 0;
}

