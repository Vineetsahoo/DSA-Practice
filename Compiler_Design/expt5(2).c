#include <stdio.h>
#include <string.h>

void leftFactoring(char l, char r[]) {
    char p1[50], p2[50];
    int i = 0, j = 0, k = 0;

    /* extract first production */
    while (r[i] != '|' && r[i] != '\0') {
        p1[j++] = r[i++];
    }
    p1[j] = '\0';

    if (r[i] == '|') i++;

    /* extract second production */
    j = 0;
    while (r[i] != '\0') {
        p2[j++] = r[i++];
    }
    p2[j] = '\0';

    /* find common prefix */
    i = 0;
    while (p1[i] == p2[i] && p1[i] != '\0') {
        i++;
    }

    if (i > 0) {
        printf("%c->", l);
        for (k = 0; k < i; k++)
            printf("%c", p1[k]);
        printf("%c'\n", l);

        printf("%c'->", l);

        if (strlen(p1 + i) > 0)
            printf("%s", p1 + i);
        else
            printf("^");

        printf("|");

        if (strlen(p2 + i) > 0)
            printf("%s\n", p2 + i);
        else
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

    printf("Enter productions (Example: S->aCd|aT)\n");

    for (int i = 0; i < n; i++) {
        scanf(" %c->%s", &lhs, rhs);
        leftFactoring(lhs, rhs);
    }

    return 0;
}
