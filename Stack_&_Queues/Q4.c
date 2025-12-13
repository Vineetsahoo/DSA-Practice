#include <stdio.h>
#include <string.h>

int main() {
    char s[1005];
    if (scanf("%s", s) != 1) return 0;

    int len = (int)strlen(s);
    char st[1005];
    int top = -1;

    for (int i = 0; i < len; ++i) {
        st[++top] = s[i];
    }

    while (top >= 0) {
        putchar(st[top--]);
    }

    return 0;
}
