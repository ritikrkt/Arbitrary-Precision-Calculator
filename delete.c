#include "apc.h"

int delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *tail = NULL;

    return 1;
}
int remove_leading_zeros(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    while (*head != NULL && (*head)->data == 0 && (*head)->next != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }

    if (*head == NULL)
    {
        *tail = NULL;
    }

    return 1;
}