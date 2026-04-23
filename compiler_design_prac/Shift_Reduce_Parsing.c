#include <stdio.h>
#include <string.h>

char stack[50], input[50];
char prod_lhs[10], prod_rhs[10][20];
int top = -1, n;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void reduce(char *remaining_input) {
    for (int i = 0; i < n; i++) {
        int len = strlen(prod_rhs[i]);

        if (top + 1 >= len) {
            if (strncmp(&stack[top - len + 1], prod_rhs[i], len) == 0) {

                // Perform reduction
                stack[top - len + 1] = prod_lhs[i];
                top = top - len + 1;
                stack[top + 1] = '\0';

                // Print in table format
                printf("%s\t%s\tReduce %c->%s\n",
                       stack, remaining_input, prod_lhs[i], prod_rhs[i]);

                i = -1; // restart checking
            }
        }
    }
}

int main() {
    int i = 0;
    char temp[20];

    printf("Enter the Number of Productions: ");
    scanf("%d", &n);

    printf("Enter the productions (E->E+E format):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        prod_lhs[i] = temp[0];
        strcpy(prod_rhs[i], temp + 3);
    }

    printf("Enter the input String: ");
    scanf("%s", input);

    printf("\nStack\tInput\tAction\n");

    while (input[i] != '\0') {
        push(input[i]);

        // SHIFT action
        printf("%s\t%s\tShift\n", stack, input + i + 1);

        // REDUCE actions (if possible)
        reduce(input + i + 1);

        i++;
    }

    // Final reductions
    reduce("");

    if (top == 0 && stack[top] == prod_lhs[0])
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}