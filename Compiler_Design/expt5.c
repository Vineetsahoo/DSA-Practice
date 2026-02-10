#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char l, char r[]) {
    char temp[50], alpha[10][50], beta[10][50];
    int i = 0, a = 0, b = 0, consumed = 0;

    while (consumed < strlen(r)) {
        int k = 0;
        while (r[consumed] != '|' && r[consumed] != '\0') {
            temp[k++] = r[consumed++];
        }
        temp[k] = '\0';
        consumed++;  

        if (temp[0] == l) {
            strcpy(alpha[a++], temp + 1);
        } else {
            strcpy(beta[b++], temp);
        }
    }

    if (a > 0) {
        printf("%c->", l);
        for (i = 0; i < b; i++) {
            printf("%s%c' ", beta[i], l);
            if (i != b - 1) printf("| ");
        }
        printf("\n");

        printf("%c'->", l);
        for (i = 0; i < a; i++) {
            printf("%s%c' | ", alpha[i], l);
        }
        printf("^\n");
    } else {
        printf("%c->%s\n", l, r);
    }
}

int main() {
    char lhs;
    char rhs[50];
    int n;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: S->a|^|(T))\n");

    for (int i = 0; i < n; i++) {
        scanf(" %c->%s", &lhs, rhs);
        eliminateLeftRecursion(lhs, rhs);
    }

    return 0;
}
