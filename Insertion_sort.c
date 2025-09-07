#include <stdio.h>
#include <stdlib.h>

int A[] = {31, 41, 59, 26, 41, 58};

// Definition for singly-linked list (for LeetCode 147)
struct ListNode {
    int val;
    struct ListNode *next;
};

// INSERTION SORT ALGORITHM
void insertion_sort(int A[], int n) {
    for (int i =1 ; i < n; i++)
    {
        int temp = A[i];
        int j = i-1;
        while (j >= 0 && A[j] > temp)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}

// LINEAR SEARCH ALGORITHM
int linear_search(int A[], int n){
    int v = 41;
    for (int i = 0; i < n; i++) {
        if (A[i] == v) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

//  Consider the problem of adding two n-bit binary integers, stored in two n-element arrays A and B. The sum of the two integers should be stored in binary form in  an .n C1/-element array C. State the problem formally and write pseudocode for adding the two integers.

// Function to convert decimal to binary and store in array
void decimal_to_binary(int decimal, int binary_array[], int n) {
    // Initialize array with zeros
    for (int i = 0; i < n; i++) {
        binary_array[i] = 0;
    }
    
    // Convert decimal to binary (store from right to left)
    int index = n - 1;
    while (decimal > 0 && index >= 0) {
        binary_array[index] = decimal % 2;
        decimal = decimal / 2;
        index--;
    }
}

// Function to print binary array
void print_binary(int binary_array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", binary_array[i]);
    }
    printf("\n");
}

// Function to add two binary numbers
void binary_addition(int A[], int B[], int C[], int n) {
    int carry = 0;
    
    // Add from right to left (least significant bit first)
    for (int i = n - 1; i >= 0; i--) {
        int sum = A[i] + B[i] + carry;
        C[i + 1] = sum % 2;  // Store result bit
        carry = sum / 2;     // Calculate carry
    }
    C[0] = carry;  // Store final carry in the leftmost position
}

// Test with decimal values
int decimal_A = 10;  // 10 in decimal = 1010 in binary
int decimal_B = 11;  // 11 in decimal = 1011 in binary 

// LEETCODE 147: Insertion Sort List
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head; // If list is empty or has one node, it's already sorted
    
    // Create a dummy node to simplify insertion
    struct ListNode dummy;
    dummy.next = NULL; // Fake head of the sorted list
    
    struct ListNode* current = head; // Current node to be inserted
    
    while (current) {
        struct ListNode* next = current->next;  // Save next node
        
        // Find the correct position to insert current node
        struct ListNode* prev = &dummy; // prev points to the dummy node

        while (prev->next && prev->next->val < current->val) { // prev->next->val is the value of Unsorted list node & current->val is the value of Sorted list node
            prev = prev->next; // Move prev forward in the sorted list
        }
        
        // Insert current node after prev
        current->next = prev->next; // Connecting current to next in sorted list
        prev->next = current; // Connecting prev to current in the sorted list
        
        current = next;  // Move to next node 
    }
    
    return dummy.next; // Return the sorted list, which starts at dummy.next
} 

// Helper function to create a new ListNode
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print linked list
void printList(struct ListNode* head) { // head is a pointer to the first node
    struct ListNode* current = head; // current is used to traverse the list
    while (current) {
        printf("%d", current->val); // Print current node's value
        if (current->next) printf(" -> "); // Print arrow if not the last node
        current = current->next; // Move current to the next node
    }
    printf("\n");
}

// Helper function to free linked list memory
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
} 


int main() {
    int n = sizeof(A) / sizeof(A[0]);
    
    printf("Original array: ");
    // print_array(A, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    insertion_sort(A, n);
    
    printf("Array sorted in ascending order: \n");
    // print_array(A, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Decreasing order
    printf("Array sorted in decreasing order: \n");
    for (int i = n -1; i >= 0; i--) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("\n");
    
    // Linear search 
    printf("=== LINEAR SEARCH ===\n");
    int index = linear_search(A, n);
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found\n");
    }
    printf("\n");
    
    // Binary Addition Demo
    printf("=== BINARY ADDITION  ===\n");
    int n_bits = 4;  // Using 4-bit binary numbers
    int binary_A[4], binary_B[4], binary_C[5];  // C needs n+1 bits
    
    // Convert decimal to binary
    decimal_to_binary(decimal_A, binary_A, n_bits);
    decimal_to_binary(decimal_B, binary_B, n_bits);
    
    printf("Decimal A = %d, Binary A = ", decimal_A);
    print_binary(binary_A, n_bits);
    
    printf("Decimal B = %d, Binary B = ", decimal_B);
    print_binary(binary_B, n_bits);
    
    // Perform binary addition
    binary_addition(binary_A, binary_B, binary_C, n_bits);
    
    printf("Binary Sum = ");
    print_binary(binary_C, n_bits + 1);
    
    // Convert result back to decimal for verification
    int result_decimal = 0;
    for (int i = 0; i < n_bits + 1; i++) {
        result_decimal = result_decimal * 2 + binary_C[i];
    }
    printf("Decimal Sum = %d (Verification: %d + %d = %d)\n", 
           result_decimal, decimal_A, decimal_B, decimal_A + decimal_B);
    
    // LeetCode 147: Insertion Sort List Demo
    printf("\n=== LEETCODE 147: INSERTION SORT LIST ===\n");
    
    // Create a test linked list: 4 -> 2 -> 1 -> 3
    struct ListNode* head = createNode(4);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);
    
    printf("Original linked list: ");
    printList(head);
    
    // Sort the linked list
    struct ListNode* sortedHead = insertionSortList(head);
    
    printf("Sorted linked list: ");
    printList(sortedHead);
    
    // Free memory
    freeList(sortedHead);

    return 0;
}