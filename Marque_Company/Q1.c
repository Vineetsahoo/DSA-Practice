#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b, w;
} Sensor;

Sensor s[60000];
int parent[400], used[400];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[a] = b;
}

int cmp(const void *x, const void *y) {
    return ((Sensor*)x)->w - ((Sensor*)y)->w;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &s[i].a, &s[i].b, &s[i].w);

    qsort(s, m, sizeof(Sensor), cmp);

    int ans = 1e9;

    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            parent[k] = k;
            used[k] = 0;
        }

        int components = n;

        for (int j = i; j < m; j++) {
            int a = s[j].a;
            int b = s[j].b;

            used[a] = used[b] = 1;

            if (find(a) != find(b)) {
                unite(a, b);
                components--;
            }

            int ok = 1;
            for (int k = 0; k < n; k++)
                if (!used[k]) ok = 0;

            if (ok && components == 1) {
                int margin = s[j].w - s[i].w;
                if (margin < ans) ans = margin;
                break;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
