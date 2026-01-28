# include <stdio.h>
# include <stdlib.h>

// ========== BASIC LINKED LIST IMPLEMENTATION ==========

// Definition of a node in the singly linked list
typedef struct Node {
    int data; // Data part of the node
    struct Node* next; // Pointer to the next node
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    if (!newNode){ // Check for memory allocation failure
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data; // Set the data
    newNode->next = NULL; // Initialize next pointer to NULL

    return newNode; // Return the newly created node
}

// Function to append a node at the end of the linked list
void append(Node** head_ref, int new_data) {
    Node* newNode = createNode(new_data); // Create a new node
    if (*head_ref == NULL) { // If the list is empty, make the new node the head
        *head_ref = newNode;
        return;
    }
    Node* last = *head_ref; // Start from the head
    while (last->next != NULL) { // Traverse to the last node
        last = last->next; // Move to the next node
    }
     
    last->next = newNode; // Link the new node at the end
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) { // Traverse the list
        printf("%d -> ", node->data); // Print the data of the current node
        node = node->next; // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

// Function to free the linked list
void freeList(Node** head_ref) {
    Node* current = *head_ref;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head_ref = NULL;
}

// ========== LEETCODE 707: DESIGN LINKED LIST ==========

// MyLinkedList structure
typedef struct {
    Node* head; // Pointer to the head of the list
    int size;   // Size of the linked list
} MyLinkedList;

// Initialize the linked list
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (!obj) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

// Get the value of the index-th node in the linked list
// Return -1 if the index is invalid
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return -1; // Invalid index
    }
    
    Node* current = obj->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    return current->data;
}

// Add a node of value val before the first element of the linked list
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = createNode(val);
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

// Append a node of value val to the last element of the linked list
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = createNode(val);
    obj->size++;
    
    if (obj->head == NULL) {
        obj->head = newNode;
        return;
    }
    
    Node* current = obj->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Add a node of value val before the index-th node in the linked list
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) {
        return; // Invalid index (note: index == size is valid for append)
    }
    
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    
    Node* newNode = createNode(val);
    Node* current = obj->head;
    
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    obj->size++;
}

// Delete the index-th node in the linked list
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return; // Invalid index
    }
    
    if (index == 0) {
        Node* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
        obj->size--;
        return;
    }
    
    Node* current = obj->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    obj->size--;
}

// Free the linked list
void myLinkedListFree(MyLinkedList* obj) {
    Node* current = obj->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(obj);
}

// Main function to demonstrate the linked list operations
int main() {
    // ========== BASIC IMPLEMENTATION TEST ==========
    printf("========== BASIC LINKED LIST IMPLEMENTATION ==========\n\n");
    
    Node* head = NULL; // Initialize the head of the list

    append(&head, 1); // Append nodes to the list
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("Created Linked List: \n");
    printList(head); // Print the linked list
    
    freeList(&head);
    
    // ========== LEETCODE 707: DESIGN LINKED LIST TEST ==========
    printf("\n========== LEETCODE 707: DESIGN LINKED LIST ==========\n\n");
    
    MyLinkedList* obj = myLinkedListCreate();
    
    printf("Test Case 1: addAtHead operations\n");
    myLinkedListAddAtHead(obj, 7);
    myLinkedListAddAtHead(obj, 2);
    myLinkedListAddAtHead(obj, 1);
    printf("After adding 1, 2, 7 at head (in this order): ");
    Node* temp = obj->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Size: %d\n\n", obj->size);
    
    printf("Test Case 2: addAtIndex operations\n");
    myLinkedListAddAtIndex(obj, 3, 0);
    printf("After addAtIndex(3, 0): ");
    temp = obj->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Size: %d\n\n", obj->size);
    
    printf("Test Case 3: deleteAtIndex operations\n");
    myLinkedListDeleteAtIndex(obj, 2);
    printf("After deleteAtIndex(2): ");
    temp = obj->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Size: %d\n\n", obj->size);
    
    printf("Test Case 4: get operations\n");
    printf("Get value at index 0: %d\n", myLinkedListGet(obj, 0));
    printf("Get value at index 1: %d\n", myLinkedListGet(obj, 1));
    printf("Get value at index 2: %d\n", myLinkedListGet(obj, 2));
    printf("Get value at index 10 (invalid): %d\n\n", myLinkedListGet(obj, 10));
    
    printf("Test Case 5: addAtTail operations\n");
    myLinkedListAddAtTail(obj, 999);
    myLinkedListAddAtTail(obj, 888);
    printf("After addAtTail(999) and addAtTail(888): ");
    temp = obj->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Final Size: %d\n", obj->size);
    
    myLinkedListFree(obj);
    
    return 0;
}