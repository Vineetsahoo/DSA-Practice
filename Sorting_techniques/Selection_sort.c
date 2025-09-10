# include <stdio.h>

int A[] = {31, 41, 59, 26, 41, 58};

// Function declarations
void selection_sort(int A[], int n);
void sortColors(int nums[], int n);
int findKthLargest(int nums[], int n, int k);
int missingNumber(int nums[], int n);

// SELECTION SORT ALGORITHM
void selection_sort(int A[], int n) {
    for (int i = 0; i< n-1; i++){
        int min = i;
        for (int j = i+1; j < n; j++){
            if (A[j]< A[min]){
                min = j;
            }
        }
        if (min != i){
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

int main(){
    int n = sizeof(A)/sizeof(A[0]);
    printf("===ORIGINAL ARRAY===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    selection_sort(A, n);

    printf("===SELECTION SORT===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n\n");

    // LEETCODE 75: SORT COLORS (Using Selection Sort)
    printf("===LEETCODE 75: SORT COLORS===\n");
    
    // Test case for Sort Colors (0s, 1s, 2s only)
    int colors[] = {2, 0, 2, 1, 1, 0};
    int colors_n = sizeof(colors)/sizeof(colors[0]);
    
    printf("Original colors array: ");
    for (int i = 0; i < colors_n; i++){
        printf("%d ", colors[i]);
    }
    printf("\n");
    
    // Using Selection Sort
    sortColors(colors, colors_n);
    
    printf("After selection sort: ");
    for (int i = 0; i < colors_n; i++){
        printf("%d ", colors[i]);
    }
    printf("\n\n");
    
    // LEETCODE 215: Kth Largest Element in an Array
    printf("===LEETCODE 215: Kth Largest Element===\n");
    
    // Test case
    int nums[] = {3, 2, 1, 5, 6, 4};
    int nums_n = sizeof(nums)/sizeof(nums[0]);
    int k = 2; // Find 2nd largest element
    
    printf("Original array: ");
    for (int i = 0; i < nums_n; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("Finding %d largest element...\n", k);
    
    int result = findKthLargest(nums, nums_n, k);
    printf("The %d largest element is: %d\n", k, result);
    
    // Test case 2
    int nums2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int nums2_n = sizeof(nums2)/sizeof(nums2[0]);
    int k2 = 4;
    
    printf("\nTest case 2: ");
    for (int i = 0; i < nums2_n; i++){
        printf("%d ", nums2[i]);
    }
    printf("\n");
    printf("Finding %d largest element...\n", k2);
    
    int result2 = findKthLargest(nums2, nums2_n, k2);
    printf("The %d largest element is: %d\n", k2, result2);
    printf("\n");
    
    // LEETCODE 268: Missing Number
    printf("===LEETCODE 268: Missing Number===\n");
    
    // Test case 1: [3,0,1] - missing 2
    int missing_nums1[] = {3, 0, 1};
    int missing_n1 = sizeof(missing_nums1)/sizeof(missing_nums1[0]);
    
    printf("Original array: ");
    for (int i = 0; i < missing_n1; i++){
        printf("%d ", missing_nums1[i]);
    }
    printf("\n");
    
    int missing_result1 = missingNumber(missing_nums1, missing_n1);
    printf("Missing number: %d\n", missing_result1);
    
    // Test case 2: [0,1] - missing 2
    int missing_nums2[] = {0, 1};
    int missing_n2 = sizeof(missing_nums2)/sizeof(missing_nums2[0]);
    
    printf("\nTest case 2: ");
    for (int i = 0; i < missing_n2; i++){
        printf("%d ", missing_nums2[i]);
    }
    printf("\n");
    
    int missing_result2 = missingNumber(missing_nums2, missing_n2);
    printf("Missing number: %d\n", missing_result2);
    
    // Test case 3: [9,6,4,2,3,5,7,0,1] - missing 8
    int missing_nums3[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int missing_n3 = sizeof(missing_nums3)/sizeof(missing_nums3[0]);
    
    printf("\nTest case 3: ");
    for (int i = 0; i < missing_n3; i++){
        printf("%d ", missing_nums3[i]);
    }
    printf("\n");
    
    int missing_result3 = missingNumber(missing_nums3, missing_n3);
    printf("Missing number: %d\n", missing_result3);
}

// LEETCODE 75: Sort Colors using Selection Sort
void sortColors(int nums[], int n) {
    for (int i = 0; i < n-1; i++){
        int min = i;
        for (int j = i+1; j < n; j++){
            if (nums[j] < nums[min]){
                min = j;
            }
        }
        if (min != i){
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
    }
}

// LEETCODE 215: Kth Largest Element using Selection Sort
int findKthLargest(int nums[], int n, int k) {
    // Sort the array in descending order using selection sort
    for (int i = 0; i < n-1; i++){
        int max = i;
        for (int j = i+1; j < n; j++){
            if (nums[j] > nums[max]){ // Find maximum instead of minimum
                max = j;
            }
        }
        if (max != i){
            int temp = nums[i];
            nums[i] = nums[max];
            nums[max] = temp;
        }
    }
    
    // After sorting in descending order, kth largest is at index k-1
    return nums[k-1];
}

// LEETCODE 268: Missing Number using Selection Sort
int missingNumber(int nums[], int n) {
    // Sort the array in ascending order using selection sort
    for (int i = 0; i < n-1; i++){
        int min = i;
        for (int j = i+1; j < n; j++){
            if (nums[j] < nums[min]){
                min = j;
            }
        }
        if (min != i){
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
    }
    
    // After sorting, check for missing number
    // Array should contain numbers from 0 to n
    for (int i = 0; i < n; i++){
        if (nums[i] != i){
            return i; // Found the missing number
        }
    }
    
    // If all numbers 0 to n-1 are present, missing number is n
    return n;
}