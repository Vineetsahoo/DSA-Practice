#include <stdio.h>
#include <stdbool.h>

// Function to check if a string is a palindrome using two-pointer technique
int isPalindrome(const char* s) {
    int left = 0;
    int right = 0;

    // Find the length of the string
    while (s[right] != '\0') {
        right++;
    }
    right--; // Set right to the last character index

    while (left < right) {
        // Move left pointer to the next alphanumeric character
        while (left < right && !((s[left] >= 'a' && s[left] <= 'z') || 
                                 (s[left] >= 'A' && s[left] <= 'Z') || 
                                 (s[left] >= '0' && s[left] <= '9'))) {
            left++;
        }
        // Move right pointer to the previous alphanumeric character
        while (left < right && !((s[right] >= 'a' && s[right] <= 'z') || 
                                  (s[right] >= 'A' && s[right] <= 'Z') || 
                                  (s[right] >= '0' && s[right] <= '9'))) {
            right--;
        }

        // Compare characters in a case-insensitive manner
        char leftChar = s[left];
        char rightChar = s[right];

        // Convert to lowercase if they are uppercase
        if (leftChar >= 'A' && leftChar <= 'Z') {
            leftChar += ('a' - 'A');
        }
        if (rightChar >= 'A' && rightChar <= 'Z') {
            rightChar += ('a' - 'A');
        }

        if (leftChar != rightChar) {
            return 0; // Not a palindrome
        }

        left++;
        right--;
    }

    return 1; // Is a palindrome
}

// ========== LEETCODE 125: VALID PALINDROME ==========

// Helper function to check if character is alphanumeric
int isAlphanumeric(char c) {
    return ((c >= 'a' && c <= 'z') || 
            (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9'));
}

// Helper function to convert to lowercase
char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// LeetCode 125: Valid Palindrome
int isPalindrome_leetcode(char* s) {
    int left = 0;
    int right = 0;
    
    // Find string length
    while (s[right] != '\0') {
        right++;
    }
    right--; // Set to last character index
    
    while (left < right) {
        // Skip non-alphanumeric from left (including colons, commas, spaces, etc.)
        while (left < right && !isAlphanumeric(s[left])) {
            left++;
        }
        // Skip non-alphanumeric from right (including colons, commas, spaces, etc.)
        while (left < right && !isAlphanumeric(s[right])) {
            right--;
        }
        
        // If pointers crossed, we're done
        if (left >= right) {
            break;
        }
        
        // Convert to lowercase and compare
        char leftChar = toLowerCase(s[left]);
        char rightChar = toLowerCase(s[right]);
        
        if (leftChar != rightChar) {
            return 0; // false
        }
        
        left++;
        right--;
    }
    
    return 1; // true
}

// ========== LEETCODE 680: VALID PALINDROME II ==========

// Helper function to check if substring is palindrome
int isPalindromeRange(char* s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return 0; // false
        }
        left++;
        right--;
    }
    return 1; // true
}

// LeetCode 680: Valid Palindrome II
int validPalindrome(char* s) {
    int left = 0;
    int right = 0;
    
    // Find string length
    while (s[right] != '\0') {
        right++;
    }
    right--; // Set to last character index
    
    while (left < right) {
        if (s[left] != s[right]) {
            // Try skipping left character OR skipping right character
            return isPalindromeRange(s, left + 1, right) || 
                   isPalindromeRange(s, left, right - 1);
        }
        left++;
        right--;
    }
    
    return 1; // Already a palindrome
}

// ========== LEETCODE 647: PALINDROMIC SUBSTRINGS ==========

// Helper function to expand around center and count palindromes
int expandAroundCenter(char* s, int left, int right) {
    int count = 0;
    int len = 0;
    
    // Find string length
    while (s[len] != '\0') {
        len++;
    }
    
    // Expand while characters match and within bounds
    while (left >= 0 && right < len && s[left] == s[right]) {
        count++; // Found a palindrome
        left--;  // Expand left
        right++; // Expand right
    }
    
    return count;
}

// LeetCode 647: Palindromic Substrings
int countSubstrings(char* s) {
    int totalCount = 0;
    int len = 0;
    
    // Find string length
    while (s[len] != '\0') {
        len++;
    }
    
    for (int i = 0; i < len; i++) {
        // Count odd-length palindromes (center at i)
        totalCount += expandAroundCenter(s, i, i);
        
        // Count even-length palindromes (center between i and i+1)
        totalCount += expandAroundCenter(s, i, i + 1);
    }
    
    return totalCount;
}

