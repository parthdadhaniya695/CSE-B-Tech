// 4.	Output Feedback Mode - OFB

#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

// Common XOR function
void xorBlock(char *a, char *b, char *result)
{
    for(int i = 0; i < BLOCK_SIZE; i++)
        result[i] = a[i] ^ b[i];
}

// OFB Mode (Same for Encrypt & Decrypt)
void OFB(char *input, char *key, char *iv, char *output, int length)
{
    char temp[BLOCK_SIZE];

    for(int i = 0; i < length; i += BLOCK_SIZE)
    {
        xorBlock(iv, key, temp);              
        memcpy(iv, temp, BLOCK_SIZE);         
        xorBlock(input + i, iv, output + i);  
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

    memcpy(original_iv, iv, BLOCK_SIZE);

    // Encrypt
    OFB(plaintext, key, iv, ciphertext, length);
    ciphertext[length] = '\0';

    // Reset IV
    memcpy(iv, original_iv, BLOCK_SIZE);

    // Decrypt (same function)
    OFB(ciphertext, key, iv, decrypted, length);
    decrypted[length] = '\0';

    printf("\nEncrypted: %s", ciphertext);
    printf("\nDecrypted: %s", decrypted);

    return 0;
}
