#include <stdio.h>
#include <stdlib.h>

int str_len(char *);
float stack_pop(float *, int);
float a2f(char *);
float expr(int, char **);
void error(char *);

int str_len(char *string)
{
    int length = 0;
    for (; *string++; length++)
        ;
    return length;
}

void error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

float stack_pop(float nums[], int index)
{
    if (index < 0) 
        error("Syntax error");
    return nums[index];
}

float a2f(char *string)
{
    float num = 0, num_sign = 1.0;
    float factor;
    int decimal_digits = 0;
    int exp = 0, exp_sign = 1;

    /* check sign */
    if (*string == '+' || *string == '-') {
        /* at least one digit or a decimal should come after sign */
        if (*(string+1) != '.' && !(*(string+1) >= '0' && *(string+1) <= '9'))
            error("Invalid number");
        num_sign = (*string++ == '+')? 1.0: -1.0;
    }

    /* check valid number with '0' as beginner */
    if (*string == '0' && (*(string+1) != '\0' && *(string+1) != '.'))
        error("Invalid number");

    /* check valid number before decimal point */
    for (; *string >= '0' && *string <= '9'; string++) 
        num = num * 10 + *string - '0';

    /* analyze decimal part */
    if (*string == '.') 
        for (++string; *string >= '0' && *string <= '9'; string++, decimal_digits++) 
            num = num * 10 + *string - '0';

    /* analyze exponential part */
    if (*string == 'e' || *string == 'E') {
        string++;

        /* sign of exponential */
        if (*string == '-' || *string == '+')
            exp_sign = (*string++ == '+')? 1: -1;

        /* exponential can start with 0 only if it's 0 */
        if (*string == '0' && *(string+1) != '\0')
            error("Invalid exponential");

        for (; *string >= '0' && *string <= '9'; string++)
            exp = exp * 10 + *string - '0';
        exp *= exp_sign;
    }

    if (*string)
        error("Invalid number");

    exp -= decimal_digits; 
    factor = (exp >= 0)? 10.0: 0.1;
    exp *= (exp >= 0)? 1: -1;
    for (; exp--; num *= factor)
        ;
    return num * num_sign;
}

float expr(int total, char *operand[])
{
    float nums[total], op1, op2;
    int index = 0;

    for (; total--; operand++) {
        if ((str_len(*operand) == 1) && (**operand > '9' || **operand < '0')) {
            op2 = stack_pop(nums, --index);
            op1 = stack_pop(nums, --index);

            switch (**operand) {
                case '+':
                    nums[index++] = op1 + op2;
                    break;
                case '-':
                    nums[index++] = op1 - op2;
                    break;
                case '*':
                    nums[index++] = op1 * op2;
                    break;
                case '/':
                    nums[index++] = op1 / op2;
                    break;
                default:
                    fprintf(stderr, "Invalid operator: %c\n", **operand);
                    exit(1);
            }
        } else
            nums[index++] = a2f(*operand);
    }
    return nums[--index];
}

int main(int argc, char *argv[])
{
    float result = expr(--argc, ++argv);

    
    printf("Result: %f\n", result);

    return 0;
}

