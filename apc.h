#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

/* Insert functions */
int insert_at_first(Dlist **head, Dlist **tail, int data);
int insert_at_last(Dlist **head, Dlist **tail, int data);

/* Delete functions */
int delete_list(Dlist **head, Dlist **tail);

/* Print function */
void print_list(Dlist *head);

/* Validation */
int validate_operator(char operator);
int validate_operand(char *operand);
int store_operand(char *operand, Dlist **head, Dlist **tail);

int addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist *tail1, Dlist *tail2,Dlist **headR, Dlist **tailR);
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
int multiply_by_digit(Dlist *tail, int digit, Dlist **headR, Dlist **tailR);
int division(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

int remove_leading_zeros(Dlist **head, Dlist **tail);
int compare_lists(Dlist *head1, Dlist *head2);
int get_sign(char *operand);
int handle_signs(int sign1, int sign2, char operator);
int get_result_sign(int sign1, int sign2, char operator, int comparison);
int append_zeros(Dlist **head, Dlist **tail, int count);
int copy_list(Dlist *head, Dlist **new_head, Dlist **new_tail);
int increment_quotient(Dlist **head, Dlist **tail);
int is_zero(Dlist *head);

#endif