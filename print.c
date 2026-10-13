#include "apc.h"

void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d", head->data);

        if (head->next != NULL)
        {
            printf(" <-> ");
        }

        head = head->next;
    }

    printf("\n");
}