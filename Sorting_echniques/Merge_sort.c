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

// LEETCODE 21: Merge Two Sorted Lists
// This is exactly the same as the merge step in merge sort!
struct Node* mergeTwoLists(struct Node* list1, struct Node* list2) {
    // Create a dummy node to simplify the merging process
    struct Node* dummy = createNode(0);
    struct Node* current = dummy;
    
    // Compare elements from both lists and merge
    // This is identical to the merge step in array merge sort!
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            current->next = list1;  // Link the smaller node
            list1 = list1->next;    // Move to next node in list1
        } else {
            current->next = list2;  // Link the smaller node
            list2 = list2->next;    // Move to next node in list2
        }
        current = current->next;    // Move current pointer
    }
    
    // Attach remaining nodes (if any)
    // Just like copying remaining elements in array merge sort
    if (list1 != NULL) {
        current->next = list1;
    }
    if (list2 != NULL) {
        current->next = list2;
    }
    
    // Store the result and free dummy node
    struct Node* result = dummy->next;
    free(dummy);
    
    return result;
}

// LEETCODE 23: Merge K Sorted Lists
// This uses the DIVIDE AND CONQUER approach of merge sort!
// Approach 1: Naive - merge lists one by one (O(k*N) where N is total nodes)
struct Node* mergeKLists_naive(struct Node** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    
    struct Node* result = lists[0];
    
    // Merge each list with the result one by one
    for (int i = 1; i < listsSize; i++) {
        result = mergeTwoLists(result, lists[i]);
    }
    
    return result;
}

// LEETCODE 23: Merge K Sorted Lists - OPTIMIZED
// This uses DIVIDE AND CONQUER exactly like merge sort! (O(N log k))
struct Node* mergeKLists_divideConquer(struct Node** lists, int start, int end) {
    // Base cases
    if (start > end) return NULL;
    if (start == end) return lists[start];
    
    // Divide: Find the middle point (just like merge sort!)
    int mid = start + (end - start) / 2;
    
    // Conquer: Recursively merge left and right halves
    struct Node* left = mergeKLists_divideConquer(lists, start, mid);
    struct Node* right = mergeKLists_divideConquer(lists, mid + 1, end);
    
    // Combine: Merge the two halves (using our LeetCode 21 solution!)
    return mergeTwoLists(left, right);
}

