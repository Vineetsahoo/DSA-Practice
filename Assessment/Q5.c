#include <stdio.h>

int main() {
    int n, found = 0, key;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("%d: Yes", key);
    else
        printf("%d: No", key);

    return 0;
}
