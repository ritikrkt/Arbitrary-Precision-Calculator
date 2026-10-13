#include "apc.h"

int multiply_by_digit(Dlist *tail, int digit, Dlist **headR, Dlist **tailR)
{
    int carry = 0;
    int product;

    while (tail != NULL)
    {
        product = tail->data * digit + carry;

        insert_at_first(headR, tailR, product % 10);

        carry = product / 10;

        tail = tail->prev;
    }

    while (carry != 0)
    {
        insert_at_first(headR, tailR, carry % 10);
        carry = carry / 10;
    }

    return 1;
}

int append_zeros(Dlist **head, Dlist **tail, int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        insert_at_last(head, tail, 0);
    }

    return 1;
}

int multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp2 = tail2;

    Dlist *partial_head = NULL;
    Dlist *partial_tail = NULL;

    Dlist *sum_head = NULL;
    Dlist *sum_tail = NULL;

    int position = 0;

    if (tail1 == NULL || tail2 == NULL)
    {
        return 0;
    }

    while (temp2 != NULL)
    {
        partial_head = NULL;
        partial_tail = NULL;

        multiply_by_digit(tail1, temp2->data, &partial_head, &partial_tail);

        append_zeros(&partial_head, &partial_tail, position);

        if (sum_head == NULL)
        {
            sum_head = partial_head;
            sum_tail = partial_tail;
        }
        else
        {
        Dlist *new_sum_head = NULL;
        Dlist *new_sum_tail = NULL;

        addition(sum_tail, partial_tail, &new_sum_head, &new_sum_tail);

        delete_list(&sum_head, &sum_tail);
        delete_list(&partial_head, &partial_tail);

        sum_head = new_sum_head;
        sum_tail = new_sum_tail;
        }

        position++;
        temp2 = temp2->prev;
    }

    *headR = sum_head;
    *tailR = sum_tail;

    return 1;
}