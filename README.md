# DSA Practice

This repo is for DSA Practice

## September 4, 2025

**Insertion Sort** --- September 4, 2025, 11:42 PM
- Implemented insertion sort algorithm
- Added linear search algorithm  
- Binary addition for n-bit integers
- Decimal to binary conversion
- Array sorting in ascending and descending order

## September 6, 2025

**Selection Sort** --- September 6, 2025, 10:30 PM
- Implemented selection sort algorithm
- LeetCode 75: Sort Colors using selection sort
- LeetCode 215: Kth Largest Element in an Array using selection sort
- LeetCode 268: Missing Number using selection sort
- Practiced finding minimum and maximum elements
- Array sorting in ascending and descending order

## September 7, 2025

**Insertion Sort Advanced** --- September 7, 2025, 2:00 PM
- Enhanced insertion sort algorithm with linked list implementation
- LeetCode 147: Insertion Sort List using linked list insertion sort
- LeetCode 148: Sort List (same algorithm as 147, different function name)
- LeetCode 35: Search Insert Position using insertion sort concepts
- LeetCode 704: Binary Search (optimized version of insertion sort position finding)
- LeetCode 278: First Bad Version using insertion sort boundary finding logic
- Implemented helper functions for linked list operations (createNode, printList, freeList)
- Binary addition for n-bit integers (continued from previous work)
- Understanding insertion sort applications in various problem-solving scenarios

**Merge Sort** --- September 7, 2025, 3:30 PM
- Implemented merge sort algorithm using divide and conquer
- LeetCode 88: Merge Sorted Array using backward merging technique
- Fixed array indexing bug (A[j] vs B[j])
- Time complexity: O(n log n)

## September 8, 2025

**Merge Sort with Linked List** --- September 8, 2025, 10:30 PM
- Implemented merge sort for singly linked list
- Created helper functions: createNode, printList, freeList
- Simple logic approach: findMiddle using node counting (no fast/slow pointers)
- mergeTwoSortedLists function to merge two sorted linked lists
- mergeSortLinkedList recursive function for divide and conquer
- Successfully sorted linked list: 64→34→25→12→22→11→90 to 11→12→22→25→34→64→90

## September 9, 2025

**Merge Sort with LeetCode** --- September 9, 2025, 4:15 PM
- LeetCode 21: Merge Two Sorted Lists using merge sort merge step
- LeetCode 23: Merge K Sorted Lists using divide and conquer approach
- Enhanced Merge_sort.c with LeetCode solutions
- Fixed code bugs and variable naming conflicts

**Bubble Sort** --- September 9, 2025, 8:30 PM
- Implemented bubble sort algorithm with optimized version
- LeetCode 977: Squares of Sorted Array using bubble sort
- LeetCode 1051: Height Checker using bubble sort
- Enhanced Bubble_sort.c with LeetCode solutions

**Quick Sort** --- September 9, 2025, 10:05 PM
- Implemented quick sort algorithm with partition function
- LeetCode 912: Sort an Array using quick sort
- LeetCode 347: Top K Frequent Elements using quick sort with frequency counting
- Enhanced Quick_Sort.c with LeetCode solutions
- Used parallel arrays for frequency-based sorting

## September 10, 2025

**Project Organization** --- September 10, 2025, 12:01 AM
- Created automation scripts for better project organization
- Added compile.bat and compile.ps1 for automated compilation
- Added move_exe.bat and move_exe.ps1 for organizing executable files
- Created output folder to store all generated executable files
- Improved project structure and file management

**Two Pointer Techniques** --- September 10, 2025, 12:30 AM
- Started practicing array-based two pointer techniques
- LeetCode 26: Remove Duplicates from Sorted Array using two pointer approach
- Enhanced Remove_Duplicates.c with LeetCode solution
- Created 2_pointer_techniques folder for organized practice

## File Structure
```
dsa Practice/
├── .git/
├── .vscode/
├── 2_pointer_techniques/
│   └── Remove_Duplicates.c
├── Sorting_techniques/
│   ├── Bubble_sort.c
│   ├── Insertion_sort.c
│   ├── Merge_sort.c
│   ├── Quick_Sort.c
│   └── Selection_sort.c
├── output/
│   └── (executable files generated from compilation)
├── move_exe.bat
├── move_exe.ps1
└── README.md
```

## Usage Instructions

### Organization Scripts
- **Move Executables**: `.\move_exe.bat` or `.\move_exe.ps1`
  - Automatically moves all .exe files to output folder