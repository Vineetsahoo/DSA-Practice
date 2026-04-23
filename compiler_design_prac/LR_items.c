# include <stdio.h>
# include <string.h>
# include <ctype.h>

# define MAX 20
char prod[MAX][20];
char items[MAX][MAX][20];
int item_count[MAX];
int n, states = 0;

int exists(int state, char *str){
    for (int i = 0; i < item_count[state]; i++){
        if (strcmp(items[state][i], str) == 0)
            return 1;
    }
    return 0;
}

void add_item(int state, char *str){
    if (!exists(state, str)){
        strcpy(items[state][item_count[state]++], str);
    }
}

void closure(int state){
    for (int i = 0; i < item_count[state]; i++){
        char *dot = strchr(items[state][i], '.');

        if (dot && isupper(*(dot + 1))) {
            char B = *(dot + 1);

            for( int j = 0; j< n; j++){
                if (prod[j][0] == B){
                    char temp[20];
                    sprintf(temp, "%c->.%s", B, prod[j] + 3);
                    add_item(state, temp);
                }
            }
        }
    }
}

void compute_goto(int state){
    char symbols[MAX];
    int count = 0;

    for (int i = 0; i< item_count[state]; i++){
        char *dot = strchr(items[state], '.');
        if (dot && *(dot + 1) != '\0'){
            char c = *(dot + 1);

            int found = 0;
            for (int k = 0; k < count; k++)
                if (symbols[k] == c) found = 1;

            if (!found)
                symbols[count++] = c;
        }
    }
}