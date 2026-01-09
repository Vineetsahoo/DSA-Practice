#include <stdio.h>

int CountDigitOccurrences(int l, int u, int x) {
    int count = 0;

    for (int i = l; i <= u; i++) {
        int num = i;

        if (num == 0 && x == 0)
            count++;

        while (num > 0) {
            if (num % 10 == x)
                count++;
            num /= 10;
        }
    }
    return count;
}

int main() {
    int l, u, x;
    scanf("%d", &l);
    scanf("%d", &u);
    scanf("%d", &x);

    printf("%d", CountDigitOccurrences(l, u, x));
    return 0;
}
