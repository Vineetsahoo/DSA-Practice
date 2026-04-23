#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n;
    char stmt[50];

    printf("Enter number of three address statements: ");
    scanf("%d", &n);

    printf("Enter the statements:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%s", stmt);

        char result, op1, op2, operator;

        // Case 1: Assignment (length = 3) → d=u
        if(strlen(stmt) == 3)
        {
            result = stmt[0];
            op1 = stmt[2];

            printf("LOAD %c\n", op1);
            printf("STORE %c\n", result);
        }
        // Case 2: Operation → t=a+b
        else if(strlen(stmt) == 5)
        {
            result = stmt[0];
            op1 = stmt[2];
            operator = stmt[3];
            op2 = stmt[4];

            printf("LOAD %c\n", op1);

            if(operator == '+')
                printf("ADD %c\n", op2);
            else if(operator == '-')
                printf("SUB %c\n", op2);
            else if(operator == '*')
                printf("MUL %c\n", op2);
            else if(operator == '/')
                printf("DIV %c\n", op2);

            printf("STORE %c\n", result);
        }
    }

    return 0;
}