// Wrapper function for LeetCode 23
struct Node* mergeKLists(struct Node** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    return mergeKLists_divideConquer(lists, 0, listsSize - 1);
}

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
    
    // ========== LEETCODE 21: MERGE TWO SORTED LISTS ==========
    printf("\n=== LEETCODE 21: MERGE TWO SORTED LISTS ===\n");
    
    // Test Case 1: list1 = [1,2,4], list2 = [1,3,4]
    // Expected output: [1,1,2,3,4,4]
    printf("Test Case 1:\n");
    
    // Create list1: 1 -> 2 -> 4
    struct Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);
    
    // Create list2: 1 -> 3 -> 4
    struct Node* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);
    
    printf("list1 = ");
    printList(list1);
    printf("list2 = ");
    printList(list2);
    
    struct Node* merged1 = mergeTwoLists(list1, list2);
    printf("Output = ");
    printList(merged1);
    printf("\n");
    
    // Test Case 2: list1 = [], list2 = []
    // Expected output: []
    printf("Test Case 2:\n");
    printf("list1 = []\n");
    printf("list2 = []\n");
    
    struct Node* merged2 = mergeTwoLists(NULL, NULL);
    printf("Output = ");
    if (merged2 == NULL) {
        printf("[]\n");
    } else {
        printList(merged2);
    }
    printf("\n");
    
    // Test Case 3: list1 = [], list2 = [0]
    // Expected output: [0]
    printf("Test Case 3:\n");
    printf("list1 = []\n");
    
    struct Node* list3 = createNode(0);
    printf("list2 = ");
    printList(list3);
    
    struct Node* merged3 = mergeTwoLists(NULL, list3);
    printf("Output = ");
    printList(merged3);
    
    // Free memory for LeetCode 21 test cases
    freeList(merged1);
    if (merged2 != NULL) freeList(merged2);
    freeList(merged3);
    
    // ========== LEETCODE 23: MERGE K SORTED LISTS ==========
    printf("\n=== LEETCODE 23: MERGE K SORTED LISTS ===\n");
    
    // Test Case 1: lists = [[1,4,5],[1,3,4],[2,6]]
    // Expected output: [1,1,2,3,4,4,5,6]
    printf("Test Case 1:\n");
    printf("Input: lists = [[1,4,5],[1,3,4],[2,6]]\n");
    
    // Create the k sorted lists
    const int numLists = 3;
    struct Node* lists[numLists];
    
    // List 1: 1 -> 4 -> 5
    lists[0] = createNode(1);
    lists[0]->next = createNode(4);
    lists[0]->next->next = createNode(5);
    
    // List 2: 1 -> 3 -> 4
    lists[1] = createNode(1);
    lists[1]->next = createNode(3);
    lists[1]->next->next = createNode(4);
    
    // List 3: 2 -> 6
    lists[2] = createNode(2);
    lists[2]->next = createNode(6);
    
    printf("The linked-lists are:\n");
    for (int i = 0; i < numLists; i++) {
        printf("  List %d: ", i + 1);
        printList(lists[i]);
    }
    
    // Method 1: Naive approach
    printf("\nUsing Naive Approach (merge one by one):\n");
    
    // Create copies for naive approach (since merging modifies the lists)
    struct Node* lists_copy1[numLists];
    lists_copy1[0] = createNode(1);
    lists_copy1[0]->next = createNode(4);
    lists_copy1[0]->next->next = createNode(5);
    
    lists_copy1[1] = createNode(1);
    lists_copy1[1]->next = createNode(3);
    lists_copy1[1]->next->next = createNode(4);
    
    lists_copy1[2] = createNode(2);
    lists_copy1[2]->next = createNode(6);
    
    struct Node* mergedNaive = mergeKLists_naive(lists_copy1, numLists);
    printf("Output (Naive): ");
    printList(mergedNaive);
    
    // Method 2: Divide and Conquer approach (like merge sort!)
    printf("\nUsing Divide & Conquer Approach (like merge sort):\n");
    
    // Create copies for divide and conquer approach
    struct Node* lists_copy2[numLists];
    lists_copy2[0] = createNode(1);
    lists_copy2[0]->next = createNode(4);
    lists_copy2[0]->next->next = createNode(5);
    
    lists_copy2[1] = createNode(1);
    lists_copy2[1]->next = createNode(3);
    lists_copy2[1]->next->next = createNode(4);
    
    lists_copy2[2] = createNode(2);
    lists_copy2[2]->next = createNode(6);
    
    struct Node* mergedDivideConquer = mergeKLists(lists_copy2, k);
    printf("Output (D&C): ");
    printList(mergedDivideConquer);
    
    // Test Case 2: Empty lists
    printf("\nTest Case 2:\n");
    printf("Input: lists = []\n");
    struct Node* mergedEmpty = mergeKLists(NULL, 0);
    printf("Output: ");
    if (mergedEmpty == NULL) {
        printf("[]\n");
    } else {
        printList(mergedEmpty);
    }
    
    // Test Case 3: Single empty list
    printf("\nTest Case 3:\n");
    printf("Input: lists = [[]]\n");
    struct Node* emptyList = NULL;
    struct Node* mergedSingleEmpty = mergeKLists(&emptyList, 1);
    printf("Output: ");
    if (mergedSingleEmpty == NULL) {
        printf("[]\n");
    } else {
        printList(mergedSingleEmpty);
    }
    
    // Free memory
    freeList(mergedNaive);
    freeList(mergedDivideConquer);
    
    return 0;
}