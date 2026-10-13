#include "apc.h"

int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
    {
        return 0;
    }

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*head)->prev = new;
        *head = new;
    }

    return 1;
}

int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
    {
        return 0;
    }

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*tail)->next = new;
        *tail = new;
    }

    return 1;
}