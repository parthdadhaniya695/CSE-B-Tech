// Write a C program to count the number of 1’s and 0’s in the binary representation of a number.

#include <stdio.h>

void countAndBinary(int n)
{
    int original = n;
    int count0 = 0, count1 = 0;
    int binary[32];
    int index = 0;

    while (n > 0)
    {
        int rem = n % 2;
        binary[index++] = rem;

        if (rem == 1)
            count1++;
        else
            count0++;

        n = n / 2;
    }

    printf("Binary of %d is: ", original);
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }

    printf("\nCount of 1s = %d\n", count1);
    printf("Count of 0s = %d\n", count0);
}

int main()
{
    int n;

    printf("Enter any Number: ");
    scanf("%d", &n);

    countAndBinary(n);

    return 0;
}