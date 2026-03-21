// 2.	Cipher Block Chaining Mode - CBC

#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

// Common XOR function
void xorBlock(char *a, char *b, char *result)
{
    for(int i = 0; i < BLOCK_SIZE; i++)
        result[i] = a[i] ^ b[i];
}

// CBC Encryption
void CBC_Encrypt(char *input, char *key, char *iv, char *output, int length)
{
    char temp[BLOCK_SIZE];

    for(int i = 0; i < length; i += BLOCK_SIZE)
    {
        xorBlock(input + i, iv, temp);
        xorBlock(temp, key, output + i);
        memcpy(iv, output + i, BLOCK_SIZE);
    }
}

// CBC Decryption
void CBC_Decrypt(char *input, char *key, char *iv, char *output, int length)
{
    char temp[BLOCK_SIZE];

    for(int i = 0; i < length; i += BLOCK_SIZE)
    {
        xorBlock(input + i, key, temp);
        xorBlock(temp, iv, output + i);
        memcpy(iv, input + i, BLOCK_SIZE);
    }
}

int main()
{
    char plaintext[64], ciphertext[64], decrypted[64];
    char key[BLOCK_SIZE] = "12345678";
    char iv[BLOCK_SIZE] = "87654321";
    char original_iv[BLOCK_SIZE];

    printf("Enter plaintext (multiple of 8): ");
    scanf("%s", plaintext);

    int length = strlen(plaintext);

    // Save original IV
    memcpy(original_iv, iv, BLOCK_SIZE);

    // Encrypt
    CBC_Encrypt(plaintext, key, iv, ciphertext, length);
    ciphertext[length] = '\0';   // Null terminate

    // Reset IV before decryption
    memcpy(iv, original_iv, BLOCK_SIZE);

    // Decrypt
    CBC_Decrypt(ciphertext, key, iv, decrypted, length);
    decrypted[length] = '\0';    // Null terminate

    printf("\nEncrypted: %s", ciphertext);
    printf("\nDecrypted: %s", decrypted);

    return 0;
}
