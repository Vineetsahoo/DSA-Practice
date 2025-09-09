#include <stdio.h>
#include <stdlib.h>

int A[] = {64, 34, 25, 12, 22, 11, 90};

// Quick Sort Implementation in array

int partition(int A[], int lb, int ub){
    int pivot = A[lb]; // Taking first element as pivot
    int start = lb;
    int end = ub;

    while (start < end ){
        while (A[start] <= pivot){
            start++;
        }
        while (A[end] > pivot){
            end--;
        }
        if (start < end){
            // Swap A[start] and A[end]
            int temp = A[start];
            A[start] = A[end];
            A[end] = temp;
        }
    }
    // Swap pivot with A[end]
    int temp = A[lb];
    A[lb] = A[end];
    A[end] = temp;
    return end;
}

void quick_sort(int A[], int lb, int ub){
    if (lb < ub){
        int loc = partition(A, lb, ub); // Partitioning index
        quick_sort(A, lb, loc - 1); // Recursively sort elements before partition
        quick_sort(A, loc + 1, ub); // Recursively sort elements after partition
    }
}

// ========== LEETCODE 912: SORT AN ARRAY ==========

// Partition function for LeetCode (with boundary checks)
int partition_leetcode(int result[], int lb, int ub) {
    int pivot = result[lb];
    int start = lb;
    int end = ub;
    
    while (start < end) {
        // Find element greater than pivot from left
        while (start <= ub && result[start] <= pivot) {
            start++;
        }
        // Find element smaller than or equal to pivot from right
        while (end >= lb && result[end] > pivot) {
            end--;
        }
        // Swap if start < end
        if (start < end) {
            int temp = result[start];
            result[start] = result[end];
            result[end] = temp;
        }
    }
    // Place pivot in correct position
    int temp = result[lb];
    result[lb] = result[end];
    result[end] = temp;
    
    return end;  // Return pivot position
}

// Quick sort function for LeetCode
void quick_sort_leetcode(int result[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition_leetcode(result, lb, ub);
        quick_sort_leetcode(result, lb, loc - 1);     // Sort left side
        quick_sort_leetcode(result, loc + 1, ub);     // Sort right side
    }
}

// LEETCODE 912: Sort an Array
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    // Copy input array to result array
    for (int i = 0; i < numsSize; i++) {
        result[i] = nums[i];
    }
    
    // Sort the result array using quick sort
    quick_sort_leetcode(result, 0, numsSize - 1);
    
    return result;
}

// ========== LEETCODE 347: TOP K FREQUENT ELEMENTS ==========

// Partition function for frequency sorting (using parallel arrays)
int partition_freq(int elements[], int frequencies[], int lb, int ub) {
    int pivot = frequencies[lb];
    int start = lb;
    int end = ub;
    
    while (start < end) {
        while (start <= ub && frequencies[start] <= pivot) {
            start++;
        }
        while (end >= lb && frequencies[end] > pivot) {
            end--;
        }
        if (start < end) {
            // Swap frequencies
            int temp_freq = frequencies[start];
            frequencies[start] = frequencies[end];
            frequencies[end] = temp_freq;
            
            // Swap corresponding elements
            int temp_elem = elements[start];
            elements[start] = elements[end];
            elements[end] = temp_elem;
        }
    }
    // Place pivot in correct position
    int temp_freq = frequencies[lb];
    frequencies[lb] = frequencies[end];
    frequencies[end] = temp_freq;
    
    int temp_elem = elements[lb];
    elements[lb] = elements[end];
    elements[end] = temp_elem;
    
    return end;
}

// Quick sort for parallel arrays
void quick_sort_freq(int elements[], int frequencies[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition_freq(elements, frequencies, lb, ub);
        quick_sort_freq(elements, frequencies, lb, loc - 1);
        quick_sort_freq(elements, frequencies, loc + 1, ub);
    }
}

