#include <stdio.h>
#include <string.h>

int main() {
    int key[3][3] = {
        {6, 24, 1},
        {13, 16, 10},
        {20, 17, 15}
    };

    char plaintext[100];
    int i;

    printf("Enter Plaintext (uppercase): ");
    scanf("%s", plaintext);

    // Padding with X if needed
    while (strlen(plaintext) % 3 != 0) {
        strcat(plaintext, "X");
    }

    printf("Ciphertext: ");

    for (i = 0; i < strlen(plaintext); i += 3) {
        int p[3], c[3], j;

        for (j = 0; j < 3; j++) {
            p[j] = plaintext[i + j] - 'A';
        }

        for (j = 0; j < 3; j++) {
            c[j] = (key[j][0]*p[0] + key[j][1]*p[1] + key[j][2]*p[2]) % 26;
            printf("%c", c[j] + 'A');
        }
    }

    return 0;
}