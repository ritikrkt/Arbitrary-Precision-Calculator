#include "apc.h"

int copy_list(Dlist *tail, Dlist **new_head, Dlist **new_tail)
{
    while (tail != NULL)
    {
        insert_at_first(new_head, new_tail, tail->data);
        tail = tail->prev;
    }

    return 1;
}

int increment_quotient(Dlist **head, Dlist **tail)
{
    Dlist *temp = *tail;
    int carry = 1;
    int sum;

    while (temp != NULL && carry)
    {
        sum = temp->data + carry;

        temp->data = sum % 10;
        carry = sum / 10;

        temp = temp->prev;
    }

    if (carry)
    {
        insert_at_first(head, tail, carry);
    }

    return 1;
}

int is_zero(Dlist *head)
{
    while (head != NULL)
    {
        if (head->data != 0)
        {
            return 0;
        }

        head = head->next;
    }

    return 1;
}

int division(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *remainder_head = NULL;
    Dlist *remainder_tail = NULL;

    Dlist *sub_head = NULL;
    Dlist *sub_tail = NULL;

    Dlist *divisor_head = NULL;
    Dlist *divisor_tail = NULL;

    if (tail1 == NULL || tail2 == NULL)
    {
        return 0;
    }

    /* Copy dividend into remainder */
    copy_list(tail1, &remainder_head, &remainder_tail);

    /* Copy divisor */
    copy_list(tail2, &divisor_head, &divisor_tail);
    
    if (is_zero(divisor_head))
    {
        delete_list(&remainder_head, &remainder_tail);
        delete_list(&divisor_head, &divisor_tail);
        return 0;
    }

    /* Quotient starts from 0 */
    insert_at_last(headR, tailR, 0);

    while (compare_lists(remainder_head, divisor_head) >= 0)
    {
        sub_head = NULL;
        sub_tail = NULL;

        subtraction(remainder_tail, divisor_tail,
                    &sub_head, &sub_tail);

        delete_list(&remainder_head, &remainder_tail);

        remainder_head = sub_head;
        remainder_tail = sub_tail;

        remove_leading_zeros(&remainder_head, &remainder_tail);

        increment_quotient(headR, tailR);
    }

    remove_leading_zeros(headR, tailR);

    delete_list(&remainder_head, &remainder_tail);
    delete_list(&divisor_head, &divisor_tail);

    return 1;
}