#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node *root, int key) {
    if (root == NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    struct Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    if (root == NULL) return 0;
    struct Node *queue[n + 5];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            struct Node *node = queue[front++];
            printf("%d", node->data);
            if (i < levelSize - 1) printf(" ");
            if (node->left != NULL) queue[rear++] = node->left;
            if (node->right != NULL) queue[rear++] = node->right;
        }
        if (front < rear) printf("\n");
    }
    return 0;
}
