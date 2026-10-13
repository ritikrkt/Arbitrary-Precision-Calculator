#include "apc.h"

int get_sign(char *operand)
{
    if (operand[0] == '-')
    {
        return -1;
    }

    return 1;
}

int handle_signs(int sign1, int sign2, char operator)
{
    if (operator == '+')
    {
        if (sign1 == sign2)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    if (operator == '-')
    {
        if (sign1 != sign2)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    if (operator == 'x')
    {
        return 3;
    }
    if (operator == '/')
    {
        return 4;
    }

    return 0;
}

int get_result_sign(int sign1, int sign2, char operator, int comparison)
{
    if (operator == '+')
    {
        if (sign1 == sign2)
        {
            return sign1;
        }

        if (comparison >= 0)
        {
            return sign1;
        }
        else
        {
            return sign2;
        }
    }

    if (operator == '-')
    {
        if (sign1 != sign2)
        {
            return sign1;
        }

        if (comparison >= 0)
        {
            return sign1;
        }
        else
        {
            return -sign1;
        }
    }
    if (operator == 'x')
    {
        return sign1 * sign2;
    }

    if (operator == '/')
    {
        return sign1 * sign2;
    }

    return 1;
}