// Polyalphabetic Cipher Implementation in C.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[20];
    int i, j = 0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key: ");
    scanf("%s", key);

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + (tolower(key[j]) - 'a')) % 26 + base;
            j = (j + 1) % strlen(key);
        }
    }

    printf("Encrypted text: %s", text);
    return 0;
}