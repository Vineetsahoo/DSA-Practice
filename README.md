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

**Two Pointer Techniques** --- September 10, 2025, 10:33 AM
- Started practicing array-based two pointer techniques
- LeetCode 26: Remove Duplicates from Sorted Array using two pointer approach
- Enhanced Remove_Duplicates.c with LeetCode solution
- Created 2_pointer_techniques folder for organized practice

## September 27, 2025

**Palindrome Problems Complete** --- September 27, 2025, 10:30 PM
- Advanced two pointer techniques for palindrome problems
- LeetCode 125: Valid Palindrome with alphanumeric filtering and helper functions
- LeetCode 680: Valid Palindrome II with one character deletion strategy
- LeetCode 647: Palindromic Substrings using expand around centers technique
- Created comprehensive Plaindrome.c with multiple palindrome algorithms
- Implemented helper functions: isAlphanumeric(), toLowerCase(), expandAroundCenter()
- Mastered different two-pointer patterns: validation, modification, and counting

## December 3-4, 2025

**Sliding Window Technique** --- December 3, 2025, 11:30 PM
- Started learning sliding window pattern for subarray problems
- Implemented basic sliding window for maximum sum of subarray
- LeetCode 643: Maximum Average Subarray I using fixed window sliding technique
- Created Sliding_Window.c with comprehensive implementations

**Sliding Window Advanced** --- December 4, 2025, 11:15 AM
- LeetCode 1343: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
- LeetCode 1876: Substrings of Size Three with Distinct Characters
- LeetCode 2269: Find the K-Beauty of a Number
- Mastered counting subarrays that meet specific conditions
- Learned optimization: comparing sums instead of calculating averages
- Understanding fixed window patterns across arrays, strings, and numbers
- Practiced string-to-integer conversion and divisibility checking

## December 13, 2025

**Sorting & Searching Algorithms Practice** --- December 13, 2025, 10:00 PM
- Created dedicated folder for sorting and searching algorithm exercises
- Practicing various sorting algorithm implementations and optimizations
- Working on search algorithm problems and their variations
- Combined sorting and searching techniques for problem solving
- Building strong foundation in fundamental algorithms

**Linked List & Trees** --- December 13, 2025, 10:30 PM
- Started learning linked list data structures and operations
- Practicing singly and doubly linked list implementations
- Working on tree data structure fundamentals
- Understanding pointer manipulation and node operations
- Exploring traversal techniques and tree algorithms

**Stack & Queues** --- December 13, 2025, 11:00 PM
- Learning stack data structure with LIFO operations
- Implementing queue data structure with FIFO operations
- Practicing push, pop, enqueue, and dequeue operations
- Understanding applications of stacks and queues
- Working on stack and queue based problem solving

## January 28, 2026

**LeetCode 707: Design Linked List** --- January 28, 2026, 11:15 PM
- Implemented complete Design Linked List (LeetCode 707) in Single_linked_list/implmentation.c
- MyLinkedList data structure with size tracking
- get(index): Returns value at index-th node (-1 if invalid)
- addAtHead(val): Adds node at the beginning in O(1) time
- addAtTail(val): Appends node at the end in O(n) time
- addAtIndex(index, val): Inserts node at index-th position with boundary validation
- deleteAtIndex(index): Removes node at index with proper memory deallocation
- Comprehensive test cases demonstrating all operations
- Maintained backward compatibility with basic linked list implementation (append, printList)
- Added freeList() function for proper memory cleanup

## January 31, 2026

**Factorial and Permutation Problems** --- January 31, 2026, 02:30 PM
- Created Factorial/ folder for factorial-based LeetCode problems
- Basic factorial calculation with overflow handling (up to 20!)
- LeetCode 172: Factorial Trailing Zeroes using integer division by powers of 5
- LeetCode 60: Permutation Sequence using factorial number system (Lehmer code)
- getPermutation(n, k): Generates k-th lexicographic permutation of 1 to n
- Dynamic memory allocation for result string in permutation generation
- Time complexity: O(n²) for permutation sequence, O(log n) for trailing zeroes

## File Structure
```
dsa_Practice/
├── .git/
├── .vscode/
│   ├── settings.json
│   └── tasks.json
├── 2_pointer_techniques/
│   ├── Plaindrome.c
│   ├── Remove_Duplicates.c
│   ├── Sliding_Window.c
│   └── output/
├── Assessment/
│   ├── Q1.c
│   ├── Q2.c
│   ├── Q3.c
│   ├── Q4.c
│   ├── Q5.c
│   ├── Q6.c
│   ├── Q7.c
│   └── output/
├── Factorial/
│   ├── Factorial.c
│   └── a.exe
├── Linked_List_&_Trees/
│   ├── Q1.c
│   ├── Q2.c
│   ├── Q3.c
│   ├── Q4.c
│   ├── Q5.C
│   └── output/
├── Marque_Company/
│   ├── Q1.c
│   ├── Q2.c
│   ├── Q3.c
│   ├── Q4.c
│   ├── output/
│   └── a.exe
├── Single_linked_list/
│   ├── implmentation.c
│   └── a.exe
├── Sorting_&_Searching_Algo/
│   ├── Q1.c
│   ├── Q2.c
│   ├── Q3.c
│   ├── Q4.c
│   ├── Q5.c
│   ├── Q6.c
│   └── output/
├── Sorting_techniques/
│   ├── Bubble_sort.c
│   ├── Insertion_sort.c
│   ├── Merge_sort.c
│   ├── Quick_Sort.c
│   └── Selection_sort.c
├── Stack_&_Queues/
│   ├── Q1.c
│   ├── Q2.c
│   ├── Q3.c
│   ├── Q4.c
│   ├── Q5.c
│   ├── Q6.c
│   ├── Q7.c
│   ├── Q8.c
│   └── output/
├── move_exe.bat
├── move_exe.ps1
└── README.md
```

## Usage Instructions

### Organization Scripts
- **Move Executables**: `.\move_exe.bat` or `.\move_exe.ps1`
  - Automatically moves all .exe files to output folder