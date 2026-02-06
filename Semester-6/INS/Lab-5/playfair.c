#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keyTable[5][5];

// Function to generate 5x5 key matrix
void generateKeyTable(char key[]) {
    int used[26] = {0};
    int i, j, k = 0;

    for (i = 0; key[i]; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';
        if (!used[ch - 'A']) {
            keyTable[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (i + 'A' == 'J') continue;
        if (!used[i]) {
            keyTable[k / 5][k % 5] = i + 'A';
            k++;
        }
    }
}

// Find position of character in key table
void findPosition(char ch, int *row, int *col) {
    int i, j;
    if (ch == 'J') ch = 'I';
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (keyTable[i][j] == ch) {
                *row = i;
                *col = j;
            }
}

// Encrypt plaintext
void encrypt(char text[]) {
    int i, r1, c1, r2, c2;
    for (i = 0; i < strlen(text); i += 2) {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            printf("%c%c",
                   keyTable[r1][(c1 + 1) % 5],
                   keyTable[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2) {
            printf("%c%c",
                   keyTable[(r1 + 1) % 5][c1],
                   keyTable[(r2 + 1) % 5][c2]);
        }
        else {
            printf("%c%c",
                   keyTable[r1][c2],
                   keyTable[r2][c1]);
        }
    }
}

int main() {
    char key[20], text[50];

    printf("Enter Key: ");
    scanf("%s", key);

    printf("Enter Plain Text (even length): ");
    scanf("%s", text);

    generateKeyTable(key);

    printf("\nEncrypted Text: ");
    encrypt(text);

    return 0;
}