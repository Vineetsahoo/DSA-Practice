#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20
#define MAX_LEN 50

char productions[MAX][MAX_LEN];
char updatedProductions[MAX][MAX_LEN];
char first[26][MAX], follow[26][MAX];
char table[26][MAX][MAX_LEN];

int count;
int newCount = 0;

int isNonTerminal(char c) {
    return (c >= 'A' && c <= 'Z');
}

void addToSet(char set[], char val) {
    if (val == '\0') return;
    for (int i = 0; set[i] != '\0'; i++)
        if (set[i] == val)
            return;

    int len = strlen(set);
    set[len] = val;
    set[len + 1] = '\0';
}

//////////////////////////////////////////////
// REMOVE IMMEDIATE LEFT RECURSION
//////////////////////////////////////////////

void removeLeftRecursion() {
    for (int i = 0; i < count; i++) {
        char lhs = productions[i][0];

        if (productions[i][3] == lhs) {  // A->Aα case
            char newNT = lhs + 1;

            // A -> βA'
            sprintf(updatedProductions[newCount++], "%c=%c%c",
                    lhs, productions[i][4], newNT);

            // A' -> αA' | #
            sprintf(updatedProductions[newCount++], "%c=%s%c|#",
                    newNT, &productions[i][4], newNT);
        } else {
            strcpy(updatedProductions[newCount++], productions[i]);
        }
    }

    count = newCount;
    for (int i = 0; i < count; i++)
        strcpy(productions[i], updatedProductions[i]);
}

//////////////////////////////////////////////
// SIMPLE LEFT FACTORING (COMMON FIRST SYMBOL)
//////////////////////////////////////////////

void leftFactoring() {
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (productions[i][0] == productions[j][0] &&
                productions[i][3] == productions[j][3]) {

                char lhs = productions[i][0];
                char newNT = lhs + 2;

                // A -> aA'
                sprintf(updatedProductions[newCount++], "%c=%c%c",
                        lhs, productions[i][3], newNT);

                // A' -> remaining parts
                sprintf(updatedProductions[newCount++], "%c=%s|%s",
                        newNT,
                        &productions[i][4],
                        &productions[j][4]);
            }
        }
    }

    if (newCount > 0) {
        count = newCount;
        for (int i = 0; i < count; i++)
            strcpy(productions[i], updatedProductions[i]);
    }
}

//////////////////////////////////////////////
// FIRST
//////////////////////////////////////////////

void computeFirst() {
    int changed;
    do {
        changed = 0;
        for (int i = 0; i < count; i++) {
            char lhs = productions[i][0];
            char *rhs = &productions[i][2];

            if (!isNonTerminal(rhs[0])) {
                addToSet(first[lhs - 'A'], rhs[0]);
            } else {
                int idx = rhs[0] - 'A';
                for (int j = 0; first[idx][j] != '\0'; j++)
                    addToSet(first[lhs - 'A'], first[idx][j]);
            }
        }
    } while (changed);
}

//////////////////////////////////////////////
// FOLLOW
//////////////////////////////////////////////

void computeFollow() {
    addToSet(follow[productions[0][0] - 'A'], '$');

    for (int i = 0; i < count; i++) {
        char lhs = productions[i][0];

        for (int j = 2; productions[i][j] != '\0'; j++) {
            if (isNonTerminal(productions[i][j])) {
                if (productions[i][j + 1] != '\0' &&
                    !isNonTerminal(productions[i][j + 1])) {
                    addToSet(follow[productions[i][j] - 'A'],
                             productions[i][j + 1]);
                } else {
                    for (int k = 0; follow[lhs - 'A'][k] != '\0'; k++)
                        addToSet(follow[productions[i][j] - 'A'],
                                 follow[lhs - 'A'][k]);
                }
            }
        }
    }
}

//////////////////////////////////////////////
// PARSING TABLE
//////////////////////////////////////////////

void constructTable() {
    for (int i = 0; i < count; i++) {
        char lhs = productions[i][0];
        char rhs = productions[i][2];

        if (!isNonTerminal(rhs))
            strcpy(table[lhs - 'A'][rhs - 'a'], productions[i]);
        else {
            int idx = rhs - 'A';
            for (int j = 0; first[idx][j] != '\0'; j++)
                strcpy(table[lhs - 'A'][first[idx][j] - 'a'], productions[i]);
        }
    }
}

void printTable() {
    printf("\nPredictive Parsing Table:\n\n");
    printf("NT\\T  a   b   c   d   $\n");

    for (int i = 0; i < 26; i++) {
        if (strlen(first[i]) > 0 || strlen(follow[i]) > 0) {
            printf("%c   ", i + 'A');
            for (int j = 0; j < 5; j++) {
                if (strlen(table[i][j]) != 0)
                    printf("%s ", table[i][j]);
                else
                    printf("-   ");
            }
            printf("\n");
        }
    }
}

//////////////////////////////////////////////
// MAIN
//////////////////////////////////////////////

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &count);

    printf("Enter productions (Example: S=aCd or S=a|b):\n");

    for (int i = 0; i < count; i++)
        scanf("%s", productions[i]);

    removeLeftRecursion();
    leftFactoring();

    computeFirst();
    computeFollow();
    constructTable();
    printTable();

    return 0;
}