#include <stdio.h>
#include <stdlib.h>

int main() {
    int R, C;
    if (scanf("%d %d", &R, &C) != 2) return 0;
    int total = R * C;
    int *mat = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) scanf("%d", &mat[i]);
    int *dist = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) dist[i] = -1;
    int maxq = total + 5;
    int *qr = (int*)malloc(maxq * sizeof(int));
    int *qc = (int*)malloc(maxq * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int idx = i * C + j;
            if (mat[idx] == 1) {
                dist[idx] = 0;
                qr[rear] = i;
                qc[rear] = j;
                rear++;
            }
        }
    }
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    while (front < rear) {
        int r = qr[front];
        int c = qc[front];
        front++;
        int d = dist[r * C + c];
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                int nidx = nr * C + nc;
                if (dist[nidx] == -1) {
                    dist[nidx] = d + 1;
                    qr[rear] = nr;
                    qc[rear] = nc;
                    rear++;
                }
            }
        }
    }
    int first = 1;
    for (int i = 0; i < total; i++) {
        if (!first) printf(" ");
        printf("%d", dist[i]);
        first = 0;
    }
    free(mat);
    free(dist);
    free(qr);
    free(qc);
    return 0;
}
