#include <stdio.h>
#include <stdlib.h>

void merge_three(int a[], int l, int m1, int m2, int r) {
    int n1 = m1 - l + 1;
    int n2 = m2 - m1;
    int n3 = r - m2;
    int i = l, j = m1 + 1, k = m2 + 1;
    int *tmp = (int*)malloc((r - l + 1) * sizeof(int));
    int idx = 0;
    while ((i <= m1) || (j <= m2) || (k <= r)) {
        int val;
        int avail1 = (i <= m1);
        int avail2 = (j <= m2);
        int avail3 = (k <= r);
        if (avail1 && (!avail2 || a[i] <= a[j]) && (!avail3 || a[i] <= a[k])) {
            val = a[i++];
        } else if (avail2 && (!avail1 || a[j] < a[i]) && (!avail3 || a[j] <= a[k])) {
            val = a[j++];
        } else {
            val = a[k++];
        }
        tmp[idx++] = val;
    }
    for (int t = 0; t < idx; t++) a[l + t] = tmp[t];
    free(tmp);
}

void three_way_sort(int a[], int l, int r) {
    if (l >= r) return;
    int third = (r - l) / 3;
    int m1 = l + third;
    int m2 = l + 2 * third + ((r - l) % 3 >= 1 ? 1 : 0);
    if (m1 < l) m1 = l;
    if (m2 < m1) m2 = m1;
    three_way_sort(a, l, m1);
    three_way_sort(a, m1 + 1, m2);
    three_way_sort(a, m2 + 1, r);
    merge_three(a, l, m1, m2, r);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) return 0;
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    three_way_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    free(a);
    return 0;
}
