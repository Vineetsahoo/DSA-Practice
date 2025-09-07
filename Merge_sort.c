#include <stdio.h>

int A[] = {31, 41, 59, 26, 41, 58};

// Function declarations
void merge_sort(int A[], int left, int right);
void merge(int A[], int left, int mid, int right);

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

int main(){
    int n = sizeof(A)/sizeof(A[0]);
    printf("===ORIGINAL ARRAY===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");

    merge_sort(A, 0, n-1);

    printf("===MERGE SORT===\n");
    for (int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    // LEETCODE 88: Merge Sorted Array
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