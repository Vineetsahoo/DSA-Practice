#include <stdio.h>

long long factorial(int n) {
    long long result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

// ========== LEETCODE 172: FACTORIAL TRAILING ZEROES ==========
int trailingZeroes(int n) {
    int count =0;

    while (n>0){
        n/=5;
        count += n;
    }

    return count;
}

// ========== LEETCODE 60: PERMUTATION SEQUENCE ==========
char* getPermutation(int n, int k) {
    int fact[10];
    int numbers[10];

    fact[0] = 1;
    for (int i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * i;
        numbers[i -1] = i;
    }

    k--;

    char* result = (char*) malloc((n+1) * sizeof(char));
    int pos = 0;

    for (int i=n; i >= 1; i-- ){
        int idx = k / fact[i-1];
        k %= fact[i - 1];

        result[pos++] = numbers[idx] + '0';

        for (int j = idx; j < i -1; j++ ){
            numbers[j] = numbers[j+1];
        }
    }

    result[pos] = '\0';
    return result;
}

int main() {

    // ========== BASIC IMPLEMENTATION TEST ==========
    int number;
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else if (number > 20) {
        printf("Number too large. Factorial overflows 64-bit integer.\n");
    } else {
        printf("Factorial of %d is %lld\n", number, factorial(number));
    }

    // ========== LEETCODE 172: FACTORIAL TRAILING ZEROES TEST==========
    int n;
    printf("Enter a non-negative integer to find trailing zeroes in its factorial: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Input must be a non-negative integer.\n");
    } else {
        printf("Number of trailing zeroes in %d! is %d\n", n, trailingZeroes(n));
    }

    // ========== LEETCODE 60: PERMUTATION SEQUENCE TEST ===========
    int perm_n, perm_k;
    printf("Enter n and k to find the k-th permutation sequence of numbers from 1 to n: ");
    scanf("%d %d", &perm_n, &perm_k);
    if (perm_n <= 0 || perm_n > 9) {

        printf("n must be between 1 and 9.\n");
    } else {
        char* permutation = getPermutation(perm_n, perm_k);
        printf("The %d-th permutation sequence of numbers from 1 to %d is: %s\n", perm_k, perm_n, permutation);
        free(permutation);
    }

    return 0;
}
