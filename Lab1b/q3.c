#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

int main() {
    char paragraph[1000];
    char words[MAX_WORDS][MAX_LEN];
    int freq[MAX_WORDS] = {0};
    int count = 0;

    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " \n\t.,;!?");
    while (token != NULL) {
        for (int i = 0; token[i]; i++)
            token[i] = tolower(token[i]);

        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[count], token);
            freq[count]++;
            count++;
        }
        token = strtok(NULL, " \n\t.,;!?");
    }

    for (int i = 0; i < count; i++)
        printf("%s: %d\n", words[i], freq[i]);

    return 0;
}
