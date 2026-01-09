#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int stack[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &stack[i]); //inserting in the stack

    printf("%d", stack[n - 1]); //printing the top element of the stack
    return 0;
}
