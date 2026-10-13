#include "apc.h"

int addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    int carry = 0;
    int sum;

    while (tail1 != NULL || tail2 != NULL)
    {
        sum = carry;

        if (tail1 != NULL)
        {
            sum = sum + tail1->data;
            tail1 = tail1->prev;
        }

        if (tail2 != NULL)
        {
            sum = sum + tail2->data;
            tail2 = tail2->prev;
        }

        insert_at_first(headR, tailR, sum % 10);

        carry = sum / 10;
    }

    if (carry != 0)
    {
        insert_at_first(headR, tailR, carry);
    }

    return 1;
}