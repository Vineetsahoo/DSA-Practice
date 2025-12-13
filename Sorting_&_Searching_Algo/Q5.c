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
    if (N <= 0) {
        printf("0");
        return 0;
    }
    int *S = (int*)malloc(N * sizeof(int));
    int *E = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) scanf("%d %d", &S[i], &E[i]);
    int *uniq = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) uniq[i] = E[i];
    qsort(uniq, N, sizeof(int), cmp_int);
    int ucount = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 || uniq[i] != uniq[i-1]) uniq[ucount++] = uniq[i];
    }
    int best = 0;
    for (int ui = 0; ui < ucount; ui++) {
        int k = uniq[ui];
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (E[i] <= k && S[i] > k) cnt++;
        }
        if (cnt > best) best = cnt;
    }
    printf("%d", best);
    free(S);
    free(E);
    free(uniq);
    return 0;
}
