#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    if (head == NULL) return 0;
    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *prevSlow = NULL;
    while (fast != NULL && fast->next != NULL) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == NULL) {
        if (prevSlow != NULL) {
            printf("%d %d", prevSlow->data, slow->data);
        } else {
            printf("%d", slow->data);
        }
    } else {
        printf("%d", slow->data);
    }
    return 0;
}
