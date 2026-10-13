#include "apc.h"

int validate_operator(char operator)
{
    if (operator == '+' || operator == '-' ||
        operator == 'x' || operator == '/' ||
        operator == '%')
    {
        return 1;
    }

    return 0;
}

int validate_operand(char *operand)
{
    int i = 0;

    if (operand[0] == '\0')
    {
        return 0;
    }

    if (operand[0] == '-' || operand[0] == '+')
    {
        i = 1;
    }

    if (operand[i] == '\0')
    {
        return 0;
    }

    while (operand[i] != '\0')
    {
        if (operand[i] < '0' || operand[i] > '9')
        {
            return 0;
        }

        i++;
    }

    return 1;
}

int store_operand(char *operand, Dlist **head, Dlist **tail)
{
    int i = 0;

    if (operand[0] == '-' || operand[0] == '+')
    {
        i = 1;
    }

    while (operand[i] != '\0')
    {
        insert_at_last(head, tail, operand[i] - '0');
        i++;
    }

    return 1;
}