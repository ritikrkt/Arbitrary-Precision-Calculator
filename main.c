#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *headR = NULL;
    Dlist *tailR = NULL;
    
    int sign1;
    int sign2;
    int operation;
    int comparison;
    int result_sign;


    if (argc != 4)
    {
        printf("Usage: ./apc operand1 operator operand2\n");
        return 0;
    }

    if (!validate_operand(argv[1]))
    {
        printf("Invalid operand 1\n");
        return 0;
    }

    if (!validate_operator(argv[2][0]))
    {
        printf("Invalid operator\n");
        return 0;
    }

    if (!validate_operand(argv[3]))
    {
        printf("Invalid operand 2\n");
        return 0;
    }
    
    sign1 = get_sign(argv[1]);
    sign2 = get_sign(argv[3]);

    store_operand(argv[1], &head1, &tail1);
    store_operand(argv[3], &head2, &tail2);

    operation = handle_signs(sign1, sign2, argv[2][0]);
    comparison = compare_lists(head1, head2);
    result_sign = get_result_sign(sign1, sign2, argv[2][0], comparison);
    
    
    if (operation == 1)
{
    addition(tail1, tail2, &headR, &tailR);
}
else if (operation == 2)
{
    if (comparison >= 0)
    {
        subtraction(tail1, tail2, &headR, &tailR);
    }
    else
    {
        subtraction(tail2, tail1, &headR, &tailR);
    }
}
    else if (operation == 3)
    {
        multiplication(tail1, tail2, &headR, &tailR);
    }

    else if (operation == 4)
{
    if (!division(tail1, tail2, &headR, &tailR))
    {
        printf("Error: Division by zero\n");

        delete_list(&head1, &tail1);
        delete_list(&head2, &tail2);

        return 0;
    }
}

    remove_leading_zeros(&headR, &tailR);
    
    printf("Operand 1 : ");
    print_list(head1);

    printf("Operand 2 : ");
    print_list(head2);

    printf("Result : ");

    if (result_sign == -1 && comparison != 0)
    {
    printf("-");
    }

    print_list(headR);


    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&headR, &tailR);

    return 0;
}