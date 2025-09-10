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

// LEETCODE 35: Search Insert Position (Using Insertion Sort Concept)
int searchInsert(int nums[], int n, int target) {
    // Approach 1: Linear search (similar to insertion sort's position finding)
    for (int i = 0; i < n; i++) {
        if (nums[i] >= target) {
            return i; // Found position where target should be inserted
        }
    }
    return -1; // Insert at the end if target is larger than all elements
}

// LEETCODE 704: Binary Search (Optimized version of insertion sort's position finding)
int search(int nums[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Find middle position
        
        if (nums[mid] == target) {
            return mid; // Found target at mid position
        }
        else if (nums[mid] < target) {
            left = mid + 1; // Target is in right half
        }
        else {
            right = mid - 1; // Target is in left half
        }
    }
    
    return -1; // Target not found
}

// LEETCODE 704: Linear Search version (similar to insertion sort logic)
int search_linear(int nums[], int n, int target) {
    // This is similar to how insertion sort finds position
    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {
            return i; // Found target
        }
    }
    return -1; // Target not found
}

// LEETCODE 278: First Bad Version - API function (simulated)
// This simulates the isBadVersion API that LeetCode provides
int bad_version = 4; // Let's say version 4 is the first bad version

// Forward declaration for LeetCode compatibility
int isBadVersion(int version);

// Implementation of isBadVersion (this would be provided by LeetCode)
int isBadVersion(int version) {
    return version >= bad_version;
}

// LEETCODE 278: First Bad Version (LeetCode Compatible Version)
int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (isBadVersion(mid)) {
            right = mid; // First bad version is at mid or before mid
        } else {
            left = mid + 1; // First bad version is after mid
        }
    }
    
    return left; // left will be the first bad version
}

