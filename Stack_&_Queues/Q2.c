
#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int a[n];

    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int stack[n];
    int top = -1;

    for (int i = 0; i < n; ++i) stack[++top] = a[i];

    while (top >= 0) {
        printf("%d", stack[top--]);
        if (top >= 0) printf(" ");
    }
    printf("\n");

    top = -1;
    for (int i = 0; i < n; ++i) stack[++top] = a[i];

    int pops = (n < 2) ? n : 2;
    while (pops-- > 0 && top >= 0) {
        top--;
    }

    while (top >= 0) {
        printf("%d", stack[top--]);
        if (top >= 0) printf(" ");
    }

    return 0;
}
