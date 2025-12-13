#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) return 0;

    int cap = 2 * n + 5;
    char **q = (char **)malloc(cap * sizeof(char *));
    if (!q) return 0;
    for (int i = 0; i < cap; ++i) {
        q[i] = (char *)malloc(64 * sizeof(char));
    }

    int front = 0, rear = 0;

    strcpy(q[rear], "1");
    rear = (rear + 1) % cap;

    for (int count = 0; count < n; ++count) {
        char curr[64];
        strcpy(curr, q[front]);
        front = (front + 1) % cap;

        printf("%s\n", curr);

        char temp0[64];
        char temp1[64];
        snprintf(temp0, sizeof(temp0), "%s0", curr);
        snprintf(temp1, sizeof(temp1), "%s1", curr);

        strcpy(q[rear], temp0);
        rear = (rear + 1) % cap;

        strcpy(q[rear], temp1);
        rear = (rear + 1) % cap;
    }

    for (int i = 0; i < cap; ++i) {
        free(q[i]);
    }
    free(q);
    return 0;
}
