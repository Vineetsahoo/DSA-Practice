#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long p[n];
    for (int i = 0; i < n; ++i) scanf("%lld", &p[i]);

    long long val_stack[n];
    int day_stack[n];
    int top = -1;
    int maxDays = 0;

    for (int i = 0; i < n; ++i) {
        int days = 0;

        while (top >= 0 && p[i] <= val_stack[top]) {
            if (day_stack[top] > days) days = day_stack[top];
            top--;
        }

        if (top < 0) {
            days = 0;
        } else {
            days += 1;
        }

        if (days > maxDays) maxDays = days;

        val_stack[++top] = p[i];
        day_stack[top] = days;
    }

    printf("%d", maxDays);
    return 0;
}
