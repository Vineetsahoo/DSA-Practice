#include <stdio.h>

int freq[1000005];

int main() {
    int X;
    scanf("%d", &X);

    int arrows = 0;

    for (int i = 0; i < X; i++) {
        int h;
        scanf("%d", &h);

        if (freq[h] > 0) {
            freq[h]--;
            freq[h - 1]++;
        } else {
            arrows++;
            freq[h - 1]++;
        }
    }

    printf("%d\n", arrows);
    return 0;
}