// LEETCODE 278: Linear Search version (similar to insertion sort logic)
int firstBadVersion_linear(int n) {
    // This is similar to how insertion sort finds the correct position
    for (int i = 1; i <= n; i++) {
        if (isBadVersion(i)) {
            return i; // Found first bad version
        }
    }
    return n; // All versions are good (shouldn't happen according to problem)
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
    
    while (current != NULL) {
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

// LEETCODE 148: Sort List (Same algorithm as 147, different function name)
struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head; // If list is empty or has one node, it's already sorted
    
    // Create a dummy node to simplify insertion
    struct ListNode dummy;
    dummy.next = NULL; // Fake head of the sorted list
    
    struct ListNode* current = head; // Current node to be inserted
    
    while (current != NULL) {
        struct ListNode* next = current->next;  // Save next node
        
        // Find the correct position to insert current node
        struct ListNode* prev = &dummy; // prev points to the dummy node

        while (prev->next && prev->next->val < current->val) { // Find insertion position
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
    
    // LeetCode 35: Search Insert Position Demo
    printf("\n=== LEETCODE 35: SEARCH INSERT POSITION ===\n");
    
    // Test case 1: Array = [1,3,5,6], target = 5
    int nums1[] = {1, 3, 5, 6};
    int nums1_size = sizeof(nums1)/sizeof(nums1[0]);
    int target1 = 5;
    
    printf("Array: [");
    for (int i = 0; i < nums1_size; i++) {
        printf("%d", nums1[i]);
        if (i < nums1_size - 1) printf(", ");
    }
    printf("], Target: %d\n", target1);
    
    int pos1 = searchInsert(nums1, nums1_size, target1);
    printf("Insert position: %d\n", pos1);
    
    // Test case 2: Array = [1,3,5,6], target = 2
    int target2 = 2;
    printf("\nArray: [");
    for (int i = 0; i < nums1_size; i++) {
        printf("%d", nums1[i]);
        if (i < nums1_size - 1) printf(", ");
    }
    printf("], Target: %d\n", target2);
    
    int pos2 = searchInsert(nums1, nums1_size, target2);
    printf("Insert position: %d\n", pos2);
    
    // Test case 3: Array = [1,3,5,6], target = 7
    int target3 = 7;
    printf("\nArray: [");
    for (int i = 0; i < nums1_size; i++) {
        printf("%d", nums1[i]);
        if (i < nums1_size - 1) printf(", ");
    }
    printf("], Target: %d\n", target3);
    
    int pos3 = searchInsert(nums1, nums1_size, target3);
    printf("Insert position: %d\n", pos3);
    
    // LeetCode 704: Binary Search Demo
    printf("\n=== LEETCODE 704: BINARY SEARCH ===\n");
    
    // Test case 1: Array = [-1,0,3,5,9,12], target = 9
    int search_nums1[] = {-1, 0, 3, 5, 9, 12};
    int search_size1 = sizeof(search_nums1)/sizeof(search_nums1[0]);
    int search_target1 = 9;
    
    printf("Array: [");
    for (int i = 0; i < search_size1; i++) {
        printf("%d", search_nums1[i]);
        if (i < search_size1 - 1) printf(", ");
    }
    printf("], Target: %d\n", search_target1);
    
    int result1 = search(search_nums1, search_size1, search_target1);
    printf("Binary search result: %d\n", result1);
    
    int result1_linear = search_linear(search_nums1, search_size1, search_target1);
    printf("Linear search result: %d\n", result1_linear);
    
    // Test case 2: Array = [-1,0,3,5,9,12], target = 2
    int search_target2 = 2;
    printf("\nArray: [");
    for (int i = 0; i < search_size1; i++) {
        printf("%d", search_nums1[i]);
        if (i < search_size1 - 1) printf(", ");
    }
    printf("], Target: %d\n", search_target2);
    
    int result2 = search(search_nums1, search_size1, search_target2);
    printf("Binary search result: %d\n", result2);
    
    int result2_linear = search_linear(search_nums1, search_size1, search_target2);
    printf("Linear search result: %d\n", result2_linear);
    
    // LeetCode 278: First Bad Version Demo
    printf("\n=== LEETCODE 278: FIRST BAD VERSION ===\n");
    
    // Test case 1: n = 5, first bad version = 4
    printf("Total versions: 5, First bad version: %d\n", bad_version);
    printf("Testing versions: ");
    for (int i = 1; i <= 5; i++) {
        printf("v%d:%s ", i, isBadVersion(i) ? "bad" : "good");
    }
    printf("\n");
    
    int first_bad1 = firstBadVersion(5);
    printf("Binary search result: %d\n", first_bad1);
    
    int first_bad1_linear = firstBadVersion_linear(5);
    printf("Linear search result: %d\n", first_bad1_linear);
    
    // Test case 2: Let's change the bad version
    bad_version = 1; // Now version 1 is the first bad
    printf("\nTotal versions: 3, First bad version: %d\n", bad_version);
    printf("Testing versions: ");
    for (int i = 1; i <= 3; i++) {
        printf("v%d:%s ", i, isBadVersion(i) ? "bad" : "good");
    }
    printf("\n");
    
    int first_bad2 = firstBadVersion(3);
    printf("Binary search result: %d\n", first_bad2);
    
    int first_bad2_linear = firstBadVersion_linear(3);
    printf("Linear search result: %d\n", first_bad2_linear);
    
    // Reset bad_version for consistency
    bad_version = 4;
    
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
    
    // LeetCode 148: Sort List Demo
    printf("\n=== LEETCODE 148: SORT LIST ===\n");
    
    // Create a test linked list: 5 -> 2 -> 8 -> 1 -> 3
    struct ListNode* head2 = createNode(5);
    head2->next = createNode(2);
    head2->next->next = createNode(8);
    head2->next->next->next = createNode(1);
    head2->next->next->next->next = createNode(3);
    
    printf("Original linked list: ");
    printList(head2);
    
    // Sort the linked list using sortList function
    struct ListNode* sortedHead2 = sortList(head2);
    
    printf("Sorted linked list: ");
    printList(sortedHead2);
    
    // Free memory
    freeList(sortedHead2);

    return 0;
}