// LEETCODE 347: Top K Frequent Elements
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;
    
    // Step 1: Count frequencies using parallel arrays
    int elements[1000];     // Store unique elements
    int frequencies[1000];  // Store their frequencies
    int uniqueCount = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // Check if element already exists
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (elements[j] == nums[i]) {
                frequencies[j]++;
                found = 1;
                break;
            }
        }
        // If not found, add new element
        if (!found) {
            elements[uniqueCount] = nums[i];
            frequencies[uniqueCount] = 1;
            uniqueCount++;
        }
    }
    
    // Step 2: Sort by frequency using quick sort
    quick_sort_freq(elements, frequencies, 0, uniqueCount - 1);
    
    // Step 3: Reverse to get descending order (highest frequency first)
    for (int i = 0; i < uniqueCount / 2; i++) {
        // Swap frequencies
        int temp_freq = frequencies[i];
        frequencies[i] = frequencies[uniqueCount - 1 - i];
        frequencies[uniqueCount - 1 - i] = temp_freq;
        
        // Swap elements
        int temp_elem = elements[i];
        elements[i] = elements[uniqueCount - 1 - i];
        elements[uniqueCount - 1 - i] = temp_elem;
    }
    
    // Step 4: Extract top k elements
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = elements[i];
    }
    
    return result;
}

int main(){
    int n = sizeof(A)/sizeof(A[0]);
    printf("===ORIGINAL ARRAY===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    quick_sort(A, 0, n-1);

    printf("===ARRAY QUICK SORT===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    // ========== LEETCODE 912: SORT AN ARRAY ==========
    printf("\n=== LEETCODE 912: SORT AN ARRAY ===\n");
    
    // Test case 1: nums = [5,2,3,1]
    // Expected output: [1,2,3,5]
    int nums1[] = {5, 2, 3, 1};
    int nums1_size = sizeof(nums1)/sizeof(nums1[0]);
    int returnSize1;
    
    printf("Test Case 1:\n");
    printf("Input: [");
    for (int i = 0; i < nums1_size; i++) {
        printf("%d", nums1[i]);
        if (i < nums1_size - 1) printf(",");
    }
    printf("]\n");
    
    int* result1 = sortArray(nums1, nums1_size, &returnSize1);
    printf("Output: [");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d", result1[i]);
        if (i < returnSize1 - 1) printf(",");
    }
    printf("]\n\n");
    
    // Test case 2: nums = [5,1,1,2,0,0]
    // Expected output: [0,0,1,1,2,5]
    int nums2[] = {5, 1, 1, 2, 0, 0};
    int nums2_size = sizeof(nums2)/sizeof(nums2[0]);
    int returnSize2;
    
    printf("Test Case 2:\n");
    printf("Input: [");
    for (int i = 0; i < nums2_size; i++) {
        printf("%d", nums2[i]);
        if (i < nums2_size - 1) printf(",");
    }
    printf("]\n");
    
    int* result2 = sortArray(nums2, nums2_size, &returnSize2);
    printf("Output: [");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d", result2[i]);
        if (i < returnSize2 - 1) printf(",");
    }
    printf("]\n");
    
    // Free allocated memory
    free(result1);
    free(result2);
    
    // ========== LEETCODE 347: TOP K FREQUENT ELEMENTS ==========
    printf("\n=== LEETCODE 347: TOP K FREQUENT ELEMENTS ===\n");
    
    // Test case 1: nums = [1,1,1,2,2,3], k = 2
    // Expected output: [1,2] (1 appears 3 times, 2 appears 2 times)
    int nums3[] = {1, 1, 1, 2, 2, 3};
    int nums3_size = sizeof(nums3)/sizeof(nums3[0]);
    int k1 = 2;
    int returnSize3;
    
    printf("Test Case 1:\n");
    printf("Input: [");
    for (int i = 0; i < nums3_size; i++) {
        printf("%d", nums3[i]);
        if (i < nums3_size - 1) printf(",");
    }
    printf("], k = %d\n", k1);
    
    int* result3 = topKFrequent(nums3, nums3_size, k1, &returnSize3);
    printf("Output: [");
    for (int i = 0; i < returnSize3; i++) {
        printf("%d", result3[i]);
        if (i < returnSize3 - 1) printf(",");
    }
    printf("]\n\n");
    
    // Test case 2: nums = [1], k = 1
    // Expected output: [1]
    int nums4[] = {1};
    int nums4_size = sizeof(nums4)/sizeof(nums4[0]);
    int k2 = 1;
    int returnSize4;
    
    printf("Test Case 2:\n");
    printf("Input: [");
    for (int i = 0; i < nums4_size; i++) {
        printf("%d", nums4[i]);
        if (i < nums4_size - 1) printf(",");
    }
    printf("], k = %d\n", k2);
    
    int* result4 = topKFrequent(nums4, nums4_size, k2, &returnSize4);
    printf("Output: [");
    for (int i = 0; i < returnSize4; i++) {
        printf("%d", result4[i]);
        if (i < returnSize4 - 1) printf(",");
    }
    printf("]\n");
    
    // Free allocated memory
    free(result3);
    free(result4);
    
    return 0;
}