#include <stdio.h>
#include <stdlib.h>

// Basic implementation of Sliding Window technique for practice by applying it to find the maximum sum of a subarray of size k

int maxSubarraySum(int arr[], int n, int w) {
    int current = 0;
    for (int i = 0; i<w;i++){
        current += arr[i];
    }
    int max = current;
    for (int i =1; i <= n - w; i++){
        current = current - arr[i - 1] + arr[i + w - 1];
        if (current > max){
            max = current;
        }
    }
    return max;
}

// ========== LEETCODE 643: MAXIMUM AVERAGE SUBARRAY I ==========

// LeetCode 643: Maximum Average Subarray I
double findMaxAverage(int* nums, int numsSize, int k) {
    // Calculate sum of first window
    int current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += nums[i];
    }
    
    // Initialize max_sum with first window sum
    int max_sum = current_sum;
    
    // Slide the window
    for (int i = k; i < numsSize; i++) {
        current_sum = current_sum - nums[i - k] + nums[i];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    // Return average as double
    return (double)max_sum / k;
}

// ========== LEETCODE 1343: NUMBER OF SUB-ARRAYS OF SIZE K AND AVERAGE GREATER THAN OR EQUAL TO THRESHOLD ==========

// LeetCode 1343: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
int numOfSubarrays(int arr[], int arrSize, int k, int threshold) {
    // Calculate sum of first window
    int current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }
    
    // Calculate threshold sum (threshold * k)
    int threshold_sum = threshold * k;
    
    // Check if first window meets threshold
    int count = 0;
    if (current_sum >= threshold_sum) {
        count++;
    }
    
    // Slide the window and check each window
    for (int i = k; i < arrSize; i++) {
        current_sum = current_sum - arr[i - k] + arr[i];
        if (current_sum >= threshold_sum) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int w = 3;
    printf("===BASIC IMPLEMENTATION===\n");
    printf("Array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nWindow size: %d\n", w);
    int maxSum = maxSubarraySum(arr, n, w);
    printf("Maximum sum of a subarray of size %d: %d\n", w, maxSum);

    // ========== LEETCODE 643: MAXIMUM AVERAGE SUBARRAY I ==========
    printf("\n=== LEETCODE 643: MAXIMUM AVERAGE SUBARRAY I ===\n");
    
    // Test case 1: nums = [1,12,-5,-6,50,3], k = 4
    // Expected output: 12.75000
    int nums1[] = {1, 12, -5, -6, 50, 3};
    int nums1_size = sizeof(nums1)/sizeof(nums1[0]);
    int k1 = 4;
    
    printf("Test Case 1:\n");
    printf("Input: nums = [");
    for (int i = 0; i < nums1_size; i++) {
        printf("%d", nums1[i]);
        if (i < nums1_size - 1) printf(",");
    }
    printf("], k = %d\n", k1);
    printf("Output: %.5f\n\n", findMaxAverage(nums1, nums1_size, k1));
    
    // Test case 2: nums = [5], k = 1
    // Expected output: 5.00000
    int nums2[] = {5};
    int nums2_size = sizeof(nums2)/sizeof(nums2[0]);
    int k2 = 1;
    
    printf("Test Case 2:\n");
    printf("Input: nums = [");
    for (int i = 0; i < nums2_size; i++) {
        printf("%d", nums2[i]);
        if (i < nums2_size - 1) printf(",");
    }
    printf("], k = %d\n", k2);
    printf("Output: %.5f\n\n", findMaxAverage(nums2, nums2_size, k2));
    
    // Test case 3: nums = [0,4,0,3,2], k = 1
    // Expected output: 4.00000
    int nums3[] = {0, 4, 0, 3, 2};
    int nums3_size = sizeof(nums3)/sizeof(nums3[0]);
    int k3 = 1;
    
    printf("Test Case 3:\n");
    printf("Input: nums = [");
    for (int i = 0; i < nums3_size; i++) {
        printf("%d", nums3[i]);
        if (i < nums3_size - 1) printf(",");
    }
    printf("], k = %d\n", k3);
    printf("Output: %.5f\n", findMaxAverage(nums3, nums3_size, k3));

    // ========== LEETCODE 1343: NUMBER OF SUB-ARRAYS ==========
    printf("\n=== LEETCODE 1343: NUMBER OF SUB-ARRAYS OF SIZE K ===\n");
    
    // Test case 1: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
    // Expected output: 3
    int arr1[] = {2, 2, 2, 2, 5, 5, 5, 8};
    int arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    int k_1 = 3;
    int threshold1 = 4;
    
    printf("Test Case 1:\n");
    printf("Input: arr = [");
    for (int i = 0; i < arr1_size; i++) {
        printf("%d", arr1[i]);
        if (i < arr1_size - 1) printf(",");
    }
    printf("], k = %d, threshold = %d\n", k_1, threshold1);
    printf("Output: %d\n\n", numOfSubarrays(arr1, arr1_size, k_1, threshold1));
    
    // Test case 2: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
    // Expected output: 6
    int arr2[] = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    int arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    int k_2 = 3;
    int threshold2 = 5;
    
    printf("Test Case 2:\n");
    printf("Input: arr = [");
    for (int i = 0; i < arr2_size; i++) {
        printf("%d", arr2[i]);
        if (i < arr2_size - 1) printf(",");
    }
    printf("], k = %d, threshold = %d\n", k_2, threshold2);
    printf("Output: %d\n\n", numOfSubarrays(arr2, arr2_size, k_2, threshold2));
    
    // Test case 3: arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
    // Expected output: 1
    int arr3[] = {7, 7, 7, 7, 7, 7, 7};
    int arr3_size = sizeof(arr3)/sizeof(arr3[0]);
    int k_3 = 7;
    int threshold3 = 7;
    
    printf("Test Case 3:\n");
    printf("Input: arr = [");
    for (int i = 0; i < arr3_size; i++) {
        printf("%d", arr3[i]);
        if (i < arr3_size - 1) printf(",");
    }
    printf("], k = %d, threshold = %d\n", k_3, threshold3);
    printf("Output: %d\n", numOfSubarrays(arr3, arr3_size, k_3, threshold3));

    return 0;
}