// Implementation of Caesar Cipher Techniques.

#include <stdio.h>

int main() {
    char text[100], encrypted[100], decrypted[100];
    int key, i;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key (number of shifts): ");
    scanf("%d", &key);

    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (ch >= 'A' && ch <= 'Z')
            encrypted[i] = (ch - 'A' + key) % 26 + 'A';
        else if (ch >= 'a' && ch <= 'z')
            encrypted[i] = (ch - 'a' + key) % 26 + 'a';
        else
            encrypted[i] = ch;  

    }
    encrypted[i] = '\0';

    printf("\nEncrypted Text: %s", encrypted);

    for (i = 0; encrypted[i] != '\0'; i++) {
        char ch = encrypted[i];

        if (ch >= 'A' && ch <= 'Z')
            decrypted[i] = (ch - 'A' - key + 26) % 26 + 'A';
        else if (ch >= 'a' && ch <= 'z')
            decrypted[i] = (ch - 'a' - key + 26) % 26 + 'a';
        else
            decrypted[i] = ch;

    }
    decrypted[i] = '\0';

    printf("Decrypted Text: %s", decrypted);

    return 0;
}