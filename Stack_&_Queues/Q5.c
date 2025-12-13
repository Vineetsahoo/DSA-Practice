/* Q5: Minimum cost to connect steel pieces (like ropes) */
#include <stdio.h>
#include <stdlib.h>

void heapify_up(long long heap[], int idx) {
    while (idx > 1) {
        int parent = idx / 2;
        if (heap[parent] <= heap[idx]) break;
        long long tmp = heap[parent];
        heap[parent] = heap[idx];
        heap[idx] = tmp;
        idx = parent;
    }
}

void heapify_down(long long heap[], int size, int idx) {
    while (1) {
        int left = 2 * idx;
        int right = 2 * idx + 1;
        int smallest = idx;

        if (left <= size && heap[left] < heap[smallest]) smallest = left;
        if (right <= size && heap[right] < heap[smallest]) smallest = right;

        if (smallest == idx) break;

        long long tmp = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = tmp;

        idx = smallest;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long *heap = (long long *)malloc((n * 2 + 5) * sizeof(long long));
    if (!heap) return 0;

    int size = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        scanf("%lld", &x);
        heap[++size] = x;
        heapify_up(heap, size);
    }

    long long totalCost = 0;

    while (size > 1) {
        long long a = heap[1];
        heap[1] = heap[size--];
        heapify_down(heap, size, 1);

        long long b = heap[1];
        heap[1] = heap[size--];
        heapify_down(heap, size, 1);

        long long cost = a + b;
        totalCost += cost;

        heap[++size] = cost;
        heapify_up(heap, size);
    }

    printf("%lld", totalCost);
    free(heap);
    return 0;
}
