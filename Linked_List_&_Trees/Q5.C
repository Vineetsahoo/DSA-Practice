#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node *root, char key) {
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

void inorder(struct Node *root, int *first) {
    if (root == NULL) return;
    inorder(root->left, first);
    if (!*first) printf(" ");
    printf("%c", root->data);
    *first = 0;
    inorder(root->right, first);
}

void preorder(struct Node *root, int *first) {
    if (root == NULL) return;
    if (!*first) printf(" ");
    printf("%c", root->data);
    *first = 0;
    preorder(root->left, first);
    preorder(root->right, first);
}

void postorder(struct Node *root, int *first) {
    if (root == NULL) return;
    postorder(root->left, first);
    postorder(root->right, first);
    if (!*first) printf(" ");
    printf("%c", root->data);
    *first = 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    struct Node *root = NULL;
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c);
        root = insert(root, c);
    }
    int first;
    first = 1;
    inorder(root, &first);
    printf("\n");
    first = 1;
    preorder(root, &first);
    printf("\n");
    first = 1;
    postorder(root, &first);
    return 0;
}
