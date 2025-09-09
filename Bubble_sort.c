#include <stdio.h>
#include <stdlib.h>

int A[] = {64, 34, 25, 12, 22, 11, 90};
int B[] = {31, 41, 59, 26, 41, 58}; 

// Bubble Sort Implementation in array

void bubble_sort(int A[], int n){
    for (int i = 0; i < n - 1; i++){ // Number of Passes
        for (int j = 0; j < n - i- 1; j++){ // last i elements are already sorted
            if (A[j] > A[j+1]){
                // Swap elements
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

// OPTIMISED BUBBLE SORT 
void bubble_sort_optimised(int B[], int n){
    int flag = 0; // To check if any swapping occurs
    for (int i = 0; i < n - 1; i++){ // Number of Passes
        flag = 0; // Reset flag for each pass
        for (int j = 0; j < n - i - 1; j++){  // Last i elements are already sorted
            if (B[j] > B[j+1]){
                // Swap elements
                int temp = B[j];
                B[j] = B[j+1];
                B[j+1] = temp;
                flag = 1; // Set flag if swapping occurs
            }
        }
        // If no swapping occurred, array is sorted
        if (flag == 0) {
            break;
        }
    }
}

// LEETCODE 977: Squares of Sorted Array using Bubble Sort
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    // Allocate memory for result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;  // Set the return size
    
    // Copy input array to result array and square each element
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i] * nums[i];
    }
    
    // Bubble sort the squared array (optimized version)
    int flag = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        flag = 0;
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (result[j] > result[j + 1]) {
                // Swap elements
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;  // Array is sorted, early termination
        }
    }
    
    return result;  // Return the pointer to the sorted array
}

// LEETCODE 1051: Height Checker using Bubble Sort (Simple Version)
int heightChecker(int A[], int n) {
    int B[100] = {};
    for (int i = 0; i < n; i++){
        B[i] = A[i];
    }

    int flag = 0;

    for (int i = 0; i < n - 1; i++){
        flag = 0;
        for (int j = 0; j < n - i - 1; j++){
            if (B[j] > B[j + 1]){
                int temp = B[j];
                B[j] = B[j + 1];
                B[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0){
            break;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++){
        if (A[i] != B[i]){
            count++;
        }
    }

    return count;
}

int main(){
    int n = sizeof(A)/sizeof(A[0]);
    printf("===ORIGINAL ARRAY of ARRAY A ===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    bubble_sort(A, n);

    printf("===ARRAY BUBBLE SORT===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("\n===ORIGINAL ARRAY of ARRAY B ===\n");
    int m = sizeof(B)/sizeof(B[0]);
    for (int i = 0; i < m; i++){
        printf("%d ", B[i]);
    }
    printf("\n");

    bubble_sort_optimised(B, m);

    printf("\n===ARRAY BUBBLE SORT OPTIMISED===\n");
    for (int i = 0; i < m; i++){
        printf("%d ", B[i]);
    }
    printf("\n");
    
    // ========== LEETCODE 977: SQUARES OF SORTED ARRAY ==========
    printf("\n=== LEETCODE 977: SQUARES OF SORTED ARRAY ===\n");
    
    // Test case 1: nums = [-4,-1,0,3,10]
    // Expected output: [0,1,9,16,100]
    int nums1[] = {-4, -1, 0, 3, 10};
    int nums1_size = sizeof(nums1)/sizeof(nums1[0]);
    int returnSize1;
    
    printf("Test Case 1:\n");
    printf("Input: [");
    for (int i = 0; i < nums1_size; i++) {
        printf("%d", nums1[i]);
        if (i < nums1_size - 1) printf(",");
    }
    printf("]\n");
    
    int* result1 = sortedSquares(nums1, nums1_size, &returnSize1);
    printf("Output: [");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d", result1[i]);
        if (i < returnSize1 - 1) printf(",");
    }
    printf("]\n\n");
    
    // Test case 2: nums = [-7,-3,2,3,11]
    // Expected output: [4,9,9,49,121]
    int nums2[] = {-7, -3, 2, 3, 11};
    int nums2_size = sizeof(nums2)/sizeof(nums2[0]);
    int returnSize2;
    
    printf("Test Case 2:\n");
    printf("Input: [");
    for (int i = 0; i < nums2_size; i++) {
        printf("%d", nums2[i]);
        if (i < nums2_size - 1) printf(",");
    }
    printf("]\n");
    
    int* result2 = sortedSquares(nums2, nums2_size, &returnSize2);
    printf("Output: [");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d", result2[i]);
        if (i < returnSize2 - 1) printf(",");
    }
    printf("]\n");
    
    // Free allocated memory
    free(result1);
    free(result2);
    
    // ========== LEETCODE 1051: HEIGHT CHECKER ==========
    printf("\n=== LEETCODE 1051: HEIGHT CHECKER ===\n");
    
    // Test case 1: heights = [1,1,4,2,1,3]
    // Expected: [1,1,1,2,3,4], so positions 2, 4, 5 are wrong → answer = 3
    int heights1[] = {1, 1, 4, 2, 1, 3};
    int heights1_size = sizeof(heights1)/sizeof(heights1[0]);
    
    printf("Test Case 1:\n");
    printf("Input: [");
    for (int i = 0; i < heights1_size; i++) {
        printf("%d", heights1[i]);
        if (i < heights1_size - 1) printf(",");
    }
    printf("]\n");
    
    int result_1051_1 = heightChecker(heights1, heights1_size);
    printf("Output: %d (students out of place)\n\n", result_1051_1);
    
    // Test case 2: heights = [5,1,2,3,4]
    // Expected: [1,2,3,4,5], so positions 0, 1, 2, 3, 4 are wrong → answer = 5
    int heights2[] = {5, 1, 2, 3, 4};
    int heights2_size = sizeof(heights2)/sizeof(heights2[0]);
    
    printf("Test Case 2:\n");
    printf("Input: [");
    for (int i = 0; i < heights2_size; i++) {
        printf("%d", heights2[i]);
        if (i < heights2_size - 1) printf(",");
    }
    printf("]\n");
    
    int result_1051_2 = heightChecker(heights2, heights2_size);
    printf("Output: %d (students out of place)\n\n", result_1051_2);
    
    // Test case 3: heights = [1,2,3,4,5]
    // Expected: [1,2,3,4,5], already sorted → answer = 0
    int heights3[] = {1, 2, 3, 4, 5};
    int heights3_size = sizeof(heights3)/sizeof(heights3[0]);
    
    printf("Test Case 3:\n");
    printf("Input: [");
    for (int i = 0; i < heights3_size; i++) {
        printf("%d", heights3[i]);
        if (i < heights3_size - 1) printf(",");
    }
    printf("]\n");
    
    int result_1051_3 = heightChecker(heights3, heights3_size);
    printf("Output: %d (students out of place)\n", result_1051_3);
    
    return 0;
}