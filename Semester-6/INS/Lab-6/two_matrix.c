#include <stdio.h>
#include <string.h>

int main() {
    int key[2][2] = {{3, 3}, {2, 5}};
    char plaintext[100];
    int i;

    printf("Enter Plaintext (uppercase): ");
    scanf("%s", plaintext);

    // If length is odd, add X
    if (strlen(plaintext) % 2 != 0) {
        strcat(plaintext, "X");
    }

    printf("Ciphertext: ");

    for (i = 0; i < strlen(plaintext); i += 2) {
        int p1 = plaintext[i] - 'A';
        int p2 = plaintext[i + 1] - 'A';

        int c1 = (key[0][0]*p1 + key[0][1]*p2) % 26;
        int c2 = (key[1][0]*p1 + key[1][1]*p2) % 26;

        printf("%c%c", c1 + 'A', c2 + 'A');
    }

    return 0;
}