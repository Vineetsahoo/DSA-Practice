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
    int M, N;
    if (scanf("%d %d", &M, &N) != 2) return 0;
    if (M <= 0) return 0;
    int *A1 = (int*)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) scanf("%d", &A1[i]);
    int *A2 = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) scanf("%d", &A2[i]);
    int *vis = (int*)calloc(M, sizeof(int));
    int first = 1;
    for (int j = 0; j < N; j++) {
        int key = A2[j];
        for (int i = 0; i < M; i++) {
            if (!vis[i] && A1[i] == key) {
                if (!first) printf(" ");
                printf("%d", A1[i]);
                first = 0;
                vis[i] = 1;
            }
        }
    }
    int rest_count = 0;
    int *rest = (int*)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        if (!vis[i]) rest[rest_count++] = A1[i];
    }
    qsort(rest, rest_count, sizeof(int), cmp_int);
    for (int i = 0; i < rest_count; i++) {
        if (!first) printf(" ");
        printf("%d", rest[i]);
        first = 0;
    }
    if (M >= 0) printf(" ");
    free(A1);
    free(A2);
    free(vis);
    free(rest);
    return 0;
}
