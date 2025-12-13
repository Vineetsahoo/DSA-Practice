#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    if (N < 1) {
        printf("-1");
        return 0;
    }
    int total = N * N;
    int *buf = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) scanf("%d", &buf[i]);
    for (int r = 0; r < N; r++) {
        qsort(buf + r * N, N, sizeof(int), cmp_int);
    }
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (c) printf(" ");
            printf("%d", buf[r * N + c]);
        }
        if (r < N - 1) printf("\n");
    }
    free(buf);
    return 0;
}
