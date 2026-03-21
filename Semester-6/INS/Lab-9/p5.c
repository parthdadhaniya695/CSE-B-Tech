// 5.	Counter Mode - CTR

#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

void xorBlock(char *a, char *b, char *result)
{
    for(int i = 0; i < BLOCK_SIZE; i++)
        result[i] = a[i] ^ b[i];
}

void CTR(char *input, char *key, char *nonce, char *output, int length)
{
    char counterBlock[BLOCK_SIZE];
    char temp[BLOCK_SIZE];

    for(int i = 0; i < length; i += BLOCK_SIZE)
    {
        memcpy(counterBlock, nonce, BLOCK_SIZE);
        counterBlock[BLOCK_SIZE - 1] += i / BLOCK_SIZE;

        xorBlock(counterBlock, key, temp);
        xorBlock(input + i, temp, output + i);
    }
}

int main()
{
    char plaintext[64], ciphertext[64], decrypted[64];
    char key[BLOCK_SIZE] = "12345678";
    char nonce[BLOCK_SIZE] = "00000000";

    printf("Enter plaintext (multiple of 8): ");
    scanf("%s", plaintext);

    int length = strlen(plaintext);

    CTR(plaintext, key, nonce, ciphertext, length);
    CTR(ciphertext, key, nonce, decrypted, length);

    printf("\nEncrypted: %s", ciphertext);
    printf("\nDecrypted: %s", decrypted);

    return 0;
}