// 1.	Electronic Code Book - ECB

#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

void xorBlock(char *input, char *key, char *output)
{
    for(int i = 0; i < BLOCK_SIZE; i++)
        output[i] = input[i] ^ key[i];
}

void ECB(char *input, char *key, char *output, int length)
{
    for(int i = 0; i < length; i += BLOCK_SIZE)
        xorBlock(input + i, key, output + i);
}

int main()
{
    char plaintext[64], ciphertext[64], decrypted[64];
    char key[BLOCK_SIZE] = "12345678";

    printf("Enter plaintext (multiple of 8): ");
    scanf("%s", plaintext);

    int length = strlen(plaintext);

    ECB(plaintext, key, ciphertext, length);
    ciphertext[length] = '\0';   // Fix

    ECB(ciphertext, key, decrypted, length);
    decrypted[length] = '\0';    // Fix

    printf("\nEncrypted: %s", ciphertext);
    printf("\nDecrypted: %s", decrypted);

    return 0;
}
