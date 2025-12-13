#include <stdio.h>

int main() {
    int n, m, q, p, r, k;
    if (scanf("%d %d %d %d %d %d", &n, &m, &q, &p, &r, &k) != 6) return 0;

    int freeCars = n;
    int museum = m;
    int gate = q;
    int done = 0;

    int busy[n];
    int busy_count = 0;

    for (int t = 0; t <= k; ++t) {
        if (t > 0 && r > 0 && (t % r == 0) && museum > 0) {
            museum--;
            gate++;
        }

        int new_busy_count = 0;
        for (int i = 0; i < busy_count; ++i) {
            if (busy[i] == t) {
                freeCars++;
                done++;
            } else {
                busy[new_busy_count++] = busy[i];
            }
        }
        busy_count = new_busy_count;

        if (t < k) {
            while (freeCars > 0 && gate > 0 && busy_count < n) {
                freeCars--;
                gate--;
                busy[busy_count++] = t + p;
            }
        }
    }

    printf("%d %d %d %d", freeCars, done, museum, gate);
    return 0;
}
