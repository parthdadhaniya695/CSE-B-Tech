// 1.	Implementation of AES Algorithm.

#include <stdio.h>

#define Nr 10

char state[4][4];

// Simple S-box (short version for lab)
char sbox[16] = {0x6,0x4,0xC,0x5,0x0,0x7,0x2,0xE,0x1,0xF,0x3,0xD,0x8,0xA,0x9,0xB};

void AddRoundKey(char key[4][4])
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            state[i][j] ^= key[i][j];
}

void SubBytes()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            state[i][j] = sbox[state[i][j] % 16];
}

void ShiftRows()
{
    char temp;

    temp = state[1][0];
    state[1][0]=state[1][1];
    state[1][1]=state[1][2];
    state[1][2]=state[1][3];
    state[1][3]=temp;

    char t1 = state[2][0];
    char t2 = state[2][1];
    state[2][0]=state[2][2];
    state[2][1]=state[2][3];
    state[2][2]=t1;
    state[2][3]=t2;

    temp = state[3][3];
    state[3][3]=state[3][2];
    state[3][2]=state[3][1];
    state[3][1]=state[3][0];
    state[3][0]=temp;
}

void MixColumns()
{
    for(int i=0;i<4;i++)
    {
        char t = state[0][i]^state[1][i]^state[2][i]^state[3][i];
        state[0][i]^=t;
        state[1][i]^=t;
        state[2][i]^=t;
        state[3][i]^=t;
    }
}

void printState()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            printf("%d ",state[i][j]);
        printf("\n");
    }
}

int main()
{
    char plaintext[4][4];
    char key[4][4];

    printf("Enter 16 plaintext values:\n");
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            scanf("%d",&plaintext[i][j]);

    printf("Enter 16 key values:\n");
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            scanf("%d",&key[i][j]);

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            state[i][j]=plaintext[i][j];

    AddRoundKey(key);

    for(int round=1; round<Nr; round++)
    {
        SubBytes();
        ShiftRows();
        MixColumns();
        AddRoundKey(key);
    }

    SubBytes();
    ShiftRows();
    AddRoundKey(key);

    printf("\nCiphertext:\n");
    printState();

    return 0;
}