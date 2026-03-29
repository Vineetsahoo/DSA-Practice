#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char prod[MAX][20];
char items[MAX][MAX][20];
int state_count = 0, prod_count;

// Check if Non-terminal
int isNonTerminal(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Add item if not already present
int addItem(int state, char item[]) {
    for (int i = 0; i < MAX; i++) {
        if (strcmp(items[state][i], item) == 0)
            return 0;
    }

    for (int i = 0; i < MAX; i++) {
        if (strlen(items[state][i]) == 0) {
            strcpy(items[state][i], item);
            return 1;
        }
    }
    return 0;
}

// Closure function
void closure(int state) {
    int added;
    do {
        added = 0;

        for (int i = 0; i < MAX; i++) {
            if (strlen(items[state][i]) == 0) continue;

            char *dot = strchr(items[state][i], '.');

            if (dot && isNonTerminal(*(dot + 1))) {
                char nt = *(dot + 1);

                for (int j = 0; j < prod_count; j++) {
                    if (prod[j][0] == nt) {
                        char temp[20];
                        sprintf(temp, "%c->.%s", nt, prod[j] + 3);

                        if (addItem(state, temp))
                            added = 1;
                    }
                }
            }
        }
    } while (added);
}

// Compare states
int isSameState(int s1, int s2) {
    for (int i = 0; i < MAX; i++) {
        if (strcmp(items[s1][i], items[s2][i]) != 0)
            return 0;
    }
    return 1;
}

// GOTO function
int GOTO(int from, char symbol) {
    int newState = state_count;

    for (int i = 0; i < MAX; i++) {
        if (strlen(items[from][i]) == 0) continue;

        char temp[20];
        strcpy(temp, items[from][i]);

        char *dot = strchr(temp, '.');

        if (dot && *(dot + 1) == symbol) {
            char t = *dot;
            *dot = *(dot + 1);
            *(dot + 1) = t;

            addItem(newState, temp);
        }
    }

    // If no items added → ignore
    if (strlen(items[newState][0]) == 0)
        return -1;

    closure(newState);

    // Check if state already exists
    for (int i = 0; i < state_count; i++) {
        if (isSameState(i, newState)) {
            // Clear duplicate state
            for (int j = 0; j < MAX; j++)
                items[newState][j][0] = '\0';
            return i;
        }
    }

    state_count++;
    return newState;
}

// Print all states
void printStates() {
    printf("\n===== Canonical Collection of LR(0) Items =====\n");

    for (int i = 0; i < state_count; i++) {
        printf("\nI%d:\n", i);
        for (int j = 0; j < MAX; j++) {
            if (strlen(items[i][j]) > 0)
                printf("   %s\n", items[i][j]);
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &prod_count);

    printf("Enter productions (E->E+T):\n");
    for (int i = 0; i < prod_count; i++) {
        scanf("%s", prod[i]);
    }

    // Initial state
    char start[20];
    sprintf(start, "%c->.%s", prod[0][0], prod[0] + 3);

    addItem(0, start);
    closure(0);
    state_count = 1;

    //  FIXED STATE GENERATION LOOP
    int processed = 0;

    while (processed < state_count) {
        for (int i = 0; i < MAX; i++) {
            if (strlen(items[processed][i]) == 0) continue;

            char *dot = strchr(items[processed][i], '.');

            if (dot && *(dot + 1) != '\0') {
                GOTO(processed, *(dot + 1));
            }
        }
        processed++;
    }

    printStates();

    return 0;
}