int main() {
    // ===BASIC IMPLEMENTATION===
    printf("===BASIC IMPLEMENTATION===\n");
    
    char test1[] = "racecar";
    char test2[] = "hello";
    char test3[] = "A man a plan a canal Panama";
    
    printf("Testing: \"%s\" -> %s\n", test1, isPalindrome(test1) ? "Palindrome" : "Not Palindrome");
    printf("Testing: \"%s\" -> %s\n", test2, isPalindrome(test2) ? "Palindrome" : "Not Palindrome");
    printf("Testing: \"%s\" -> %s\n", test3, isPalindrome(test3) ? "Palindrome" : "Not Palindrome");
    
    // ========== LEETCODE 125: VALID PALINDROME ==========
    printf("\n=== LEETCODE 125: VALID PALINDROME ===\n");
    
    // Test case 1: "A man, a plan, a canal: Panama"
    // Expected output: true
    char s1[] = "A man, a plan, a canal: Panama";
    printf("Test Case 1:\n");
    printf("Input: \"%s\"\n", s1);
    printf("Output: %s\n\n", isPalindrome_leetcode(s1) ? "true" : "false");
    
    // Test case 2: "race a car"
    // Expected output: false
    char s2[] = "race a car";
    printf("Test Case 2:\n");
    printf("Input: \"%s\"\n", s2);
    printf("Output: %s\n\n", isPalindrome_leetcode(s2) ? "true" : "false");
    
    // Test case 3: " "
    // Expected output: true
    char s3[] = " ";
    printf("Test Case 3:\n");
    printf("Input: \"%s\"\n", s3);
    printf("Output: %s\n\n", isPalindrome_leetcode(s3) ? "true" : "false");
    
    // Test case 4: "Madam"
    // Expected output: true
    char s4[] = "Madam";
    printf("Test Case 4:\n");
    printf("Input: \"%s\"\n", s4);
    printf("Output: %s\n\n", isPalindrome_leetcode(s4) ? "true" : "false");
    
    // Test case 5: "No 'x' in Nixon"
    // Expected output: true
    char s5[] = "No 'x' in Nixon";
    printf("Test Case 5:\n");
    printf("Input: \"%s\"\n", s5);
    printf("Output: %s\n", isPalindrome_leetcode(s5) ? "true" : "false");
    
    // ========== LEETCODE 680: VALID PALINDROME II ==========
    printf("\n=== LEETCODE 680: VALID PALINDROME II ===\n");
    
    // Test case 1: "aba"
    // Expected output: true
    char t1[] = "aba";
    printf("Test Case 1:\n");
    printf("Input: \"%s\"\n", t1);
    printf("Output: %s\n\n", validPalindrome(t1) ? "true" : "false");
    
    // Test case 2: "abca"
    // Expected output: true (delete 'c')
    char t2[] = "abca";
    printf("Test Case 2:\n");
    printf("Input: \"%s\"\n", t2);
    printf("Output: %s\n\n", validPalindrome(t2) ? "true" : "false");
    
    // Test case 3: "abc"
    // Expected output: false
    char t3[] = "abc";
    printf("Test Case 3:\n");
    printf("Input: \"%s\"\n", t3);
    printf("Output: %s\n\n", validPalindrome(t3) ? "true" : "false");
    
    // Test case 4: "raceacar"
    // Expected output: true (delete middle 'a')
    char t4[] = "raceacar";
    printf("Test Case 4:\n");
    printf("Input: \"%s\"\n", t4);
    printf("Output: %s\n\n", validPalindrome(t4) ? "true" : "false");
    
    // Test case 5: "deeee"
    // Expected output: true (delete one 'e')
    char t5[] = "deeee";
    printf("Test Case 5:\n");
    printf("Input: \"%s\"\n", t5);
    printf("Output: %s\n", validPalindrome(t5) ? "true" : "false");
    
    // ========== LEETCODE 647: PALINDROMIC SUBSTRINGS ==========
    printf("\n=== LEETCODE 647: PALINDROMIC SUBSTRINGS ===\n");
    
    // Test case 1: "abc"
    // Expected output: 3 ("a", "b", "c")
    char p1[] = "abc";
    printf("Test Case 1:\n");
    printf("Input: \"%s\"\n", p1);
    printf("Output: %d\n\n", countSubstrings(p1));
    
    // Test case 2: "aaa"
    // Expected output: 6 ("a", "a", "a", "aa", "aa", "aaa")
    char p2[] = "aaa";
    printf("Test Case 2:\n");
    printf("Input: \"%s\"\n", p2);
    printf("Output: %d\n\n", countSubstrings(p2));
    
    // Test case 3: "aba"
    // Expected output: 4 ("a", "b", "a", "aba")
    char p3[] = "aba";
    printf("Test Case 3:\n");
    printf("Input: \"%s\"\n", p3);
    printf("Output: %d\n\n", countSubstrings(p3));
    
    // Test case 4: "racecar"
    // Expected output: 10
    char p4[] = "racecar";
    printf("Test Case 4:\n");
    printf("Input: \"%s\"\n", p4);
    printf("Output: %d\n\n", countSubstrings(p4));
    
    // Test case 5: "abccba"
    // Expected output: 9
    char p5[] = "abccba";
    printf("Test Case 5:\n");
    printf("Input: \"%s\"\n", p5);
    printf("Output: %d\n", countSubstrings(p5));
    
    return 0;
}