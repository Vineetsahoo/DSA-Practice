#include <stdio.h>
#include <string.h>

char FirstNonRepeat(char str[]) {
    int freq[26] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[str[i] - 'a'] == 1)
            return str[i];
    }

    return '0';
}

int main() {
    char str[100];
    scanf("%s", str);
    printf("%c", FirstNonRepeat(str));
    return 0;
}
