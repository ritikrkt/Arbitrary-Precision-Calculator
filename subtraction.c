#include "apc.h"

int subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    int borrow = 0;
    int diff;

    while (tail1 != NULL)
    {
        diff = tail1->data - borrow;

        if (tail2 != NULL)
        {
            diff = diff - tail2->data;
            tail2 = tail2->prev;
        }

        if (diff < 0)
        {
            diff = diff + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        insert_at_first(headR, tailR, diff);

        tail1 = tail1->prev;
    }

    return 1;
}

int compare_lists(Dlist *head1, Dlist *head2)
{
    int count1 = 0;
    int count2 = 0;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    if (count1 > count2)
    {
        return 1;
    }
    else if (count1 < count2)
    {
        return -1;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data > head2->data)
        {
            return 1;
        }
        else if (head1->data < head2->data)
        {
            return -1;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return 0;
}