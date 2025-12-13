#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long a[n];
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

    long long nge[n];
    int st[n];
    int top = -1;

    for (int i = n - 1; i >= 0; --i) {
        while (top >= 0 && a[st[top]] <= a[i]) {
            top--;
        }
        if (top < 0) nge[i] = -1;
        else nge[i] = a[st[top]];

        st[++top] = i;
    }

    for (int i = 0; i < n; ++i) {
        printf("%lld %lld\n", a[i], nge[i]);
    }

    return 0;
}
