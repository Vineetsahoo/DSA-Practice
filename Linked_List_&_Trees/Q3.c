#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
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
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    int pos;
    scanf("%d", &pos);
    if (head != NULL && pos > 0) {
        if (pos == 1) {
            struct Node *temp = head;
            head = head->next;
            if (head != NULL) head->prev = NULL;
            free(temp);
        } else {
            struct Node *curr = head;
            int count = 1;
            while (curr != NULL && count < pos) {
                curr = curr->next;
                count++;
            }
            if (curr != NULL) {
                struct Node *p = curr->prev;
                struct Node *n = curr->next;
                if (p != NULL) p->next = n;
                if (n != NULL) n->prev = p;
                if (curr == tail) tail = p;
                free(curr);
            }
        }
    }
    struct Node *temp = head;
    int first = 1;
    while (temp != NULL) {
        if (!first) printf(" ");
        printf("%d", temp->data);
        first = 0;
        temp = temp->next;
    }
    return 0;
}
