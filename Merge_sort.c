#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

int A[] = {31, 41, 59, 26, 41, 58};

// Function declarations
void merge_sort(int A[], int left, int right);
void merge(int A[], int left, int mid, int right);

// Linked List function declarations
struct Node* createNode(int data); // Creation of the node
void printList(struct Node* head); // Printing operation
void freeList(struct Node* head); // Freeing memory
struct Node* findMiddle(struct Node* head); // Finding middle of linked list
struct Node* mergeTwoSortedLists(struct Node* left, struct Node* right); // Merging two sorted linked lists
struct Node* mergeSortLinkedList(struct Node* head); // Main merge sort function for linked list

// Temporary array to hold merged result (needs proper size)
int B[100]; // Fixed size temporary array

// Merge Sort function
void merge_sort(int A[], int left, int right){
    if (left < right ){
        int mid = left + (right - left)/2;
        merge_sort(A, left, mid); // dividing into left half
        merge_sort(A, mid+1, right); // dividing into right half
        merge(A, left, mid, right); // merging the two halves
    }
}

// Merge function to merge two halves
void merge(int A[], int left, int mid, int right){
    int i = left; // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left; // Starting index to be sorted

    // Merge the two halves into temporary array B
    while (i <= mid && j <= right){ // Checking both subarrays have elements
        if (A[i] <= A[j]){ //Comparing elements of both subarrays
            B[k] = A[i]; // If left element is smaller, add it to B
            i++;
        }
        else{
            B[k] = A[j]; // If right element is smaller, add it to B
            j++;
        }
        k++;
    }

    // Copy remaining elements of left subarray, if any
    while (i <= mid){ 
        B[k] = A[i];
        i++;
        k++;
    }

    // Copy remaining elements of right subarray, if any
    while (j <= right){
        B[k] = A[j];
        j++;
        k++;
    }
    
    // Copy merged elements back to original array A
    for (int p = left; p <= right; p++){
        A[p] = B[p];
    }
}

// ========== LINKED LIST MERGE SORT IMPLEMENTATION ==========

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the linked list memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to find the middle of the linked list
// This divides the list into two halves
struct Node* findMiddle(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; // List has 0 or 1 node
    }
    
    struct Node* prev = NULL;
    struct Node* current = head;
    int count = 0;
    
    // First, count the total number of nodes
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    // Move to the middle node
    int middle = count / 2;
    for (int i = 0; i < middle; i++) {
        prev = current;
        current = current->next;
    }
    
    // Break the connection to split the list
    prev->next = NULL;
    
    return current; // Return the start of second half
}

// Function to merge two sorted linked lists
struct Node* mergeTwoSortedLists(struct Node* left, struct Node* right) {
    // Create a dummy node to simplify the merging process
    struct Node* dummy = createNode(0);
    struct Node* current = dummy;
    
    // Compare elements from both lists and merge
    while (left != NULL && right != NULL) {
        if (left->data <= right->data) {
            current->next = left;  // Link the smaller node
            left = left->next;     // Move to next node in left list
        } else {
            current->next = right; // Link the smaller node
            right = right->next;   // Move to next node in right list
        }
        current = current->next;   // Move current pointer
    }
    
    // Attach remaining nodes (if any)
    if (left != NULL) {
        current->next = left;
    }
    if (right != NULL) {
        current->next = right;
    }
    
    // Store the result and free dummy node
    struct Node* result = dummy->next;
    free(dummy);
    
    return result;
}

// Main merge sort function for linked list
struct Node* mergeSortLinkedList(struct Node* head) {
    // Base case: if list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Step 1: Find the middle and split the list into two halves
    struct Node* secondHalf = findMiddle(head);
    
    // Step 2: Recursively sort both halves
    struct Node* sortedLeft = mergeSortLinkedList(head);
    struct Node* sortedRight = mergeSortLinkedList(secondHalf);
    
    // Step 3: Merge the sorted halves
    return mergeTwoSortedLists(sortedLeft, sortedRight);
}

int main(){
    // ========== ARRAY MERGE SORT TEST ==========
    int n = sizeof(A)/sizeof(A[0]);
    printf("===ORIGINAL ARRAY===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    merge_sort(A, 0, n-1);

    printf("===ARRAY MERGE SORT===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    // ========== LINKED LIST MERGE SORT TEST ==========
    printf("\n===LINKED LIST MERGE SORT===\n");
    
    // Create a linked list: 64 -> 34 -> 25 -> 12 -> 22 -> 11 -> 90
    struct Node* head = createNode(64);
    head->next = createNode(34);
    head->next->next = createNode(25);
    head->next->next->next = createNode(12);
    head->next->next->next->next = createNode(22);
    head->next->next->next->next->next = createNode(11);
    head->next->next->next->next->next->next = createNode(90);
    
    printf("Original linked list: ");
    printList(head);
    
    // Sort the linked list using merge sort
    head = mergeSortLinkedList(head);
    
    printf("Sorted linked list:   ");
    printList(head);
    
    // Free the memory
    freeList(head);
    
    // ========== LEETCODE 88: Merge Sorted Array ==========
    printf("\n=== LEETCODE 88: Merge Sorted Array ===\n");
    
    // Test case 1: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    int nums1_1[] = {1, 2, 3, 0, 0, 0};
    int nums2_1[] = {2, 5, 6};
    int m1 = 3, n1 = 3;
    
    printf("Before merge: nums1 = ");
    for (int i = 0; i < 6; i++) printf("%d ", nums1_1[i]);
    printf(", nums2 = ");
    for (int i = 0; i < 3; i++) printf("%d ", nums2_1[i]);
    printf("\n");
    
    // Merge logic (backward merging)
    int i = m1 - 1;
    int j = n1 - 1;
    int k = m1 + n1 - 1;
    
    while (i >= 0 && j >= 0) {
        if (nums1_1[i] > nums2_1[j]) {
            nums1_1[k] = nums1_1[i];
            i--;
        } else {
            nums1_1[k] = nums2_1[j];
            j--;
        }
        k--;
    }
    
    while (j >= 0) {
        nums1_1[k] = nums2_1[j];
        j--;
        k--;
    }
    
    printf("After merge:  nums1 = ");
    for (int i = 0; i < 6; i++) printf("%d ", nums1_1[i]);
    printf("\n");
    
    return 0;
}