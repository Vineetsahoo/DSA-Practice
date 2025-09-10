#include <stdio.h>
#include <stdlib.h>

// Basic implementation for practice
int removeDuplicates(int A[],int n){
    if (n == 0) return 0; // if array is empty
    int j = 0; // Pointer for the position of the next unique element
    for (int i = 1; i < n; i++){
        if (A[i] != A[j]){ // If current element is different from the last unique element
            j++; // Move to the next position for unique element
            A[j] = A[i]; // Update the position with the new unique element
        }
    }
    return j + 1; // Length of array with unique elements
}

// ========== LEETCODE 26: REMOVE DUPLICATES FROM SORTED ARRAY ==========

// LeetCode 26: Remove Duplicates from Sorted Array
int removeDuplicates_leetcode(int* nums, int numsSize) {
    // Edge case: if array is empty
    if (numsSize == 0) return 0;
    
    int j = 0; // Pointer for the position of the next unique element
    
    // Start from index 1 since first element is always unique
    for (int i = 1; i < numsSize; i++) {
        // If current element is different from the last unique element
        if (nums[i] != nums[j]) {
            j++; // Move to the next position for unique element
            nums[j] = nums[i]; // Update the position with the new unique element
        }
    }
    
    return j + 1; // Return the length of array with unique elements
}

int main(){
    int A[] = {1,1,2,2,3,4,4,5};
    int n = sizeof(A)/sizeof(A[0]);
    printf("===BASIC IMPLEMENTATION===\n");
    printf("Original array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    int newLength = removeDuplicates(A, n);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < newLength; i++){
        printf("%d ", A[i]);
    }
    printf("\nNew length: %d\n", newLength);

    // ========== LEETCODE 26: REMOVE DUPLICATES FROM SORTED ARRAY ==========
    printf("\n=== LEETCODE 26: REMOVE DUPLICATES FROM SORTED ARRAY ===\n");
    
    // Test case 1: nums = [1,1,2]
    // Expected output: 2, nums = [1,2,_]
    int nums1[] = {1, 1, 2};
    int nums1_size = sizeof(nums1)/sizeof(nums1[0]);
    
    printf("Test Case 1:\n");
    printf("Input: [");
    for (int i = 0; i < nums1_size; i++) {
        printf("%d", nums1[i]);
        if (i < nums1_size - 1) printf(",");
    }
    printf("]\n");
    
    int result1 = removeDuplicates_leetcode(nums1, nums1_size);
    printf("Output: %d, nums = [", result1);
    for (int i = 0; i < result1; i++) {
        printf("%d", nums1[i]);
        if (i < result1 - 1) printf(",");
    }
    printf("]\n\n");
    
    // Test case 2: nums = [0,0,1,1,1,2,2,3,3,4]
    // Expected output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int nums2_size = sizeof(nums2)/sizeof(nums2[0]);
    
    printf("Test Case 2:\n");
    printf("Input: [");
    for (int i = 0; i < nums2_size; i++) {
        printf("%d", nums2[i]);
        if (i < nums2_size - 1) printf(",");
    }
    printf("]\n");
    
    int result2 = removeDuplicates_leetcode(nums2, nums2_size);
    printf("Output: %d, nums = [", result2);
    for (int i = 0; i < result2; i++) {
        printf("%d", nums2[i]);
        if (i < result2 - 1) printf(",");
    }
    printf("]\n\n");
    
    // Test case 3: nums = [1,2,3]
    // Expected output: 3, nums = [1,2,3]
    int nums3[] = {1, 2, 3};
    int nums3_size = sizeof(nums3)/sizeof(nums3[0]);
    
    printf("Test Case 3:\n");
    printf("Input: [");
    for (int i = 0; i < nums3_size; i++) {
        printf("%d", nums3[i]);
        if (i < nums3_size - 1) printf(",");
    }
    printf("]\n");
    
    int result3 = removeDuplicates_leetcode(nums3, nums3_size);
    printf("Output: %d, nums = [", result3);
    for (int i = 0; i < result3; i++) {
        printf("%d", nums3[i]);
        if (i < result3 - 1) printf(",");
    }
    printf("]\n\n");
    
    // Test case 4: Edge case - single element
    int nums4[] = {1};
    int nums4_size = sizeof(nums4)/sizeof(nums4[0]);
    
    printf("Test Case 4 (Edge Case):\n");
    printf("Input: [");
    for (int i = 0; i < nums4_size; i++) {
        printf("%d", nums4[i]);
        if (i < nums4_size - 1) printf(",");
    }
    printf("]\n");
    
    int result4 = removeDuplicates_leetcode(nums4, nums4_size);
    printf("Output: %d, nums = [", result4);
    for (int i = 0; i < result4; i++) {
        printf("%d", nums4[i]);
        if (i < result4 - 1) printf(",");
    }
    printf("]\n");

    return 0;
}