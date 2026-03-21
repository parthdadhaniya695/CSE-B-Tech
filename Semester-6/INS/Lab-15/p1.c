// Demonstration of Data Integrity Techniques
// Checksum, Simple Hashing and CRC

#include <stdio.h>
#include <string.h>

/* -------- CHECKSUM -------- */
int checksum(char data[])
{
    int sum = 0;

    for(int i = 0; data[i] != '\0'; i++)
    {
        sum = sum + data[i];
    }

    return sum % 256;   // simple checksum
}

/* -------- SIMPLE HASH -------- */
int simpleHash(char data[])
{
    int hash = 0;

    for(int i = 0; data[i] != '\0'; i++)
    {
        hash = (hash * 31 + data[i]) % 1000;
    }

    return hash;
}

/* -------- CRC -------- */
void crc(char data[], char key[])
{
    char temp[100], remainder[100];
    int dataLen = strlen(data);
    int keyLen = strlen(key);

    strcpy(temp, data);

    for(int i = 0; i < keyLen - 1; i++)
        temp[dataLen + i] = '0';

    temp[dataLen + keyLen - 1] = '\0';

    strcpy(remainder, temp);

    for(int i = 0; i <= strlen(temp) - keyLen; i++)
    {
        if(remainder[i] == '1')
        {
            for(int j = 0; j < keyLen; j++)
            {
                remainder[i+j] =
                (remainder[i+j] == key[j]) ? '0' : '1';
            }
        }
    }

    printf("CRC Remainder: ");
    for(int i = strlen(temp) - keyLen + 1; i < strlen(temp); i++)
        printf("%c", remainder[i]);
}

/* -------- MAIN -------- */
int main()
{
    char data[100];
    char key[20];

    printf("Enter data: ");
    scanf("%s", data);

    printf("Enter CRC key (binary): ");
    scanf("%s", key);

    printf("\nChecksum value: %d\n", checksum(data));
    printf("Simple Hash value: %d\n", simpleHash(data));

    crc(data, key);

    return 0;
}